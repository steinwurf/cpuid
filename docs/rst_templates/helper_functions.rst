{% import 'macros.rst' as macros with context %}

{# FORMAT_MEMBER_TABLE_ROW #}

{%- macro format_member_table_row(selector) -%}
{%- set function = api[selector] %}
{%- set signature = macros.format_parameters(function["parameters"]) %}
{%- set signature = signature + " const" if function["is_const"] else signature -%}
{% if "return" in function -%}
{%- set return_type = macros.format_type_list(function["return"]["type"]) -%}
{% else %}
{%- set return_type = "" -%}
{%- endif %}
{%- set return_type = "virtual " + return_type if function["is_virtual"] else return_type -%}
* - {{ return_type }}
  - :ref:`{{ function["name"] }}<{{selector}}>` {{ signature }}
{% endmacro -%}

{# FORMAT_MEMBER_TABLE #}

{%- macro format_member_table(selectors) -%}
.. list-table::
   :header-rows: 0
   :widths: auto

{% for selector in selectors %}
   {{ format_member_table_row(selector) | indent(width=3) }}
{%- endfor -%}

{% endmacro -%}

{%- set namespace = api[selector] -%}

.. _{{selector}}:

{{ macros.format_heading("namespace " + namespace["name"]) }}

{% if namespace["scope"] %}
**Scope:** {{ namespace["scope"] }}

{% endif %}

{% set functions = namespace["members"] | api_filter(
       kind="function") | api_sort(keys=["location", "line-start"])
%}

{{ format_member_table(functions) }}

{% if functions %}

Functions
---------

{% for function in functions -%}
    {{ macros.format_function(function) }}
    {% if api[function]["location"]["include"] %}
    **In header:** ``#include <{{ api[function]["location"]["include"] }}>``
    {% endif %}

{{ "-----" if not loop.last }}

{% endfor -%}
{% endif %}

