<?php
/**
* theme hook defined in hook_theme_registry_alter().
*
* includes the original theme hook for the 'webform_emails_form' and adds handling of
* confirmation request emails and confirmation emails
*/
function theme_webform_confirm_email_emails_form($variables) {
 $form = &$variables['form'];
 $node = &$form['#node'];
 $header = array(
   t('Send'),
   t('E-mail to'),
   t('Subject'),
   t('From'),
   array(
     'data'    => t('Operations'),
     'colspan' => 2
   )
 );
 $header_confirmation_request = array(
   t('Send'),
   t('E-mail to'),
   t('Subject'),
   t('From'),
   t('Redirect URL'),
   array(
     'data'    => t('Operations'),
     'colspan' => 2
   )
 );

 $output = '';
 foreach(array(
     'emails'               => t('Standard emails (always send)'),
     'confirmation_request' => t('Confirmation request emails (always send)'),
     'confirmation'         => t('Confirmation emails (only send when the confirmation URL is used)')) as $email_type => $title) {
   $rows = array();

   $eids = element_children($form[$email_type]);
   if (array_search('add_button', $eids) !== FALSE) {
     unset($eids[array_search('add_button', $eids)]);
   }
   if (array_search('add', $eids) !== FALSE) {
     unset($eids[array_search('add', $eids)]);
   }

   if (count($eids) > 0) {
     foreach ($eids as $eid) {
       // Add each component to a table row.
       $new_row = array(
         drupal_render($form[$email_type][$eid]['status']),
         drupal_render($form[$email_type][$eid]['email']),
         drupal_render($form[$email_type][$eid]['subject']),
         drupal_render($form[$email_type][$eid]['from']),
       );
       if ($email_type == 'confirmation_request') {
         $new_row[] = drupal_render($form[$email_type][$eid]['redirect_url']);
       }
       $new_row[] = l(t('Edit'),   'node/' . $node->nid . '/webform/' . $email_type . '/' . $eid);
       $new_row[] = drupal_render($form[$email_type][$eid]['delete_button']);

       $rows[] = $new_row;
     }
   }
   else {
     $cs_width = 5;
     switch($email_type) {
       case 'emails':
         $no_email_comment = t('Currently not sending standard e-mails, add a standard email by clicking the button below.');
         break;
       case 'confirmation_request':
         $no_email_comment = t('Currently not sending confirmation request e-mails, add a confirmation request email by clicking the button below.');
         $cs_width = 6;
         break;
       case 'confirmation':
         $no_email_comment = t('Currently not sending confirmation e-mails, add a confirmation email by clicking the button below.');
         break;
     }
     $rows[] = array(array('data' => $no_email_comment, 'colspan' => $cs_width));
   }

   // Add a row containing form elements for a new item.
   $row_add_email = array(
     array(
       'colspan' => ($email_type == 'confirmation_request') ? 5 : 4,
       'data'    => drupal_render($form[$email_type]['add'])
     ),
     array(
       'colspan' => 2,
       'data'    => drupal_render($form[$email_type]['add_button'])
     ),
   );
   $rows[] =array('data' => $row_add_email, 'class' => array('webform-add-form'));
   $output .= '<h2>' . $title . '</h2>';
   $output .= theme(
     'table',
     array(
       'header' => ($email_type == 'confirmation_request') ? $header_confirmation_request : $header,
       'rows'   => $rows,
       'attributes' => array('id' => 'webform-' . $email_type),
     )
   );
 }

 $output .= drupal_render_children($form);

 return $output;
}
