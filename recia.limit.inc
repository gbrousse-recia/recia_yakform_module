<?php

/**
 * @file
 * Contains the mechanism that limit access only to connected user
 */

/**
 * Returns the field bases for the custom content type.
 *
 * @return array
 *   The field base array to populate the content type with fields.
 */
function recia_custom_field_bases() {
  $field_bases = array();
  // Exported field_base: 'field_form1_limit_to_connected'.
  $field_bases['field_form1_limit_to_connected'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_form1_limit_to_connected',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'No',
        1 => 'Yes',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );
  return $field_bases;
}

/**
 * Returns fields instances for custom content type.
 *
 */
function yakforms_custom_field_instances() {
  $field_instances = array();
  // Exported field_instance: 'node-form1-field_form1_results_public'.
  $field_instances['node-field_form1_limit_to_connected'] = array(
    'bundle' => 'form1',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => "Limiter l'accès au formulaire aux utilisateurs connectés",
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_form1_limit_to_connected',
    'label' => "Limit access to results",
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );
  return $field_instances;
}
