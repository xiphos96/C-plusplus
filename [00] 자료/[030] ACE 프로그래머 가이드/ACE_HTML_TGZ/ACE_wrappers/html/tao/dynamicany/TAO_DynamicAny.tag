<?xml version='1.0' encoding='ISO-8859-1' standalone='yes'?>
<tagfile>
  <compound kind="file">
    <name>DynamicAny.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/DynamicAny/</path>
    <filename>DynamicAny_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_DynamicAny_DynamicAny</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACE_STATIC_SVC_DEFINE</name>
      <anchor>a2</anchor>
      <arglist>(TAO_DynamicAny_Loader, ACE_TEXT(&quot;DynamicAny_Loader&quot;), ACE_SVC_OBJ_T,&amp;ACE_SVC_NAME(TAO_DynamicAny_Loader), ACE_Service_Type::DELETE_THIS|ACE_Service_Type::DELETE_OBJ, 0) ACE_FACTORY_DEFINE(TAO_DynamicAny</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_DynamicAny_DynamicAny</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>DynamicAny.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/DynamicAny/</path>
    <filename>DynamicAny_8h.html</filename>
    <class kind="class">TAO_DynamicAny_Loader</class>
    <member kind="define">
      <type>#define</type>
      <name>TAO_DYNAMICANY_SAFE_INCLUDE</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACE_STATIC_SVC_DECLARE</name>
      <anchor>a2</anchor>
      <arglist>(TAO_DynamicAny_Loader) ACE_FACTORY_DECLARE(TAO_DynamicAny</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>TAO_DynamicAny_Loader int</type>
      <name>TAO_Requires_DynamicAny_Initializer</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>DynamicAny.pidl</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/DynamicAny/</path>
    <filename>DynamicAny_8pidl.html</filename>
    <namespace>DynamicAny</namespace>
  </compound>
  <compound kind="file">
    <name>dynamicany_export.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/DynamicAny/</path>
    <filename>dynamicany__export_8h.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>TAO_DYNAMICANY_HAS_DLL</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TAO_DynamicAny_Export</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TAO_DYNAMICANY_SINGLETON_DECLARATION</name>
      <anchor>a2</anchor>
      <arglist>(T)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TAO_DYNAMICANY_SINGLETON_DECLARE</name>
      <anchor>a3</anchor>
      <arglist>(SINGLETON_TYPE, CLASS, LOCK)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>DynamicAnyC.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/DynamicAny/</path>
    <filename>DynamicAnyC_8cpp.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>__TAO_UNBOUNDED_SEQUENCE_DYNAMICANY_NAMEVALUEPAIRSEQ_CS_</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_NAMEVALUEPAIRSEQ_CS_</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>__TAO_UNBOUNDED_SEQUENCE_DYNAMICANY_NAMEDYNANYPAIRSEQ_CS_</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_NAMEDYNANYPAIRSEQ_CS_</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>__TAO_UNBOUNDED_SEQUENCE_DYNAMICANY_ANYSEQ_CS_</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_ANYSEQ_CS_</name>
      <anchor>a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>__TAO_UNBOUNDED_OBJECT_SEQUENCE_DYNAMICANY_DYNANYSEQ_CS_</name>
      <anchor>a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNANYSEQ_CS_</name>
      <anchor>a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynAny_ptr</type>
      <name>tao_DynamicAny_DynAny_duplicate</name>
      <anchor>a9</anchor>
      <arglist>(DynamicAny::DynAny_ptr p)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>tao_DynamicAny_DynAny_release</name>
      <anchor>a10</anchor>
      <arglist>(DynamicAny::DynAny_ptr p)</arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynAny_ptr</type>
      <name>tao_DynamicAny_DynAny_nil</name>
      <anchor>a11</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynAny_ptr</type>
      <name>tao_DynamicAny_DynAny_narrow</name>
      <anchor>a12</anchor>
      <arglist>(CORBA::Object *p ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Object *</type>
      <name>tao_DynamicAny_DynAny_upcast</name>
      <anchor>a13</anchor>
      <arglist>(void *src)</arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynFixed_ptr</type>
      <name>tao_DynamicAny_DynFixed_duplicate</name>
      <anchor>a14</anchor>
      <arglist>(DynamicAny::DynFixed_ptr p)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>tao_DynamicAny_DynFixed_release</name>
      <anchor>a15</anchor>
      <arglist>(DynamicAny::DynFixed_ptr p)</arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynFixed_ptr</type>
      <name>tao_DynamicAny_DynFixed_nil</name>
      <anchor>a16</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynFixed_ptr</type>
      <name>tao_DynamicAny_DynFixed_narrow</name>
      <anchor>a17</anchor>
      <arglist>(CORBA::Object *p ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Object *</type>
      <name>tao_DynamicAny_DynFixed_upcast</name>
      <anchor>a18</anchor>
      <arglist>(void *src)</arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynEnum_ptr</type>
      <name>tao_DynamicAny_DynEnum_duplicate</name>
      <anchor>a19</anchor>
      <arglist>(DynamicAny::DynEnum_ptr p)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>tao_DynamicAny_DynEnum_release</name>
      <anchor>a20</anchor>
      <arglist>(DynamicAny::DynEnum_ptr p)</arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynEnum_ptr</type>
      <name>tao_DynamicAny_DynEnum_nil</name>
      <anchor>a21</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynEnum_ptr</type>
      <name>tao_DynamicAny_DynEnum_narrow</name>
      <anchor>a22</anchor>
      <arglist>(CORBA::Object *p ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Object *</type>
      <name>tao_DynamicAny_DynEnum_upcast</name>
      <anchor>a23</anchor>
      <arglist>(void *src)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::TypeCode</type>
      <name>_tc_TAO_tc_DynamicAny_FieldName</name>
      <anchor>a24</anchor>
      <arglist>(CORBA::tk_alias, sizeof(_oc_DynamicAny_FieldName),(char *)&amp;_oc_DynamicAny_FieldName, 0, sizeof(DynamicAny::FieldName))</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_NAMESPACE_TYPE</name>
      <anchor>a25</anchor>
      <arglist>(CORBA::TypeCode_ptr) TAO_NAMESPACE_BEGIN(DynamicAny) TAO_NAMESPACE_DEFINE(</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::TypeCode</type>
      <name>_tc_TAO_tc_DynamicAny_NameValuePair</name>
      <anchor>a26</anchor>
      <arglist>(CORBA::tk_struct, sizeof(_oc_DynamicAny_NameValuePair),(char *)&amp;_oc_DynamicAny_NameValuePair, 0, sizeof(DynamicAny::NameValuePair))</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::TypeCode</type>
      <name>_tc_TAO_tc_DynamicAny_NameValuePairSeq</name>
      <anchor>a27</anchor>
      <arglist>(CORBA::tk_alias, sizeof(_oc_DynamicAny_NameValuePairSeq),(char *)&amp;_oc_DynamicAny_NameValuePairSeq, 0, sizeof(DynamicAny::NameValuePairSeq))</arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynStruct_ptr</type>
      <name>tao_DynamicAny_DynStruct_duplicate</name>
      <anchor>a28</anchor>
      <arglist>(DynamicAny::DynStruct_ptr p)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>tao_DynamicAny_DynStruct_release</name>
      <anchor>a29</anchor>
      <arglist>(DynamicAny::DynStruct_ptr p)</arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynStruct_ptr</type>
      <name>tao_DynamicAny_DynStruct_nil</name>
      <anchor>a30</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynStruct_ptr</type>
      <name>tao_DynamicAny_DynStruct_narrow</name>
      <anchor>a31</anchor>
      <arglist>(CORBA::Object *p ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Object *</type>
      <name>tao_DynamicAny_DynStruct_upcast</name>
      <anchor>a32</anchor>
      <arglist>(void *src)</arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynUnion_ptr</type>
      <name>tao_DynamicAny_DynUnion_duplicate</name>
      <anchor>a33</anchor>
      <arglist>(DynamicAny::DynUnion_ptr p)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>tao_DynamicAny_DynUnion_release</name>
      <anchor>a34</anchor>
      <arglist>(DynamicAny::DynUnion_ptr p)</arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynUnion_ptr</type>
      <name>tao_DynamicAny_DynUnion_nil</name>
      <anchor>a35</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynUnion_ptr</type>
      <name>tao_DynamicAny_DynUnion_narrow</name>
      <anchor>a36</anchor>
      <arglist>(CORBA::Object *p ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Object *</type>
      <name>tao_DynamicAny_DynUnion_upcast</name>
      <anchor>a37</anchor>
      <arglist>(void *src)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::TypeCode</type>
      <name>_tc_TAO_tc_DynamicAny_AnySeq</name>
      <anchor>a38</anchor>
      <arglist>(CORBA::tk_alias, sizeof(_oc_DynamicAny_AnySeq),(char *)&amp;_oc_DynamicAny_AnySeq, 0, sizeof(DynamicAny::AnySeq))</arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynSequence_ptr</type>
      <name>tao_DynamicAny_DynSequence_duplicate</name>
      <anchor>a39</anchor>
      <arglist>(DynamicAny::DynSequence_ptr p)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>tao_DynamicAny_DynSequence_release</name>
      <anchor>a40</anchor>
      <arglist>(DynamicAny::DynSequence_ptr p)</arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynSequence_ptr</type>
      <name>tao_DynamicAny_DynSequence_nil</name>
      <anchor>a41</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynSequence_ptr</type>
      <name>tao_DynamicAny_DynSequence_narrow</name>
      <anchor>a42</anchor>
      <arglist>(CORBA::Object *p ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Object *</type>
      <name>tao_DynamicAny_DynSequence_upcast</name>
      <anchor>a43</anchor>
      <arglist>(void *src)</arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynArray_ptr</type>
      <name>tao_DynamicAny_DynArray_duplicate</name>
      <anchor>a44</anchor>
      <arglist>(DynamicAny::DynArray_ptr p)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>tao_DynamicAny_DynArray_release</name>
      <anchor>a45</anchor>
      <arglist>(DynamicAny::DynArray_ptr p)</arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynArray_ptr</type>
      <name>tao_DynamicAny_DynArray_nil</name>
      <anchor>a46</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynArray_ptr</type>
      <name>tao_DynamicAny_DynArray_narrow</name>
      <anchor>a47</anchor>
      <arglist>(CORBA::Object *p ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Object *</type>
      <name>tao_DynamicAny_DynArray_upcast</name>
      <anchor>a48</anchor>
      <arglist>(void *src)</arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynValue_ptr</type>
      <name>tao_DynamicAny_DynValue_duplicate</name>
      <anchor>a49</anchor>
      <arglist>(DynamicAny::DynValue_ptr p)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>tao_DynamicAny_DynValue_release</name>
      <anchor>a50</anchor>
      <arglist>(DynamicAny::DynValue_ptr p)</arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynValue_ptr</type>
      <name>tao_DynamicAny_DynValue_nil</name>
      <anchor>a51</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynValue_ptr</type>
      <name>tao_DynamicAny_DynValue_narrow</name>
      <anchor>a52</anchor>
      <arglist>(CORBA::Object *p ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Object *</type>
      <name>tao_DynamicAny_DynValue_upcast</name>
      <anchor>a53</anchor>
      <arglist>(void *src)</arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynAnyFactory_ptr</type>
      <name>tao_DynamicAny_DynAnyFactory_duplicate</name>
      <anchor>a54</anchor>
      <arglist>(DynamicAny::DynAnyFactory_ptr p)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>tao_DynamicAny_DynAnyFactory_release</name>
      <anchor>a55</anchor>
      <arglist>(DynamicAny::DynAnyFactory_ptr p)</arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynAnyFactory_ptr</type>
      <name>tao_DynamicAny_DynAnyFactory_nil</name>
      <anchor>a56</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynamicAny::DynAnyFactory_ptr</type>
      <name>tao_DynamicAny_DynAnyFactory_narrow</name>
      <anchor>a57</anchor>
      <arglist>(CORBA::Object *p ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Object *</type>
      <name>tao_DynamicAny_DynAnyFactory_upcast</name>
      <anchor>a58</anchor>
      <arglist>(void *src)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const CORBA::Long</type>
      <name>_oc_DynamicAny_NameValuePairSeq</name>
      <anchor>a8</anchor>
      <arglist>[]</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>DynamicAnyC.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/DynamicAny/</path>
    <filename>DynamicAnyC_8h.html</filename>
    <namespace>DynamicAny</namespace>
    <class kind="interface">DynamicAny::DynAny</class>
    <class kind="exception">DynamicAny::DynAny::InvalidValue</class>
    <class kind="exception">DynamicAny::DynAny::TypeMismatch</class>
    <class kind="interface">DynamicAny::DynAnyFactory</class>
    <class kind="exception">DynamicAny::DynAnyFactory::InconsistentTypeCode</class>
    <class kind="interface">DynamicAny::DynArray</class>
    <class kind="interface">DynamicAny::DynEnum</class>
    <class kind="interface">DynamicAny::DynFixed</class>
    <class kind="interface">DynamicAny::DynSequence</class>
    <class kind="interface">DynamicAny::DynStruct</class>
    <class kind="interface">DynamicAny::DynUnion</class>
    <class kind="interface">DynamicAny::DynValue</class>
    <class kind="struct">DynamicAny::NameDynAnyPair</class>
    <class kind="struct">DynamicAny::NameValuePair</class>
    <member kind="define">
      <type>#define</type>
      <name>TAO_EXPORT_MACRO</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNANY___PTR_CH_</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNANY___VAR_CH_</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNANY___OUT_CH_</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNANY_CH_</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNANY_INVALIDVALUE_CH_</name>
      <anchor>a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNANY_TYPEMISMATCH_CH_</name>
      <anchor>a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNFIXED___PTR_CH_</name>
      <anchor>a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNFIXED___VAR_CH_</name>
      <anchor>a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNFIXED___OUT_CH_</name>
      <anchor>a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNFIXED_CH_</name>
      <anchor>a10</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNENUM___PTR_CH_</name>
      <anchor>a11</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNENUM___VAR_CH_</name>
      <anchor>a12</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNENUM___OUT_CH_</name>
      <anchor>a13</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNENUM_CH_</name>
      <anchor>a14</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>__TAO_UNBOUNDED_SEQUENCE_DYNAMICANY_NAMEVALUEPAIRSEQ_CH_</name>
      <anchor>a15</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_NAMEVALUEPAIRSEQ_CH_</name>
      <anchor>a16</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_NAMEVALUEPAIRSEQ___VAR_CH_</name>
      <anchor>a17</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_NAMEVALUEPAIRSEQ___OUT_CH_</name>
      <anchor>a18</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>__TAO_UNBOUNDED_SEQUENCE_DYNAMICANY_NAMEDYNANYPAIRSEQ_CH_</name>
      <anchor>a19</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_NAMEDYNANYPAIRSEQ_CH_</name>
      <anchor>a20</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_NAMEDYNANYPAIRSEQ___VAR_CH_</name>
      <anchor>a21</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_NAMEDYNANYPAIRSEQ___OUT_CH_</name>
      <anchor>a22</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNSTRUCT___PTR_CH_</name>
      <anchor>a23</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNSTRUCT___VAR_CH_</name>
      <anchor>a24</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNSTRUCT___OUT_CH_</name>
      <anchor>a25</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNSTRUCT_CH_</name>
      <anchor>a26</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNUNION___PTR_CH_</name>
      <anchor>a27</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNUNION___VAR_CH_</name>
      <anchor>a28</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNUNION___OUT_CH_</name>
      <anchor>a29</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNUNION_CH_</name>
      <anchor>a30</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>__TAO_UNBOUNDED_SEQUENCE_DYNAMICANY_ANYSEQ_CH_</name>
      <anchor>a31</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_ANYSEQ_CH_</name>
      <anchor>a32</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_ANYSEQ___VAR_CH_</name>
      <anchor>a33</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_ANYSEQ___OUT_CH_</name>
      <anchor>a34</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>__TAO_UNBOUNDED_OBJECT_SEQUENCE_DYNAMICANY_DYNANYSEQ_CH_</name>
      <anchor>a35</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNANYSEQ_CH_</name>
      <anchor>a36</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNANYSEQ___VAR_CH_</name>
      <anchor>a37</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNANYSEQ___OUT_CH_</name>
      <anchor>a38</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNSEQUENCE___PTR_CH_</name>
      <anchor>a39</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNSEQUENCE___VAR_CH_</name>
      <anchor>a40</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNSEQUENCE___OUT_CH_</name>
      <anchor>a41</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNSEQUENCE_CH_</name>
      <anchor>a42</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNARRAY___PTR_CH_</name>
      <anchor>a43</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNARRAY___VAR_CH_</name>
      <anchor>a44</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNARRAY___OUT_CH_</name>
      <anchor>a45</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNARRAY_CH_</name>
      <anchor>a46</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNVALUE___PTR_CH_</name>
      <anchor>a47</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNVALUE___VAR_CH_</name>
      <anchor>a48</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNVALUE___OUT_CH_</name>
      <anchor>a49</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNVALUE_CH_</name>
      <anchor>a50</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNANYFACTORY___PTR_CH_</name>
      <anchor>a51</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNANYFACTORY___VAR_CH_</name>
      <anchor>a52</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNANYFACTORY___OUT_CH_</name>
      <anchor>a53</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNANYFACTORY_CH_</name>
      <anchor>a54</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNANYFACTORY_INCONSISTENTTYPECODE_CH_</name>
      <anchor>a55</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>TAO_NAMESPACE_CLOSE TAO_DynamicAny_Export void</type>
      <name>operator&lt;&lt;=</name>
      <anchor>a56</anchor>
      <arglist>(CORBA::Any &amp;, const DynamicAny::NameValuePair &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_DynamicAny_Export void</type>
      <name>operator&lt;&lt;=</name>
      <anchor>a57</anchor>
      <arglist>(CORBA::Any &amp;, DynamicAny::NameValuePair *)</arglist>
    </member>
    <member kind="function">
      <type>TAO_DynamicAny_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;=</name>
      <anchor>a58</anchor>
      <arglist>(const CORBA::Any &amp;, DynamicAny::NameValuePair *&amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_DynamicAny_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;=</name>
      <anchor>a59</anchor>
      <arglist>(const CORBA::Any &amp;, const DynamicAny::NameValuePair *&amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_DynamicAny_Export void</type>
      <name>operator&lt;&lt;=</name>
      <anchor>a60</anchor>
      <arglist>(CORBA::Any &amp;, const DynamicAny::NameValuePairSeq &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_DynamicAny_Export void</type>
      <name>operator&lt;&lt;=</name>
      <anchor>a61</anchor>
      <arglist>(CORBA::Any &amp;, DynamicAny::NameValuePairSeq *)</arglist>
    </member>
    <member kind="function">
      <type>TAO_DynamicAny_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;=</name>
      <anchor>a62</anchor>
      <arglist>(const CORBA::Any &amp;, DynamicAny::NameValuePairSeq *&amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_DynamicAny_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;=</name>
      <anchor>a63</anchor>
      <arglist>(const CORBA::Any &amp;, const DynamicAny::NameValuePairSeq *&amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_DynamicAny_Export void</type>
      <name>operator&lt;&lt;=</name>
      <anchor>a64</anchor>
      <arglist>(CORBA::Any &amp;, const DynamicAny::AnySeq &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_DynamicAny_Export void</type>
      <name>operator&lt;&lt;=</name>
      <anchor>a65</anchor>
      <arglist>(CORBA::Any &amp;, DynamicAny::AnySeq *)</arglist>
    </member>
    <member kind="function">
      <type>TAO_DynamicAny_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;=</name>
      <anchor>a66</anchor>
      <arglist>(const CORBA::Any &amp;, DynamicAny::AnySeq *&amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_DynamicAny_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;=</name>
      <anchor>a67</anchor>
      <arglist>(const CORBA::Any &amp;, const DynamicAny::AnySeq *&amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_DynamicAny_Export CORBA::Boolean</type>
      <name>operator&lt;&lt;</name>
      <anchor>a68</anchor>
      <arglist>(TAO_OutputCDR &amp;, const DynamicAny::NameValuePair &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_DynamicAny_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;</name>
      <anchor>a69</anchor>
      <arglist>(TAO_InputCDR &amp;, DynamicAny::NameValuePair &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_DynamicAny_Export CORBA::Boolean</type>
      <name>operator&lt;&lt;</name>
      <anchor>a70</anchor>
      <arglist>(TAO_OutputCDR &amp;, const DynamicAny::NameValuePairSeq &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_DynamicAny_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;</name>
      <anchor>a71</anchor>
      <arglist>(TAO_InputCDR &amp;, DynamicAny::NameValuePairSeq &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_DynamicAny_Export CORBA::Boolean</type>
      <name>operator&lt;&lt;</name>
      <anchor>a72</anchor>
      <arglist>(TAO_OutputCDR &amp;, const DynamicAny::AnySeq &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_DynamicAny_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;</name>
      <anchor>a73</anchor>
      <arglist>(TAO_InputCDR &amp;, DynamicAny::AnySeq &amp;)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>DynamicAnyC.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/DynamicAny/</path>
    <filename>DynamicAnyC_8i.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNANY___CI_</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNFIXED___CI_</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNENUM___CI_</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>__TAO_UNBOUNDED_SEQUENCE_DYNAMICANY_NAMEVALUEPAIRSEQ_CI_</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_NAMEVALUEPAIRSEQ_CI_</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>__TAO_UNBOUNDED_SEQUENCE_DYNAMICANY_NAMEDYNANYPAIRSEQ_CI_</name>
      <anchor>a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_NAMEDYNANYPAIRSEQ_CI_</name>
      <anchor>a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNSTRUCT___CI_</name>
      <anchor>a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNUNION___CI_</name>
      <anchor>a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>__TAO_UNBOUNDED_SEQUENCE_DYNAMICANY_ANYSEQ_CI_</name>
      <anchor>a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_ANYSEQ_CI_</name>
      <anchor>a10</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>__TAO_UNBOUNDED_OBJECT_SEQUENCE_DYNAMICANY_DYNANYSEQ_CI_</name>
      <anchor>a11</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNANYSEQ_CI_</name>
      <anchor>a12</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNSEQUENCE___CI_</name>
      <anchor>a13</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNARRAY___CI_</name>
      <anchor>a14</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNVALUE___CI_</name>
      <anchor>a15</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_DYNAMICANY_DYNANYFACTORY___CI_</name>
      <anchor>a16</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>ACE_INLINE CORBA::Boolean</type>
      <name>operator&lt;&lt;</name>
      <anchor>a17</anchor>
      <arglist>(TAO_OutputCDR &amp;strm, const DynamicAny::NameValuePair &amp;_tao_aggregate)</arglist>
    </member>
    <member kind="function">
      <type>ACE_INLINE CORBA::Boolean</type>
      <name>operator&gt;&gt;</name>
      <anchor>a18</anchor>
      <arglist>(TAO_InputCDR &amp;strm, DynamicAny::NameValuePair &amp;_tao_aggregate)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Boolean TAO_DynamicAny_Export</type>
      <name>operator&lt;&lt;</name>
      <anchor>a19</anchor>
      <arglist>(TAO_OutputCDR &amp;, const DynamicAny::NameValuePairSeq &amp;)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Boolean TAO_DynamicAny_Export</type>
      <name>operator&gt;&gt;</name>
      <anchor>a20</anchor>
      <arglist>(TAO_InputCDR &amp;, DynamicAny::NameValuePairSeq &amp;)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Boolean TAO_DynamicAny_Export</type>
      <name>operator&lt;&lt;</name>
      <anchor>a21</anchor>
      <arglist>(TAO_OutputCDR &amp;, const DynamicAny::AnySeq &amp;)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Boolean TAO_DynamicAny_Export</type>
      <name>operator&gt;&gt;</name>
      <anchor>a22</anchor>
      <arglist>(TAO_InputCDR &amp;, DynamicAny::AnySeq &amp;)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>DynAny_i.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/DynamicAny/</path>
    <filename>DynAny__i_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_DynamicAny_DynAny_i</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_DynamicAny_DynAny_i</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>DynAny_i.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/DynamicAny/</path>
    <filename>DynAny__i_8h.html</filename>
    <class kind="class">TAO_DynAny_i</class>
  </compound>
  <compound kind="file">
    <name>DynAnyFactory.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/DynamicAny/</path>
    <filename>DynAnyFactory_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_DynamicAny_DynAnyFactory</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_DynamicAny_DynAnyFactory</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>DynAnyFactory.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/DynamicAny/</path>
    <filename>DynAnyFactory_8h.html</filename>
    <class kind="class">TAO_DynAnyFactory</class>
  </compound>
  <compound kind="file">
    <name>DynArray_i.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/DynamicAny/</path>
    <filename>DynArray__i_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_DynamicAny_DynArray_i</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_DynamicAny_DynArray_i</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>DynArray_i.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/DynamicAny/</path>
    <filename>DynArray__i_8h.html</filename>
    <class kind="class">TAO_DynArray_i</class>
  </compound>
  <compound kind="file">
    <name>DynCommon.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/DynamicAny/</path>
    <filename>DynCommon_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_DynamicAny_DynCommon</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_DynamicAny_DynCommon</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>DynCommon.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/DynamicAny/</path>
    <filename>DynCommon_8h.html</filename>
    <class kind="class">TAO_DynCommon</class>
  </compound>
  <compound kind="file">
    <name>DynEnum_i.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/DynamicAny/</path>
    <filename>DynEnum__i_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_DynamicAny_DynEnum_i</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_DynamicAny_DynEnum_i</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>DynEnum_i.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/DynamicAny/</path>
    <filename>DynEnum__i_8h.html</filename>
    <class kind="class">TAO_DynEnum_i</class>
  </compound>
  <compound kind="file">
    <name>DynSequence_i.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/DynamicAny/</path>
    <filename>DynSequence__i_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_DynamicAny_DynSequence_i</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_DynamicAny_DynSequence_i</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>DynSequence_i.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/DynamicAny/</path>
    <filename>DynSequence__i_8h.html</filename>
    <class kind="class">TAO_DynSequence_i</class>
  </compound>
  <compound kind="file">
    <name>DynStruct_i.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/DynamicAny/</path>
    <filename>DynStruct__i_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_DynamicAny_DynStruct_i</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_DynamicAny_DynStruct_i</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>DynStruct_i.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/DynamicAny/</path>
    <filename>DynStruct__i_8h.html</filename>
    <class kind="class">TAO_DynStruct_i</class>
  </compound>
  <compound kind="file">
    <name>DynUnion_i.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/DynamicAny/</path>
    <filename>DynUnion__i_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_DynamicAny_DynUnion_i</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_DynamicAny_DynUnion_i</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>DynUnion_i.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/DynamicAny/</path>
    <filename>DynUnion__i_8h.html</filename>
    <class kind="class">TAO_DynUnion_i</class>
  </compound>
  <compound kind="class">
    <name>TAO_DynamicAny_Loader</name>
    <filename>classTAO__DynamicAny__Loader.html</filename>
    <base>TAO_Object_Loader</base>
    <member kind="function">
      <type></type>
      <name>TAO_DynamicAny_Loader</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Object_ptr</type>
      <name>create_object</name>
      <anchor>a1</anchor>
      <arglist>(CORBA::ORB_ptr orb, int argc, ACE_TCHAR *argv[] ACE_ENV_ARG_DECL_NOT_USED)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>int</type>
      <name>Initializer</name>
      <anchor>d0</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_DynAny_i</name>
    <filename>classTAO__DynAny__i.html</filename>
    <base virtualness="virtual">DynamicAny::DynAny</base>
    <base virtualness="virtual">TAO_DynCommon</base>
    <base virtualness="virtual">TAO_Local_RefCounted_Object</base>
    <member kind="function">
      <type></type>
      <name>TAO_DynAny_i</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_DynAny_i</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>init</name>
      <anchor>a2</anchor>
      <arglist>(CORBA_TypeCode_ptr tc ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>init</name>
      <anchor>a3</anchor>
      <arglist>(const CORBA_Any &amp;any ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>_tao_QueryInterface</name>
      <anchor>a4</anchor>
      <arglist>(ptr_arith_t type)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>from_any</name>
      <anchor>a5</anchor>
      <arglist>(const CORBA::Any &amp;value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Any *</type>
      <name>to_any</name>
      <anchor>a6</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>equal</name>
      <anchor>a7</anchor>
      <arglist>(DynamicAny::DynAny_ptr dyn_any ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>destroy</name>
      <anchor>a8</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual DynamicAny::DynAny_ptr</type>
      <name>current_component</name>
      <anchor>a9</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>TAO_DynAny_i *</type>
      <name>_narrow</name>
      <anchor>d0</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>check_typecode</name>
      <anchor>c0</anchor>
      <arglist>(CORBA::TypeCode_ptr tc ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>set_to_default_value</name>
      <anchor>c1</anchor>
      <arglist>(CORBA::TypeCode_ptr tc ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>init_common</name>
      <anchor>c2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>TAO_DynAny_i</name>
      <anchor>c3</anchor>
      <arglist>(const TAO_DynAny_i &amp;src)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>TAO_DynAny_i &amp;</type>
      <name>operator=</name>
      <anchor>c4</anchor>
      <arglist>(const TAO_DynAny_i &amp;src)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_DynAnyFactory</name>
    <filename>classTAO__DynAnyFactory.html</filename>
    <base virtualness="virtual">DynamicAny::DynAnyFactory</base>
    <base virtualness="virtual">TAO_Local_RefCounted_Object</base>
    <member kind="function">
      <type></type>
      <name>TAO_DynAnyFactory</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual DynamicAny::DynAny_ptr</type>
      <name>create_dyn_any</name>
      <anchor>a1</anchor>
      <arglist>(const CORBA::Any &amp;value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual DynamicAny::DynAny_ptr</type>
      <name>create_dyn_any_from_type_code</name>
      <anchor>a2</anchor>
      <arglist>(CORBA::TypeCode_ptr type ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::TCKind</type>
      <name>unalias</name>
      <anchor>d0</anchor>
      <arglist>(CORBA_TypeCode_ptr tc ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA_TypeCode_ptr</type>
      <name>strip_alias</name>
      <anchor>d1</anchor>
      <arglist>(CORBA_TypeCode_ptr tc ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynamicAny::DynAny_ptr</type>
      <name>make_dyn_any</name>
      <anchor>d2</anchor>
      <arglist>(const CORBA_Any &amp;any ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynamicAny::DynAny_ptr</type>
      <name>make_dyn_any</name>
      <anchor>d3</anchor>
      <arglist>(CORBA::TypeCode_ptr tc ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>TAO_DynAnyFactory</name>
      <anchor>c0</anchor>
      <arglist>(const TAO_DynAnyFactory &amp;src)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>TAO_DynAnyFactory &amp;</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const TAO_DynAnyFactory &amp;src)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_DynArray_i</name>
    <filename>classTAO__DynArray__i.html</filename>
    <base virtualness="virtual">DynamicAny::DynArray</base>
    <base virtualness="virtual">TAO_DynCommon</base>
    <base virtualness="virtual">TAO_Local_RefCounted_Object</base>
    <member kind="function">
      <type></type>
      <name>TAO_DynArray_i</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_DynArray_i</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>init</name>
      <anchor>a2</anchor>
      <arglist>(CORBA_TypeCode_ptr tc ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>init</name>
      <anchor>a3</anchor>
      <arglist>(const CORBA_Any &amp;any ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>_tao_QueryInterface</name>
      <anchor>a4</anchor>
      <arglist>(ptr_arith_t type)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual DynamicAny::AnySeq *</type>
      <name>get_elements</name>
      <anchor>a5</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_elements</name>
      <anchor>a6</anchor>
      <arglist>(const DynamicAny::AnySeq &amp;value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual DynamicAny::DynAnySeq *</type>
      <name>get_elements_as_dyn_any</name>
      <anchor>a7</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_elements_as_dyn_any</name>
      <anchor>a8</anchor>
      <arglist>(const DynamicAny::DynAnySeq &amp;value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>from_any</name>
      <anchor>a9</anchor>
      <arglist>(const CORBA::Any &amp;value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Any *</type>
      <name>to_any</name>
      <anchor>a10</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>equal</name>
      <anchor>a11</anchor>
      <arglist>(DynamicAny::DynAny_ptr dyn_any ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>destroy</name>
      <anchor>a12</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual DynamicAny::DynAny_ptr</type>
      <name>current_component</name>
      <anchor>a13</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>TAO_DynArray_i *</type>
      <name>_narrow</name>
      <anchor>d0</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>CORBA::TypeCode_ptr</type>
      <name>get_element_type</name>
      <anchor>c0</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>CORBA::ULong</type>
      <name>get_tc_length</name>
      <anchor>c1</anchor>
      <arglist>(CORBA::TypeCode_ptr tc ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>init_common</name>
      <anchor>c2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>TAO_DynArray_i</name>
      <anchor>c3</anchor>
      <arglist>(const TAO_DynArray_i &amp;src)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>TAO_DynArray_i &amp;</type>
      <name>operator=</name>
      <anchor>c4</anchor>
      <arglist>(const TAO_DynArray_i &amp;src)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_Array_Base&lt; DynamicAny::DynAny_var &gt;</type>
      <name>da_members_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_DynCommon</name>
    <filename>classTAO__DynCommon.html</filename>
    <base virtualness="virtual">DynamicAny::DynAny</base>
    <member kind="function">
      <type></type>
      <name>TAO_DynCommon</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_DynCommon</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::TypeCode_ptr</type>
      <name>type</name>
      <anchor>a2</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>assign</name>
      <anchor>a3</anchor>
      <arglist>(DynamicAny::DynAny_ptr dyn_any ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>insert_boolean</name>
      <anchor>a4</anchor>
      <arglist>(CORBA::Boolean value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>insert_octet</name>
      <anchor>a5</anchor>
      <arglist>(CORBA::Octet value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>insert_char</name>
      <anchor>a6</anchor>
      <arglist>(CORBA::Char value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>insert_short</name>
      <anchor>a7</anchor>
      <arglist>(CORBA::Short value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>insert_ushort</name>
      <anchor>a8</anchor>
      <arglist>(CORBA::UShort value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>insert_long</name>
      <anchor>a9</anchor>
      <arglist>(CORBA::Long value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>insert_ulong</name>
      <anchor>a10</anchor>
      <arglist>(CORBA::ULong value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>insert_float</name>
      <anchor>a11</anchor>
      <arglist>(CORBA::Float value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>insert_double</name>
      <anchor>a12</anchor>
      <arglist>(CORBA::Double value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>insert_string</name>
      <anchor>a13</anchor>
      <arglist>(const char *value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>insert_reference</name>
      <anchor>a14</anchor>
      <arglist>(CORBA::Object_ptr value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>insert_typecode</name>
      <anchor>a15</anchor>
      <arglist>(CORBA::TypeCode_ptr value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>insert_longlong</name>
      <anchor>a16</anchor>
      <arglist>(CORBA::LongLong value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>insert_ulonglong</name>
      <anchor>a17</anchor>
      <arglist>(CORBA::ULongLong value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>insert_longdouble</name>
      <anchor>a18</anchor>
      <arglist>(CORBA::LongDouble value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>insert_wchar</name>
      <anchor>a19</anchor>
      <arglist>(CORBA::WChar value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>insert_wstring</name>
      <anchor>a20</anchor>
      <arglist>(const CORBA::WChar *value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>insert_any</name>
      <anchor>a21</anchor>
      <arglist>(const CORBA::Any &amp;value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>insert_dyn_any</name>
      <anchor>a22</anchor>
      <arglist>(DynamicAny::DynAny_ptr value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>insert_val</name>
      <anchor>a23</anchor>
      <arglist>(CORBA::ValueBase_ptr value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>get_boolean</name>
      <anchor>a24</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Octet</type>
      <name>get_octet</name>
      <anchor>a25</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Char</type>
      <name>get_char</name>
      <anchor>a26</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Short</type>
      <name>get_short</name>
      <anchor>a27</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::UShort</type>
      <name>get_ushort</name>
      <anchor>a28</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Long</type>
      <name>get_long</name>
      <anchor>a29</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::ULong</type>
      <name>get_ulong</name>
      <anchor>a30</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Float</type>
      <name>get_float</name>
      <anchor>a31</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Double</type>
      <name>get_double</name>
      <anchor>a32</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual char *</type>
      <name>get_string</name>
      <anchor>a33</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Object_ptr</type>
      <name>get_reference</name>
      <anchor>a34</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::TypeCode_ptr</type>
      <name>get_typecode</name>
      <anchor>a35</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::LongLong</type>
      <name>get_longlong</name>
      <anchor>a36</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::ULongLong</type>
      <name>get_ulonglong</name>
      <anchor>a37</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::LongDouble</type>
      <name>get_longdouble</name>
      <anchor>a38</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::WChar</type>
      <name>get_wchar</name>
      <anchor>a39</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::WChar *</type>
      <name>get_wstring</name>
      <anchor>a40</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Any *</type>
      <name>get_any</name>
      <anchor>a41</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual DynamicAny::DynAny_ptr</type>
      <name>get_dyn_any</name>
      <anchor>a42</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::ValueBase_ptr</type>
      <name>get_val</name>
      <anchor>a43</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>seek</name>
      <anchor>a44</anchor>
      <arglist>(CORBA::Long index ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>rewind</name>
      <anchor>a45</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>next</name>
      <anchor>a46</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual DynamicAny::DynAny_ptr</type>
      <name>copy</name>
      <anchor>a47</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::ULong</type>
      <name>component_count</name>
      <anchor>a48</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>void</type>
      <name>set_flag</name>
      <anchor>b0</anchor>
      <arglist>(DynamicAny::DynAny_ptr component, CORBA::Boolean destroying ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::Boolean</type>
      <name>ref_to_component_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::Boolean</type>
      <name>container_is_destroying_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::Boolean</type>
      <name>has_components_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::Boolean</type>
      <name>destroyed_</name>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::Long</type>
      <name>current_position_</name>
      <anchor>n4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::ULong</type>
      <name>component_count_</name>
      <anchor>n5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::TypeCode_var</type>
      <name>type_</name>
      <anchor>n6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA_Any</type>
      <name>any_</name>
      <anchor>n7</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="protected">
      <type>DynamicAny::DynAny_ptr</type>
      <name>check_component</name>
      <anchor>c0</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>check_type</name>
      <anchor>c1</anchor>
      <arglist>(CORBA::TypeCode_ptr tc ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>CORBA::TypeCode_ptr</type>
      <name>check_type_and_unalias</name>
      <anchor>c2</anchor>
      <arglist>(CORBA::TypeCode_ptr tc ACE_ENV_ARG_DECL)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_DynEnum_i</name>
    <filename>classTAO__DynEnum__i.html</filename>
    <base virtualness="virtual">DynamicAny::DynEnum</base>
    <base virtualness="virtual">TAO_DynCommon</base>
    <base virtualness="virtual">TAO_Local_RefCounted_Object</base>
    <member kind="function">
      <type></type>
      <name>TAO_DynEnum_i</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_DynEnum_i</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>init</name>
      <anchor>a2</anchor>
      <arglist>(CORBA_TypeCode_ptr tc ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>init</name>
      <anchor>a3</anchor>
      <arglist>(const CORBA_Any &amp;any ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>_tao_QueryInterface</name>
      <anchor>a4</anchor>
      <arglist>(ptr_arith_t type)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual char *</type>
      <name>get_as_string</name>
      <anchor>a5</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_as_string</name>
      <anchor>a6</anchor>
      <arglist>(const char *value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::ULong</type>
      <name>get_as_ulong</name>
      <anchor>a7</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_as_ulong</name>
      <anchor>a8</anchor>
      <arglist>(CORBA::ULong value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>from_any</name>
      <anchor>a9</anchor>
      <arglist>(const CORBA::Any &amp;value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Any *</type>
      <name>to_any</name>
      <anchor>a10</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>equal</name>
      <anchor>a11</anchor>
      <arglist>(DynamicAny::DynAny_ptr dyn_any ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>destroy</name>
      <anchor>a12</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual DynamicAny::DynAny_ptr</type>
      <name>current_component</name>
      <anchor>a13</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>TAO_DynEnum_i *</type>
      <name>_narrow</name>
      <anchor>d0</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>init_common</name>
      <anchor>c0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>TAO_DynEnum_i</name>
      <anchor>c1</anchor>
      <arglist>(const TAO_DynEnum_i &amp;src)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>TAO_DynEnum_i &amp;</type>
      <name>operator=</name>
      <anchor>c2</anchor>
      <arglist>(const TAO_DynEnum_i &amp;src)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>CORBA::ULong</type>
      <name>value_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_DynSequence_i</name>
    <filename>classTAO__DynSequence__i.html</filename>
    <base virtualness="virtual">DynamicAny::DynSequence</base>
    <base virtualness="virtual">TAO_DynCommon</base>
    <base virtualness="virtual">TAO_Local_RefCounted_Object</base>
    <member kind="function">
      <type></type>
      <name>TAO_DynSequence_i</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_DynSequence_i</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>init</name>
      <anchor>a2</anchor>
      <arglist>(CORBA_TypeCode_ptr tc ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>init</name>
      <anchor>a3</anchor>
      <arglist>(const CORBA_Any &amp;any ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>_tao_QueryInterface</name>
      <anchor>a4</anchor>
      <arglist>(ptr_arith_t type)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::ULong</type>
      <name>get_length</name>
      <anchor>a5</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_length</name>
      <anchor>a6</anchor>
      <arglist>(CORBA::ULong len ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual DynamicAny::AnySeq *</type>
      <name>get_elements</name>
      <anchor>a7</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_elements</name>
      <anchor>a8</anchor>
      <arglist>(const DynamicAny::AnySeq &amp;value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual DynamicAny::DynAnySeq *</type>
      <name>get_elements_as_dyn_any</name>
      <anchor>a9</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_elements_as_dyn_any</name>
      <anchor>a10</anchor>
      <arglist>(const DynamicAny::DynAnySeq &amp;value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>from_any</name>
      <anchor>a11</anchor>
      <arglist>(const CORBA::Any &amp;value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Any *</type>
      <name>to_any</name>
      <anchor>a12</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>equal</name>
      <anchor>a13</anchor>
      <arglist>(DynamicAny::DynAny_ptr dyn_any ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>destroy</name>
      <anchor>a14</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual DynamicAny::DynAny_ptr</type>
      <name>current_component</name>
      <anchor>a15</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>TAO_DynSequence_i *</type>
      <name>_narrow</name>
      <anchor>d0</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>CORBA::TypeCode_ptr</type>
      <name>get_element_type</name>
      <anchor>c0</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>init_common</name>
      <anchor>c1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>TAO_DynSequence_i</name>
      <anchor>c2</anchor>
      <arglist>(const TAO_DynSequence_i &amp;src)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>TAO_DynSequence_i &amp;</type>
      <name>operator=</name>
      <anchor>c3</anchor>
      <arglist>(const TAO_DynSequence_i &amp;src)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_Array_Base&lt; DynamicAny::DynAny_var &gt;</type>
      <name>da_members_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_DynStruct_i</name>
    <filename>classTAO__DynStruct__i.html</filename>
    <base virtualness="virtual">DynamicAny::DynStruct</base>
    <base virtualness="virtual">TAO_DynCommon</base>
    <base virtualness="virtual">TAO_Local_RefCounted_Object</base>
    <member kind="function">
      <type></type>
      <name>TAO_DynStruct_i</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_DynStruct_i</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>init</name>
      <anchor>a2</anchor>
      <arglist>(CORBA_TypeCode_ptr tc ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>init</name>
      <anchor>a3</anchor>
      <arglist>(const CORBA_Any &amp;any ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>_tao_QueryInterface</name>
      <anchor>a4</anchor>
      <arglist>(ptr_arith_t type)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual DynamicAny::FieldName</type>
      <name>current_member_name</name>
      <anchor>a5</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::TCKind</type>
      <name>current_member_kind</name>
      <anchor>a6</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual DynamicAny::NameValuePairSeq *</type>
      <name>get_members</name>
      <anchor>a7</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_members</name>
      <anchor>a8</anchor>
      <arglist>(const DynamicAny::NameValuePairSeq &amp;value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual DynamicAny::NameDynAnyPairSeq *</type>
      <name>get_members_as_dyn_any</name>
      <anchor>a9</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_members_as_dyn_any</name>
      <anchor>a10</anchor>
      <arglist>(const DynamicAny::NameDynAnyPairSeq &amp;value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>from_any</name>
      <anchor>a11</anchor>
      <arglist>(const CORBA::Any &amp;value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Any *</type>
      <name>to_any</name>
      <anchor>a12</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>equal</name>
      <anchor>a13</anchor>
      <arglist>(DynamicAny::DynAny_ptr dyn_any ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>destroy</name>
      <anchor>a14</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual DynamicAny::DynAny_ptr</type>
      <name>current_component</name>
      <anchor>a15</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>TAO_DynStruct_i *</type>
      <name>_narrow</name>
      <anchor>d0</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>check_typecode</name>
      <anchor>c0</anchor>
      <arglist>(CORBA::TypeCode_ptr tc ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>init_common</name>
      <anchor>c1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>TAO_DynStruct_i</name>
      <anchor>c2</anchor>
      <arglist>(const TAO_DynStruct_i &amp;src)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>TAO_DynStruct_i &amp;</type>
      <name>operator=</name>
      <anchor>c3</anchor>
      <arglist>(const TAO_DynStruct_i &amp;src)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_Array_Base&lt; DynamicAny::DynAny_var &gt;</type>
      <name>da_members_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_DynUnion_i</name>
    <filename>classTAO__DynUnion__i.html</filename>
    <base virtualness="virtual">DynamicAny::DynUnion</base>
    <base virtualness="virtual">TAO_DynCommon</base>
    <base virtualness="virtual">TAO_Local_RefCounted_Object</base>
    <member kind="function">
      <type></type>
      <name>TAO_DynUnion_i</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_DynUnion_i</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>init</name>
      <anchor>a2</anchor>
      <arglist>(const CORBA_Any &amp;any ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>init</name>
      <anchor>a3</anchor>
      <arglist>(CORBA_TypeCode_ptr tc ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>_tao_QueryInterface</name>
      <anchor>a4</anchor>
      <arglist>(ptr_arith_t type)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual DynamicAny::DynAny_ptr</type>
      <name>get_discriminator</name>
      <anchor>a5</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_discriminator</name>
      <anchor>a6</anchor>
      <arglist>(DynamicAny::DynAny_ptr d ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_to_default_member</name>
      <anchor>a7</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_to_no_active_member</name>
      <anchor>a8</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>has_no_active_member</name>
      <anchor>a9</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::TCKind</type>
      <name>discriminator_kind</name>
      <anchor>a10</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual DynamicAny::DynAny_ptr</type>
      <name>member</name>
      <anchor>a11</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual char *</type>
      <name>member_name</name>
      <anchor>a12</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::TCKind</type>
      <name>member_kind</name>
      <anchor>a13</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>from_any</name>
      <anchor>a14</anchor>
      <arglist>(const CORBA::Any &amp;value ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Any *</type>
      <name>to_any</name>
      <anchor>a15</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>equal</name>
      <anchor>a16</anchor>
      <arglist>(DynamicAny::DynAny_ptr dyn_any ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>destroy</name>
      <anchor>a17</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual DynamicAny::DynAny_ptr</type>
      <name>current_component</name>
      <anchor>a18</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>TAO_DynUnion_i *</type>
      <name>_narrow</name>
      <anchor>d0</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>set_from_any</name>
      <anchor>c0</anchor>
      <arglist>(const CORBA_Any &amp;any, CORBA::Boolean from_factory ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>init_common</name>
      <anchor>c1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>CORBA::Boolean</type>
      <name>label_match</name>
      <anchor>c2</anchor>
      <arglist>(const CORBA_Any &amp;my_any, const CORBA_Any &amp;other_any ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>TAO_DynUnion_i</name>
      <anchor>c3</anchor>
      <arglist>(const TAO_DynUnion_i &amp;src)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>TAO_DynUnion_i &amp;</type>
      <name>operator=</name>
      <anchor>c4</anchor>
      <arglist>(const TAO_DynUnion_i &amp;src)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>DynamicAny::DynAny_var</type>
      <name>member_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>DynamicAny::DynAny_var</type>
      <name>discriminator_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>CORBA::ULong</type>
      <name>member_slot_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>DynamicAny</name>
    <filename>namespaceDynamicAny.html</filename>
    <class kind="class">DynamicAny::_TAO_Unbounded_Object_Sequence_DynamicAny_DynAnySeq</class>
    <class kind="class">DynamicAny::_TAO_Unbounded_Sequence_DynamicAny_AnySeq</class>
    <class kind="class">DynamicAny::_TAO_Unbounded_Sequence_DynamicAny_NameDynAnyPairSeq</class>
    <class kind="class">DynamicAny::_TAO_Unbounded_Sequence_DynamicAny_NameValuePairSeq</class>
    <class kind="class">DynamicAny::AnySeq</class>
    <class kind="class">DynamicAny::AnySeq_out</class>
    <class kind="class">DynamicAny::AnySeq_var</class>
    <class kind="interface">DynamicAny::DynAny</class>
    <class kind="exception">DynamicAny::DynAny::InvalidValue</class>
    <class kind="exception">DynamicAny::DynAny::TypeMismatch</class>
    <class kind="class">DynamicAny::DynAny_out</class>
    <class kind="class">DynamicAny::DynAny_var</class>
    <class kind="interface">DynamicAny::DynAnyFactory</class>
    <class kind="class">DynamicAny::DynAnyFactory_out</class>
    <class kind="class">DynamicAny::DynAnyFactory_var</class>
    <class kind="class">DynamicAny::DynAnySeq</class>
    <class kind="class">DynamicAny::DynAnySeq_out</class>
    <class kind="class">DynamicAny::DynAnySeq_var</class>
    <class kind="interface">DynamicAny::DynArray</class>
    <class kind="class">DynamicAny::DynArray_out</class>
    <class kind="class">DynamicAny::DynArray_var</class>
    <class kind="interface">DynamicAny::DynEnum</class>
    <class kind="class">DynamicAny::DynEnum_out</class>
    <class kind="class">DynamicAny::DynEnum_var</class>
    <class kind="interface">DynamicAny::DynFixed</class>
    <class kind="class">DynamicAny::DynFixed_out</class>
    <class kind="class">DynamicAny::DynFixed_var</class>
    <class kind="interface">DynamicAny::DynSequence</class>
    <class kind="class">DynamicAny::DynSequence_out</class>
    <class kind="class">DynamicAny::DynSequence_var</class>
    <class kind="interface">DynamicAny::DynStruct</class>
    <class kind="class">DynamicAny::DynStruct_out</class>
    <class kind="class">DynamicAny::DynStruct_var</class>
    <class kind="interface">DynamicAny::DynUnion</class>
    <class kind="class">DynamicAny::DynUnion_out</class>
    <class kind="class">DynamicAny::DynUnion_var</class>
    <class kind="interface">DynamicAny::DynValue</class>
    <class kind="exception">DynamicAny::DynAnyFactory::InconsistentTypeCode</class>
    <class kind="class">DynamicAny::DynValue_out</class>
    <class kind="class">DynamicAny::DynValue_var</class>
    <class kind="struct">DynamicAny::NameDynAnyPair</class>
    <class kind="class">DynamicAny::NameDynAnyPair_out</class>
    <class kind="class">DynamicAny::NameDynAnyPair_var</class>
    <class kind="class">DynamicAny::NameDynAnyPairSeq</class>
    <class kind="class">DynamicAny::NameDynAnyPairSeq_out</class>
    <class kind="class">DynamicAny::NameDynAnyPairSeq_var</class>
    <class kind="struct">DynamicAny::NameValuePair</class>
    <class kind="class">DynamicAny::NameValuePair_out</class>
    <class kind="class">DynamicAny::NameValuePair_var</class>
    <class kind="class">DynamicAny::NameValuePairSeq</class>
    <class kind="class">DynamicAny::NameValuePairSeq_out</class>
    <class kind="class">DynamicAny::NameValuePairSeq_var</class>
    <member kind="typedef">
      <type>string</type>
      <name>FieldName</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>sequence&lt; NameValuePair &gt;</type>
      <name>NameValuePairSeq</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>sequence&lt; NameDynAnyPair &gt;</type>
      <name>NameDynAnyPairSeq</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>sequence&lt; any &gt;</type>
      <name>AnySeq</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>sequence&lt; DynAny &gt;</type>
      <name>DynAnySeq</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>DynAny *</type>
      <name>DynAny_ptr</name>
      <anchor>a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>DynFixed *</type>
      <name>DynFixed_ptr</name>
      <anchor>a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>DynEnum *</type>
      <name>DynEnum_ptr</name>
      <anchor>a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>CORBA::String_var</type>
      <name>FieldName_var</name>
      <anchor>a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>CORBA::String_out</type>
      <name>FieldName_out</name>
      <anchor>a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>DynStruct *</type>
      <name>DynStruct_ptr</name>
      <anchor>a13</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>DynUnion *</type>
      <name>DynUnion_ptr</name>
      <anchor>a14</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>DynSequence *</type>
      <name>DynSequence_ptr</name>
      <anchor>a16</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>DynArray *</type>
      <name>DynArray_ptr</name>
      <anchor>a17</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>DynValue *</type>
      <name>DynValue_ptr</name>
      <anchor>a18</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>DynAnyFactory *</type>
      <name>DynAnyFactory_ptr</name>
      <anchor>a19</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>TAO_NAMESPACE_STORAGE_CLASS::CORBA::TypeCode_ptr</type>
      <name>_tc_FieldName</name>
      <anchor>a10</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>TAO_NAMESPACE_STORAGE_CLASS::CORBA::TypeCode_ptr</type>
      <name>_tc_NameValuePair</name>
      <anchor>a11</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>TAO_NAMESPACE_STORAGE_CLASS::CORBA::TypeCode_ptr</type>
      <name>_tc_NameValuePairSeq</name>
      <anchor>a12</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>TAO_NAMESPACE_STORAGE_CLASS::CORBA::TypeCode_ptr</type>
      <name>_tc_AnySeq</name>
      <anchor>a15</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::_TAO_Unbounded_Object_Sequence_DynamicAny_DynAnySeq</name>
    <filename>classDynamicAny_1_1__TAO__Unbounded__Object__Sequence__DynamicAny__DynAnySeq.html</filename>
    <base>TAO_Unbounded_Base_Sequence</base>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Object_Sequence_DynamicAny_DynAnySeq</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Object_Sequence_DynamicAny_DynAnySeq</name>
      <anchor>a1</anchor>
      <arglist>(CORBA::ULong maximum)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Object_Sequence_DynamicAny_DynAnySeq</name>
      <anchor>a2</anchor>
      <arglist>(CORBA::ULong maximum, CORBA::ULong length, DynAny **value, CORBA::Boolean release=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Object_Sequence_DynamicAny_DynAnySeq</name>
      <anchor>a3</anchor>
      <arglist>(const _TAO_Unbounded_Object_Sequence_DynamicAny_DynAnySeq &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>_TAO_Unbounded_Object_Sequence_DynamicAny_DynAnySeq &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(const _TAO_Unbounded_Object_Sequence_DynamicAny_DynAnySeq &amp;rhs)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~_TAO_Unbounded_Object_Sequence_DynamicAny_DynAnySeq</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_Object_Manager&lt; DynamicAny::DynAny, DynamicAny::DynAny_var &gt;</type>
      <name>operator[]</name>
      <anchor>a6</anchor>
      <arglist>(CORBA::ULong index) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_allocate_buffer</name>
      <anchor>a7</anchor>
      <arglist>(CORBA::ULong length)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_deallocate_buffer</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynAny **</type>
      <name>get_buffer</name>
      <anchor>a9</anchor>
      <arglist>(CORBA::Boolean orphan=0)</arglist>
    </member>
    <member kind="function">
      <type>const DynAny **</type>
      <name>get_buffer</name>
      <anchor>a10</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_shrink_buffer</name>
      <anchor>a11</anchor>
      <arglist>(CORBA::ULong nl, CORBA::ULong ol)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_downcast</name>
      <anchor>a12</anchor>
      <arglist>(void *target, CORBA_Object *src ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA_Object *</type>
      <name>_upcast</name>
      <anchor>a13</anchor>
      <arglist>(void *src) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynAny **</type>
      <name>allocbuf</name>
      <anchor>d0</anchor>
      <arglist>(CORBA::ULong nelems)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>freebuf</name>
      <anchor>d1</anchor>
      <arglist>(DynAny **buffer)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::_TAO_Unbounded_Sequence_DynamicAny_AnySeq</name>
    <filename>classDynamicAny_1_1__TAO__Unbounded__Sequence__DynamicAny__AnySeq.html</filename>
    <base>TAO_Unbounded_Base_Sequence</base>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Sequence_DynamicAny_AnySeq</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Sequence_DynamicAny_AnySeq</name>
      <anchor>a1</anchor>
      <arglist>(CORBA::ULong maximum)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Sequence_DynamicAny_AnySeq</name>
      <anchor>a2</anchor>
      <arglist>(CORBA::ULong maximum, CORBA::ULong length, CORBA::Any *data, CORBA::Boolean release=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Sequence_DynamicAny_AnySeq</name>
      <anchor>a3</anchor>
      <arglist>(const _TAO_Unbounded_Sequence_DynamicAny_AnySeq &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>_TAO_Unbounded_Sequence_DynamicAny_AnySeq &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(const _TAO_Unbounded_Sequence_DynamicAny_AnySeq &amp;rhs)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~_TAO_Unbounded_Sequence_DynamicAny_AnySeq</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Any &amp;</type>
      <name>operator[]</name>
      <anchor>a6</anchor>
      <arglist>(CORBA::ULong i)</arglist>
    </member>
    <member kind="function">
      <type>const CORBA::Any &amp;</type>
      <name>operator[]</name>
      <anchor>a7</anchor>
      <arglist>(CORBA::ULong i) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_allocate_buffer</name>
      <anchor>a8</anchor>
      <arglist>(CORBA::ULong length)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_deallocate_buffer</name>
      <anchor>a9</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Any *</type>
      <name>get_buffer</name>
      <anchor>a10</anchor>
      <arglist>(CORBA::Boolean orphan=0)</arglist>
    </member>
    <member kind="function">
      <type>const CORBA::Any *</type>
      <name>get_buffer</name>
      <anchor>a11</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>replace</name>
      <anchor>a12</anchor>
      <arglist>(CORBA::ULong max, CORBA::ULong length, CORBA::Any *data, CORBA::Boolean release)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::Any *</type>
      <name>allocbuf</name>
      <anchor>d0</anchor>
      <arglist>(CORBA::ULong size)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>freebuf</name>
      <anchor>d1</anchor>
      <arglist>(CORBA::Any *buffer)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::_TAO_Unbounded_Sequence_DynamicAny_NameDynAnyPairSeq</name>
    <filename>classDynamicAny_1_1__TAO__Unbounded__Sequence__DynamicAny__NameDynAnyPairSeq.html</filename>
    <base>TAO_Unbounded_Base_Sequence</base>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Sequence_DynamicAny_NameDynAnyPairSeq</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Sequence_DynamicAny_NameDynAnyPairSeq</name>
      <anchor>a1</anchor>
      <arglist>(CORBA::ULong maximum)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Sequence_DynamicAny_NameDynAnyPairSeq</name>
      <anchor>a2</anchor>
      <arglist>(CORBA::ULong maximum, CORBA::ULong length, NameDynAnyPair *data, CORBA::Boolean release=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Sequence_DynamicAny_NameDynAnyPairSeq</name>
      <anchor>a3</anchor>
      <arglist>(const _TAO_Unbounded_Sequence_DynamicAny_NameDynAnyPairSeq &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>_TAO_Unbounded_Sequence_DynamicAny_NameDynAnyPairSeq &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(const _TAO_Unbounded_Sequence_DynamicAny_NameDynAnyPairSeq &amp;rhs)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~_TAO_Unbounded_Sequence_DynamicAny_NameDynAnyPairSeq</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPair &amp;</type>
      <name>operator[]</name>
      <anchor>a6</anchor>
      <arglist>(CORBA::ULong i)</arglist>
    </member>
    <member kind="function">
      <type>const NameDynAnyPair &amp;</type>
      <name>operator[]</name>
      <anchor>a7</anchor>
      <arglist>(CORBA::ULong i) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_allocate_buffer</name>
      <anchor>a8</anchor>
      <arglist>(CORBA::ULong length)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_deallocate_buffer</name>
      <anchor>a9</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPair *</type>
      <name>get_buffer</name>
      <anchor>a10</anchor>
      <arglist>(CORBA::Boolean orphan=0)</arglist>
    </member>
    <member kind="function">
      <type>const NameDynAnyPair *</type>
      <name>get_buffer</name>
      <anchor>a11</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>replace</name>
      <anchor>a12</anchor>
      <arglist>(CORBA::ULong max, CORBA::ULong length, NameDynAnyPair *data, CORBA::Boolean release)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>NameDynAnyPair *</type>
      <name>allocbuf</name>
      <anchor>d0</anchor>
      <arglist>(CORBA::ULong size)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>freebuf</name>
      <anchor>d1</anchor>
      <arglist>(NameDynAnyPair *buffer)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::_TAO_Unbounded_Sequence_DynamicAny_NameValuePairSeq</name>
    <filename>classDynamicAny_1_1__TAO__Unbounded__Sequence__DynamicAny__NameValuePairSeq.html</filename>
    <base>TAO_Unbounded_Base_Sequence</base>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Sequence_DynamicAny_NameValuePairSeq</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Sequence_DynamicAny_NameValuePairSeq</name>
      <anchor>a1</anchor>
      <arglist>(CORBA::ULong maximum)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Sequence_DynamicAny_NameValuePairSeq</name>
      <anchor>a2</anchor>
      <arglist>(CORBA::ULong maximum, CORBA::ULong length, NameValuePair *data, CORBA::Boolean release=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Sequence_DynamicAny_NameValuePairSeq</name>
      <anchor>a3</anchor>
      <arglist>(const _TAO_Unbounded_Sequence_DynamicAny_NameValuePairSeq &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>_TAO_Unbounded_Sequence_DynamicAny_NameValuePairSeq &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(const _TAO_Unbounded_Sequence_DynamicAny_NameValuePairSeq &amp;rhs)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~_TAO_Unbounded_Sequence_DynamicAny_NameValuePairSeq</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NameValuePair &amp;</type>
      <name>operator[]</name>
      <anchor>a6</anchor>
      <arglist>(CORBA::ULong i)</arglist>
    </member>
    <member kind="function">
      <type>const NameValuePair &amp;</type>
      <name>operator[]</name>
      <anchor>a7</anchor>
      <arglist>(CORBA::ULong i) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_allocate_buffer</name>
      <anchor>a8</anchor>
      <arglist>(CORBA::ULong length)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_deallocate_buffer</name>
      <anchor>a9</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NameValuePair *</type>
      <name>get_buffer</name>
      <anchor>a10</anchor>
      <arglist>(CORBA::Boolean orphan=0)</arglist>
    </member>
    <member kind="function">
      <type>const NameValuePair *</type>
      <name>get_buffer</name>
      <anchor>a11</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>replace</name>
      <anchor>a12</anchor>
      <arglist>(CORBA::ULong max, CORBA::ULong length, NameValuePair *data, CORBA::Boolean release)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>NameValuePair *</type>
      <name>allocbuf</name>
      <anchor>d0</anchor>
      <arglist>(CORBA::ULong size)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>freebuf</name>
      <anchor>d1</anchor>
      <arglist>(NameValuePair *buffer)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::AnySeq</name>
    <filename>classDynamicAny_1_1AnySeq.html</filename>
    <base>DynamicAny::_TAO_Unbounded_Sequence_DynamicAny_AnySeq</base>
    <member kind="typedef">
      <type>AnySeq_var</type>
      <name>_var_type</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>AnySeq</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>AnySeq</name>
      <anchor>a1</anchor>
      <arglist>(CORBA::ULong max)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>AnySeq</name>
      <anchor>a2</anchor>
      <arglist>(CORBA::ULong max, CORBA::ULong length, CORBA::Any *buffer, CORBA::Boolean release=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>AnySeq</name>
      <anchor>a3</anchor>
      <arglist>(const AnySeq &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~AnySeq</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>_tao_any_destructor</name>
      <anchor>d0</anchor>
      <arglist>(void *)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::AnySeq_out</name>
    <filename>classDynamicAny_1_1AnySeq__out.html</filename>
    <member kind="function">
      <type></type>
      <name>AnySeq_out</name>
      <anchor>a0</anchor>
      <arglist>(AnySeq *&amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>AnySeq_out</name>
      <anchor>a1</anchor>
      <arglist>(AnySeq_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>AnySeq_out</name>
      <anchor>a2</anchor>
      <arglist>(const AnySeq_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>AnySeq_out &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const AnySeq_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>AnySeq_out &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(AnySeq *)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator AnySeq *&amp;</name>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>AnySeq *&amp;</type>
      <name>ptr</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>AnySeq *</type>
      <name>operator-&gt;</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Any &amp;</type>
      <name>operator[]</name>
      <anchor>a8</anchor>
      <arglist>(CORBA::ULong index)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>operator=</name>
      <anchor>c0</anchor>
      <arglist>(const AnySeq_var &amp;)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>AnySeq *&amp;</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::AnySeq_var</name>
    <filename>classDynamicAny_1_1AnySeq__var.html</filename>
    <member kind="function">
      <type></type>
      <name>AnySeq_var</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>AnySeq_var</name>
      <anchor>a1</anchor>
      <arglist>(AnySeq *)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>AnySeq_var</name>
      <anchor>a2</anchor>
      <arglist>(const AnySeq_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~AnySeq_var</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>AnySeq_var &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(AnySeq *)</arglist>
    </member>
    <member kind="function">
      <type>AnySeq_var &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(const AnySeq_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>AnySeq *</type>
      <name>operator-&gt;</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const AnySeq *</type>
      <name>operator-&gt;</name>
      <anchor>a7</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator const AnySeq &amp;</name>
      <anchor>a8</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator AnySeq &amp;</name>
      <anchor>a9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator AnySeq &amp;</name>
      <anchor>a10</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator AnySeq *&amp;</name>
      <anchor>a11</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Any &amp;</type>
      <name>operator[]</name>
      <anchor>a12</anchor>
      <arglist>(CORBA::ULong index)</arglist>
    </member>
    <member kind="function">
      <type>const CORBA::Any &amp;</type>
      <name>operator[]</name>
      <anchor>a13</anchor>
      <arglist>(CORBA::ULong index) const</arglist>
    </member>
    <member kind="function">
      <type>const AnySeq &amp;</type>
      <name>in</name>
      <anchor>a14</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>AnySeq &amp;</type>
      <name>inout</name>
      <anchor>a15</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>AnySeq *&amp;</type>
      <name>out</name>
      <anchor>a16</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>AnySeq *</type>
      <name>_retn</name>
      <anchor>a17</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>AnySeq *</type>
      <name>ptr</name>
      <anchor>a18</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>AnySeq *</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>DynamicAny::DynAny</name>
    <filename>interfaceDynamicAny_1_1DynAny.html</filename>
    <base virtualness="virtual">CORBA_Object</base>
    <member kind="typedef">
      <type>DynAny_ptr</type>
      <name>_ptr_type</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>DynAny_var</type>
      <name>_var_type</name>
      <anchor>s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>CORBA::TypeCode</type>
      <name>type</name>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>assign</name>
      <anchor>a1</anchor>
      <arglist>(in DynAny dyn_any)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>from_any</name>
      <anchor>a2</anchor>
      <arglist>(in any value)</arglist>
    </member>
    <member kind="function">
      <type>any</type>
      <name>to_any</name>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>equal</name>
      <anchor>a4</anchor>
      <arglist>(in DynAny dyn_any)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>destroy</name>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>DynAny</type>
      <name>copy</name>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert_boolean</name>
      <anchor>a7</anchor>
      <arglist>(in boolean value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert_octet</name>
      <anchor>a8</anchor>
      <arglist>(in octet value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert_char</name>
      <anchor>a9</anchor>
      <arglist>(in char value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert_short</name>
      <anchor>a10</anchor>
      <arglist>(in short value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert_ushort</name>
      <anchor>a11</anchor>
      <arglist>(in unsigned short value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert_long</name>
      <anchor>a12</anchor>
      <arglist>(in long value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert_ulong</name>
      <anchor>a13</anchor>
      <arglist>(in unsigned long value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert_float</name>
      <anchor>a14</anchor>
      <arglist>(in float value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert_double</name>
      <anchor>a15</anchor>
      <arglist>(in double value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert_string</name>
      <anchor>a16</anchor>
      <arglist>(in string value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert_reference</name>
      <anchor>a17</anchor>
      <arglist>(in Object value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert_typecode</name>
      <anchor>a18</anchor>
      <arglist>(in CORBA::TypeCode value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert_longlong</name>
      <anchor>a19</anchor>
      <arglist>(in long long value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert_ulonglong</name>
      <anchor>a20</anchor>
      <arglist>(in unsigned long long value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert_longdouble</name>
      <anchor>a21</anchor>
      <arglist>(in long double value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert_wchar</name>
      <anchor>a22</anchor>
      <arglist>(in wchar value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert_wstring</name>
      <anchor>a23</anchor>
      <arglist>(in wstring value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert_any</name>
      <anchor>a24</anchor>
      <arglist>(in any value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert_dyn_any</name>
      <anchor>a25</anchor>
      <arglist>(in DynAny value)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>insert_val</name>
      <anchor>a26</anchor>
      <arglist>(in ValueBase value)</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>get_boolean</name>
      <anchor>a27</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>octet</type>
      <name>get_octet</name>
      <anchor>a28</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>char</type>
      <name>get_char</name>
      <anchor>a29</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>short</type>
      <name>get_short</name>
      <anchor>a30</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>unsigned short</type>
      <name>get_ushort</name>
      <anchor>a31</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>long</type>
      <name>get_long</name>
      <anchor>a32</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>unsigned long</type>
      <name>get_ulong</name>
      <anchor>a33</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>float</type>
      <name>get_float</name>
      <anchor>a34</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>double</type>
      <name>get_double</name>
      <anchor>a35</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>string</type>
      <name>get_string</name>
      <anchor>a36</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Object</type>
      <name>get_reference</name>
      <anchor>a37</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>CORBA::TypeCode</type>
      <name>get_typecode</name>
      <anchor>a38</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>long long</type>
      <name>get_longlong</name>
      <anchor>a39</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>unsigned long long</type>
      <name>get_ulonglong</name>
      <anchor>a40</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>long double</type>
      <name>get_longdouble</name>
      <anchor>a41</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>wchar</type>
      <name>get_wchar</name>
      <anchor>a42</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>wstring</type>
      <name>get_wstring</name>
      <anchor>a43</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>any</type>
      <name>get_any</name>
      <anchor>a44</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>DynAny</type>
      <name>get_dyn_any</name>
      <anchor>a45</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>ValueBase</type>
      <name>get_val</name>
      <anchor>a46</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>seek</name>
      <anchor>a47</anchor>
      <arglist>(in long index)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>rewind</name>
      <anchor>a48</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>next</name>
      <anchor>a49</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>unsigned long</type>
      <name>component_count</name>
      <anchor>a50</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>DynAny</type>
      <name>current_component</name>
      <anchor>a51</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::TypeCode_ptr</type>
      <name>type</name>
      <anchor>a52</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>assign</name>
      <anchor>a53</anchor>
      <arglist>(DynamicAny::DynAny_ptr dyn_any ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>from_any</name>
      <anchor>a54</anchor>
      <arglist>(const CORBA::Any &amp;value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Any *</type>
      <name>to_any</name>
      <anchor>a55</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Boolean</type>
      <name>equal</name>
      <anchor>a56</anchor>
      <arglist>(DynamicAny::DynAny_ptr dyn_any ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>destroy</name>
      <anchor>a57</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual::DynamicAny::DynAny_ptr</type>
      <name>copy</name>
      <anchor>a58</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>insert_boolean</name>
      <anchor>a59</anchor>
      <arglist>(CORBA::Boolean value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>insert_octet</name>
      <anchor>a60</anchor>
      <arglist>(CORBA::Octet value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>insert_char</name>
      <anchor>a61</anchor>
      <arglist>(CORBA::Char value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>insert_short</name>
      <anchor>a62</anchor>
      <arglist>(CORBA::Short value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>insert_ushort</name>
      <anchor>a63</anchor>
      <arglist>(CORBA::UShort value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>insert_long</name>
      <anchor>a64</anchor>
      <arglist>(CORBA::Long value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>insert_ulong</name>
      <anchor>a65</anchor>
      <arglist>(CORBA::ULong value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>insert_float</name>
      <anchor>a66</anchor>
      <arglist>(CORBA::Float value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>insert_double</name>
      <anchor>a67</anchor>
      <arglist>(CORBA::Double value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>insert_string</name>
      <anchor>a68</anchor>
      <arglist>(const char *value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>insert_reference</name>
      <anchor>a69</anchor>
      <arglist>(CORBA::Object_ptr value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>insert_typecode</name>
      <anchor>a70</anchor>
      <arglist>(CORBA::TypeCode_ptr value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>insert_longlong</name>
      <anchor>a71</anchor>
      <arglist>(CORBA::LongLong value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>insert_ulonglong</name>
      <anchor>a72</anchor>
      <arglist>(CORBA::ULongLong value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>insert_longdouble</name>
      <anchor>a73</anchor>
      <arglist>(CORBA::LongDouble value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>insert_wchar</name>
      <anchor>a74</anchor>
      <arglist>(CORBA::WChar value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>insert_wstring</name>
      <anchor>a75</anchor>
      <arglist>(const CORBA::WChar *value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>insert_any</name>
      <anchor>a76</anchor>
      <arglist>(const CORBA::Any &amp;value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>insert_dyn_any</name>
      <anchor>a77</anchor>
      <arglist>(DynamicAny::DynAny_ptr value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>insert_val</name>
      <anchor>a78</anchor>
      <arglist>(CORBA::ValueBase_ptr value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Boolean</type>
      <name>get_boolean</name>
      <anchor>a79</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Octet</type>
      <name>get_octet</name>
      <anchor>a80</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Char</type>
      <name>get_char</name>
      <anchor>a81</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Short</type>
      <name>get_short</name>
      <anchor>a82</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::UShort</type>
      <name>get_ushort</name>
      <anchor>a83</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Long</type>
      <name>get_long</name>
      <anchor>a84</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::ULong</type>
      <name>get_ulong</name>
      <anchor>a85</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Float</type>
      <name>get_float</name>
      <anchor>a86</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Double</type>
      <name>get_double</name>
      <anchor>a87</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual char *</type>
      <name>get_string</name>
      <anchor>a88</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Object_ptr</type>
      <name>get_reference</name>
      <anchor>a89</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::TypeCode_ptr</type>
      <name>get_typecode</name>
      <anchor>a90</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::LongLong</type>
      <name>get_longlong</name>
      <anchor>a91</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::ULongLong</type>
      <name>get_ulonglong</name>
      <anchor>a92</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::LongDouble</type>
      <name>get_longdouble</name>
      <anchor>a93</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::WChar</type>
      <name>get_wchar</name>
      <anchor>a94</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::WChar *</type>
      <name>get_wstring</name>
      <anchor>a95</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Any *</type>
      <name>get_any</name>
      <anchor>a96</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual::DynamicAny::DynAny_ptr</type>
      <name>get_dyn_any</name>
      <anchor>a97</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::ValueBase_ptr</type>
      <name>get_val</name>
      <anchor>a98</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Boolean</type>
      <name>seek</name>
      <anchor>a99</anchor>
      <arglist>(CORBA::Long index ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>rewind</name>
      <anchor>a100</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Boolean</type>
      <name>next</name>
      <anchor>a101</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::ULong</type>
      <name>component_count</name>
      <anchor>a102</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual::DynamicAny::DynAny_ptr</type>
      <name>current_component</name>
      <anchor>a103</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>_tao_QueryInterface</name>
      <anchor>a104</anchor>
      <arglist>(ptr_arith_t type)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>_interface_repository_id</name>
      <anchor>a105</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynAny_ptr</type>
      <name>_duplicate</name>
      <anchor>d0</anchor>
      <arglist>(DynAny_ptr obj)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynAny_ptr</type>
      <name>_narrow</name>
      <anchor>d1</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynAny_ptr</type>
      <name>_unchecked_narrow</name>
      <anchor>d2</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynAny_ptr</type>
      <name>_nil</name>
      <anchor>d3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>int</type>
      <name>_tao_class_id</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="public">
      <type></type>
      <name>DynAny</name>
      <anchor>b0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual</type>
      <name>~DynAny</name>
      <anchor>b1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>DynAny</name>
      <anchor>c0</anchor>
      <arglist>(const DynAny &amp;)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const DynAny &amp;)</arglist>
    </member>
  </compound>
  <compound kind="exception">
    <name>DynamicAny::DynAny::InvalidValue</name>
    <filename>exceptionDynamicAny_1_1DynAny_1_1InvalidValue.html</filename>
    <member kind="function">
      <type></type>
      <name>InvalidValue</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>InvalidValue</name>
      <anchor>a1</anchor>
      <arglist>(const InvalidValue &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~InvalidValue</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>InvalidValue &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const InvalidValue &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Exception *</type>
      <name>_tao_duplicate</name>
      <anchor>a4</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_raise</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_tao_encode</name>
      <anchor>a6</anchor>
      <arglist>(TAO_OutputCDR &amp;ACE_ENV_ARG_DECL_NOT_USED) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_tao_decode</name>
      <anchor>a7</anchor>
      <arglist>(TAO_InputCDR &amp;ACE_ENV_ARG_DECL_NOT_USED)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>InvalidValue *</type>
      <name>_downcast</name>
      <anchor>d0</anchor>
      <arglist>(CORBA::Exception *)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::Exception *</type>
      <name>_alloc</name>
      <anchor>d1</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="exception">
    <name>DynamicAny::DynAny::TypeMismatch</name>
    <filename>exceptionDynamicAny_1_1DynAny_1_1TypeMismatch.html</filename>
    <member kind="function">
      <type></type>
      <name>TypeMismatch</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TypeMismatch</name>
      <anchor>a1</anchor>
      <arglist>(const TypeMismatch &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TypeMismatch</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TypeMismatch &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const TypeMismatch &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Exception *</type>
      <name>_tao_duplicate</name>
      <anchor>a4</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_raise</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_tao_encode</name>
      <anchor>a6</anchor>
      <arglist>(TAO_OutputCDR &amp;ACE_ENV_ARG_DECL_NOT_USED) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_tao_decode</name>
      <anchor>a7</anchor>
      <arglist>(TAO_InputCDR &amp;ACE_ENV_ARG_DECL_NOT_USED)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>TypeMismatch *</type>
      <name>_downcast</name>
      <anchor>d0</anchor>
      <arglist>(CORBA::Exception *)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::Exception *</type>
      <name>_alloc</name>
      <anchor>d1</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="exception">
    <name>DynamicAny::DynAny::InvalidValue</name>
    <filename>exceptionDynamicAny_1_1DynAny_1_1InvalidValue.html</filename>
    <member kind="function">
      <type></type>
      <name>InvalidValue</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>InvalidValue</name>
      <anchor>a1</anchor>
      <arglist>(const InvalidValue &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~InvalidValue</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>InvalidValue &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const InvalidValue &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Exception *</type>
      <name>_tao_duplicate</name>
      <anchor>a4</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_raise</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_tao_encode</name>
      <anchor>a6</anchor>
      <arglist>(TAO_OutputCDR &amp;ACE_ENV_ARG_DECL_NOT_USED) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_tao_decode</name>
      <anchor>a7</anchor>
      <arglist>(TAO_InputCDR &amp;ACE_ENV_ARG_DECL_NOT_USED)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>InvalidValue *</type>
      <name>_downcast</name>
      <anchor>d0</anchor>
      <arglist>(CORBA::Exception *)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::Exception *</type>
      <name>_alloc</name>
      <anchor>d1</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="exception">
    <name>DynamicAny::DynAny::TypeMismatch</name>
    <filename>exceptionDynamicAny_1_1DynAny_1_1TypeMismatch.html</filename>
    <member kind="function">
      <type></type>
      <name>TypeMismatch</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TypeMismatch</name>
      <anchor>a1</anchor>
      <arglist>(const TypeMismatch &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TypeMismatch</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TypeMismatch &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const TypeMismatch &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Exception *</type>
      <name>_tao_duplicate</name>
      <anchor>a4</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_raise</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_tao_encode</name>
      <anchor>a6</anchor>
      <arglist>(TAO_OutputCDR &amp;ACE_ENV_ARG_DECL_NOT_USED) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_tao_decode</name>
      <anchor>a7</anchor>
      <arglist>(TAO_InputCDR &amp;ACE_ENV_ARG_DECL_NOT_USED)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>TypeMismatch *</type>
      <name>_downcast</name>
      <anchor>d0</anchor>
      <arglist>(CORBA::Exception *)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::Exception *</type>
      <name>_alloc</name>
      <anchor>d1</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::DynAny_out</name>
    <filename>classDynamicAny_1_1DynAny__out.html</filename>
    <member kind="function">
      <type></type>
      <name>DynAny_out</name>
      <anchor>a0</anchor>
      <arglist>(DynAny_ptr &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynAny_out</name>
      <anchor>a1</anchor>
      <arglist>(DynAny_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynAny_out</name>
      <anchor>a2</anchor>
      <arglist>(const DynAny_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynAny_out &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const DynAny_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynAny_out &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(const DynAny_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynAny_out &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(DynAny_ptr)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator DynAny_ptr &amp;</name>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>DynAny_ptr &amp;</type>
      <name>ptr</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynAny_ptr</type>
      <name>operator-&gt;</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>DynAny_ptr &amp;</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::DynAny_var</name>
    <filename>classDynamicAny_1_1DynAny__var.html</filename>
    <base>TAO_Base_var</base>
    <member kind="function">
      <type></type>
      <name>DynAny_var</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynAny_var</name>
      <anchor>a1</anchor>
      <arglist>(DynAny_ptr p)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynAny_var</name>
      <anchor>a2</anchor>
      <arglist>(const DynAny_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~DynAny_var</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynAny_var &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(DynAny_ptr)</arglist>
    </member>
    <member kind="function">
      <type>DynAny_var &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(const DynAny_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynAny_ptr</type>
      <name>operator-&gt;</name>
      <anchor>a6</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator const DynAny_ptr &amp;</name>
      <anchor>a7</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator DynAny_ptr &amp;</name>
      <anchor>a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>DynAny_ptr</type>
      <name>in</name>
      <anchor>a9</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>DynAny_ptr &amp;</type>
      <name>inout</name>
      <anchor>a10</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynAny_ptr &amp;</type>
      <name>out</name>
      <anchor>a11</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynAny_ptr</type>
      <name>_retn</name>
      <anchor>a12</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynAny_ptr</type>
      <name>ptr</name>
      <anchor>a13</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynAny_ptr</type>
      <name>tao_duplicate</name>
      <anchor>d0</anchor>
      <arglist>(DynAny_ptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>tao_release</name>
      <anchor>d1</anchor>
      <arglist>(DynAny_ptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynAny_ptr</type>
      <name>tao_nil</name>
      <anchor>d2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynAny_ptr</type>
      <name>tao_narrow</name>
      <anchor>d3</anchor>
      <arglist>(CORBA::Object *ACE_ENV_ARG_DECL_NOT_USED)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::Object *</type>
      <name>tao_upcast</name>
      <anchor>d4</anchor>
      <arglist>(void *)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>DynAny_var</name>
      <anchor>c0</anchor>
      <arglist>(const TAO_Base_var &amp;rhs)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>DynAny_var &amp;</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const TAO_Base_var &amp;rhs)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>DynAny_ptr</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>DynamicAny::DynAnyFactory</name>
    <filename>interfaceDynamicAny_1_1DynAnyFactory.html</filename>
    <base virtualness="virtual">CORBA_Object</base>
    <member kind="typedef">
      <type>DynAnyFactory_ptr</type>
      <name>_ptr_type</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>DynAnyFactory_var</type>
      <name>_var_type</name>
      <anchor>s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>DynAny</type>
      <name>create_dyn_any</name>
      <anchor>a0</anchor>
      <arglist>(in any value)</arglist>
    </member>
    <member kind="function">
      <type>DynAny</type>
      <name>create_dyn_any_from_type_code</name>
      <anchor>a1</anchor>
      <arglist>(in CORBA::TypeCode type)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual::DynamicAny::DynAny_ptr</type>
      <name>create_dyn_any</name>
      <anchor>a2</anchor>
      <arglist>(const CORBA::Any &amp;value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual::DynamicAny::DynAny_ptr</type>
      <name>create_dyn_any_from_type_code</name>
      <anchor>a3</anchor>
      <arglist>(CORBA::TypeCode_ptr type ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>_tao_QueryInterface</name>
      <anchor>a4</anchor>
      <arglist>(ptr_arith_t type)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>_interface_repository_id</name>
      <anchor>a5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynAnyFactory_ptr</type>
      <name>_duplicate</name>
      <anchor>d0</anchor>
      <arglist>(DynAnyFactory_ptr obj)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynAnyFactory_ptr</type>
      <name>_narrow</name>
      <anchor>d1</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynAnyFactory_ptr</type>
      <name>_unchecked_narrow</name>
      <anchor>d2</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynAnyFactory_ptr</type>
      <name>_nil</name>
      <anchor>d3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>int</type>
      <name>_tao_class_id</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="public">
      <type></type>
      <name>DynAnyFactory</name>
      <anchor>b0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual</type>
      <name>~DynAnyFactory</name>
      <anchor>b1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>DynAnyFactory</name>
      <anchor>c0</anchor>
      <arglist>(const DynAnyFactory &amp;)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const DynAnyFactory &amp;)</arglist>
    </member>
  </compound>
  <compound kind="exception">
    <name>DynamicAny::DynAnyFactory::InconsistentTypeCode</name>
    <filename>exceptionDynamicAny_1_1DynAnyFactory_1_1InconsistentTypeCode.html</filename>
    <member kind="function">
      <type></type>
      <name>InconsistentTypeCode</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>InconsistentTypeCode</name>
      <anchor>a1</anchor>
      <arglist>(const InconsistentTypeCode &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~InconsistentTypeCode</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>InconsistentTypeCode &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const InconsistentTypeCode &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Exception *</type>
      <name>_tao_duplicate</name>
      <anchor>a4</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_raise</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_tao_encode</name>
      <anchor>a6</anchor>
      <arglist>(TAO_OutputCDR &amp;ACE_ENV_ARG_DECL_NOT_USED) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_tao_decode</name>
      <anchor>a7</anchor>
      <arglist>(TAO_InputCDR &amp;ACE_ENV_ARG_DECL_NOT_USED)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>InconsistentTypeCode *</type>
      <name>_downcast</name>
      <anchor>d0</anchor>
      <arglist>(CORBA::Exception *)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::Exception *</type>
      <name>_alloc</name>
      <anchor>d1</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::DynAnyFactory_out</name>
    <filename>classDynamicAny_1_1DynAnyFactory__out.html</filename>
    <member kind="function">
      <type></type>
      <name>DynAnyFactory_out</name>
      <anchor>a0</anchor>
      <arglist>(DynAnyFactory_ptr &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynAnyFactory_out</name>
      <anchor>a1</anchor>
      <arglist>(DynAnyFactory_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynAnyFactory_out</name>
      <anchor>a2</anchor>
      <arglist>(const DynAnyFactory_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynAnyFactory_out &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const DynAnyFactory_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynAnyFactory_out &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(const DynAnyFactory_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynAnyFactory_out &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(DynAnyFactory_ptr)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator DynAnyFactory_ptr &amp;</name>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>DynAnyFactory_ptr &amp;</type>
      <name>ptr</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynAnyFactory_ptr</type>
      <name>operator-&gt;</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>DynAnyFactory_ptr &amp;</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::DynAnyFactory_var</name>
    <filename>classDynamicAny_1_1DynAnyFactory__var.html</filename>
    <base>TAO_Base_var</base>
    <member kind="function">
      <type></type>
      <name>DynAnyFactory_var</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynAnyFactory_var</name>
      <anchor>a1</anchor>
      <arglist>(DynAnyFactory_ptr p)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynAnyFactory_var</name>
      <anchor>a2</anchor>
      <arglist>(const DynAnyFactory_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~DynAnyFactory_var</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynAnyFactory_var &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(DynAnyFactory_ptr)</arglist>
    </member>
    <member kind="function">
      <type>DynAnyFactory_var &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(const DynAnyFactory_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynAnyFactory_ptr</type>
      <name>operator-&gt;</name>
      <anchor>a6</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator const DynAnyFactory_ptr &amp;</name>
      <anchor>a7</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator DynAnyFactory_ptr &amp;</name>
      <anchor>a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>DynAnyFactory_ptr</type>
      <name>in</name>
      <anchor>a9</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>DynAnyFactory_ptr &amp;</type>
      <name>inout</name>
      <anchor>a10</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynAnyFactory_ptr &amp;</type>
      <name>out</name>
      <anchor>a11</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynAnyFactory_ptr</type>
      <name>_retn</name>
      <anchor>a12</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynAnyFactory_ptr</type>
      <name>ptr</name>
      <anchor>a13</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynAnyFactory_ptr</type>
      <name>tao_duplicate</name>
      <anchor>d0</anchor>
      <arglist>(DynAnyFactory_ptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>tao_release</name>
      <anchor>d1</anchor>
      <arglist>(DynAnyFactory_ptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynAnyFactory_ptr</type>
      <name>tao_nil</name>
      <anchor>d2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynAnyFactory_ptr</type>
      <name>tao_narrow</name>
      <anchor>d3</anchor>
      <arglist>(CORBA::Object *ACE_ENV_ARG_DECL_NOT_USED)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::Object *</type>
      <name>tao_upcast</name>
      <anchor>d4</anchor>
      <arglist>(void *)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>DynAnyFactory_var</name>
      <anchor>c0</anchor>
      <arglist>(const TAO_Base_var &amp;rhs)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>DynAnyFactory_var &amp;</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const TAO_Base_var &amp;rhs)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>DynAnyFactory_ptr</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::DynAnySeq</name>
    <filename>classDynamicAny_1_1DynAnySeq.html</filename>
    <base>DynamicAny::_TAO_Unbounded_Object_Sequence_DynamicAny_DynAnySeq</base>
    <member kind="typedef">
      <type>DynAnySeq_var</type>
      <name>_var_type</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynAnySeq</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynAnySeq</name>
      <anchor>a1</anchor>
      <arglist>(CORBA::ULong max)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynAnySeq</name>
      <anchor>a2</anchor>
      <arglist>(CORBA::ULong max, CORBA::ULong length, DynAny_ptr *buffer, CORBA::Boolean release=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynAnySeq</name>
      <anchor>a3</anchor>
      <arglist>(const DynAnySeq &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~DynAnySeq</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>_tao_any_destructor</name>
      <anchor>d0</anchor>
      <arglist>(void *)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::DynAnySeq_out</name>
    <filename>classDynamicAny_1_1DynAnySeq__out.html</filename>
    <member kind="function">
      <type></type>
      <name>DynAnySeq_out</name>
      <anchor>a0</anchor>
      <arglist>(DynAnySeq *&amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynAnySeq_out</name>
      <anchor>a1</anchor>
      <arglist>(DynAnySeq_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynAnySeq_out</name>
      <anchor>a2</anchor>
      <arglist>(const DynAnySeq_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynAnySeq_out &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const DynAnySeq_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynAnySeq_out &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(DynAnySeq *)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator DynAnySeq *&amp;</name>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>DynAnySeq *&amp;</type>
      <name>ptr</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynAnySeq *</type>
      <name>operator-&gt;</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_Object_Manager&lt; DynAny, DynAny_var &gt;</type>
      <name>operator[]</name>
      <anchor>a8</anchor>
      <arglist>(CORBA::ULong index)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>operator=</name>
      <anchor>c0</anchor>
      <arglist>(const DynAnySeq_var &amp;)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>DynAnySeq *&amp;</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::DynAnySeq_var</name>
    <filename>classDynamicAny_1_1DynAnySeq__var.html</filename>
    <member kind="function">
      <type></type>
      <name>DynAnySeq_var</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynAnySeq_var</name>
      <anchor>a1</anchor>
      <arglist>(DynAnySeq *)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynAnySeq_var</name>
      <anchor>a2</anchor>
      <arglist>(const DynAnySeq_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~DynAnySeq_var</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynAnySeq_var &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(DynAnySeq *)</arglist>
    </member>
    <member kind="function">
      <type>DynAnySeq_var &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(const DynAnySeq_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynAnySeq *</type>
      <name>operator-&gt;</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const DynAnySeq *</type>
      <name>operator-&gt;</name>
      <anchor>a7</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator const DynAnySeq &amp;</name>
      <anchor>a8</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator DynAnySeq &amp;</name>
      <anchor>a9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator DynAnySeq &amp;</name>
      <anchor>a10</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator DynAnySeq *&amp;</name>
      <anchor>a11</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>TAO_Object_Manager&lt; DynAny, DynAny_var &gt;</type>
      <name>operator[]</name>
      <anchor>a12</anchor>
      <arglist>(CORBA::ULong index)</arglist>
    </member>
    <member kind="function">
      <type>const DynAnySeq &amp;</type>
      <name>in</name>
      <anchor>a13</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>DynAnySeq &amp;</type>
      <name>inout</name>
      <anchor>a14</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynAnySeq *&amp;</type>
      <name>out</name>
      <anchor>a15</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynAnySeq *</type>
      <name>_retn</name>
      <anchor>a16</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynAnySeq *</type>
      <name>ptr</name>
      <anchor>a17</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>DynAnySeq *</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>DynamicAny::DynArray</name>
    <filename>interfaceDynamicAny_1_1DynArray.html</filename>
    <base virtualness="virtual">DynamicAny::DynAny</base>
    <base>DynamicAny::DynAny</base>
    <member kind="typedef">
      <type>DynArray_ptr</type>
      <name>_ptr_type</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>DynArray_var</type>
      <name>_var_type</name>
      <anchor>s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>AnySeq</type>
      <name>get_elements</name>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_elements</name>
      <anchor>a1</anchor>
      <arglist>(in AnySeq value)</arglist>
    </member>
    <member kind="function">
      <type>DynAnySeq</type>
      <name>get_elements_as_dyn_any</name>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_elements_as_dyn_any</name>
      <anchor>a3</anchor>
      <arglist>(in DynAnySeq value)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual::DynamicAny::AnySeq *</type>
      <name>get_elements</name>
      <anchor>a4</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>set_elements</name>
      <anchor>a5</anchor>
      <arglist>(const DynamicAny::AnySeq &amp;value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual::DynamicAny::DynAnySeq *</type>
      <name>get_elements_as_dyn_any</name>
      <anchor>a6</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>set_elements_as_dyn_any</name>
      <anchor>a7</anchor>
      <arglist>(const DynamicAny::DynAnySeq &amp;value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>_tao_QueryInterface</name>
      <anchor>a8</anchor>
      <arglist>(ptr_arith_t type)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>_interface_repository_id</name>
      <anchor>a9</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynArray_ptr</type>
      <name>_duplicate</name>
      <anchor>d0</anchor>
      <arglist>(DynArray_ptr obj)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynArray_ptr</type>
      <name>_narrow</name>
      <anchor>d1</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynArray_ptr</type>
      <name>_unchecked_narrow</name>
      <anchor>d2</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynArray_ptr</type>
      <name>_nil</name>
      <anchor>d3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>int</type>
      <name>_tao_class_id</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="public">
      <type></type>
      <name>DynArray</name>
      <anchor>b0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual</type>
      <name>~DynArray</name>
      <anchor>b1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>DynArray</name>
      <anchor>c0</anchor>
      <arglist>(const DynArray &amp;)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const DynArray &amp;)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::DynArray_out</name>
    <filename>classDynamicAny_1_1DynArray__out.html</filename>
    <member kind="function">
      <type></type>
      <name>DynArray_out</name>
      <anchor>a0</anchor>
      <arglist>(DynArray_ptr &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynArray_out</name>
      <anchor>a1</anchor>
      <arglist>(DynArray_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynArray_out</name>
      <anchor>a2</anchor>
      <arglist>(const DynArray_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynArray_out &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const DynArray_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynArray_out &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(const DynArray_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynArray_out &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(DynArray_ptr)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator DynArray_ptr &amp;</name>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>DynArray_ptr &amp;</type>
      <name>ptr</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynArray_ptr</type>
      <name>operator-&gt;</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>DynArray_ptr &amp;</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::DynArray_var</name>
    <filename>classDynamicAny_1_1DynArray__var.html</filename>
    <base>TAO_Base_var</base>
    <member kind="function">
      <type></type>
      <name>DynArray_var</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynArray_var</name>
      <anchor>a1</anchor>
      <arglist>(DynArray_ptr p)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynArray_var</name>
      <anchor>a2</anchor>
      <arglist>(const DynArray_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~DynArray_var</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynArray_var &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(DynArray_ptr)</arglist>
    </member>
    <member kind="function">
      <type>DynArray_var &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(const DynArray_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynArray_ptr</type>
      <name>operator-&gt;</name>
      <anchor>a6</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator const DynArray_ptr &amp;</name>
      <anchor>a7</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator DynArray_ptr &amp;</name>
      <anchor>a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>DynArray_ptr</type>
      <name>in</name>
      <anchor>a9</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>DynArray_ptr &amp;</type>
      <name>inout</name>
      <anchor>a10</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynArray_ptr &amp;</type>
      <name>out</name>
      <anchor>a11</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynArray_ptr</type>
      <name>_retn</name>
      <anchor>a12</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynArray_ptr</type>
      <name>ptr</name>
      <anchor>a13</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynArray_ptr</type>
      <name>tao_duplicate</name>
      <anchor>d0</anchor>
      <arglist>(DynArray_ptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>tao_release</name>
      <anchor>d1</anchor>
      <arglist>(DynArray_ptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynArray_ptr</type>
      <name>tao_nil</name>
      <anchor>d2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynArray_ptr</type>
      <name>tao_narrow</name>
      <anchor>d3</anchor>
      <arglist>(CORBA::Object *ACE_ENV_ARG_DECL_NOT_USED)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::Object *</type>
      <name>tao_upcast</name>
      <anchor>d4</anchor>
      <arglist>(void *)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>DynArray_var</name>
      <anchor>c0</anchor>
      <arglist>(const TAO_Base_var &amp;rhs)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>DynArray_var &amp;</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const TAO_Base_var &amp;rhs)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>DynArray_ptr</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>DynamicAny::DynEnum</name>
    <filename>interfaceDynamicAny_1_1DynEnum.html</filename>
    <base virtualness="virtual">DynamicAny::DynAny</base>
    <base>DynamicAny::DynAny</base>
    <member kind="typedef">
      <type>DynEnum_ptr</type>
      <name>_ptr_type</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>DynEnum_var</type>
      <name>_var_type</name>
      <anchor>s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>string</type>
      <name>get_as_string</name>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_as_string</name>
      <anchor>a1</anchor>
      <arglist>(in string value)</arglist>
    </member>
    <member kind="function">
      <type>unsigned long</type>
      <name>get_as_ulong</name>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_as_ulong</name>
      <anchor>a3</anchor>
      <arglist>(in unsigned long value)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual char *</type>
      <name>get_as_string</name>
      <anchor>a4</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>set_as_string</name>
      <anchor>a5</anchor>
      <arglist>(const char *value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::ULong</type>
      <name>get_as_ulong</name>
      <anchor>a6</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>set_as_ulong</name>
      <anchor>a7</anchor>
      <arglist>(CORBA::ULong value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>_tao_QueryInterface</name>
      <anchor>a8</anchor>
      <arglist>(ptr_arith_t type)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>_interface_repository_id</name>
      <anchor>a9</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynEnum_ptr</type>
      <name>_duplicate</name>
      <anchor>d0</anchor>
      <arglist>(DynEnum_ptr obj)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynEnum_ptr</type>
      <name>_narrow</name>
      <anchor>d1</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynEnum_ptr</type>
      <name>_unchecked_narrow</name>
      <anchor>d2</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynEnum_ptr</type>
      <name>_nil</name>
      <anchor>d3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>int</type>
      <name>_tao_class_id</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="public">
      <type></type>
      <name>DynEnum</name>
      <anchor>b0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual</type>
      <name>~DynEnum</name>
      <anchor>b1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>DynEnum</name>
      <anchor>c0</anchor>
      <arglist>(const DynEnum &amp;)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const DynEnum &amp;)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::DynEnum_out</name>
    <filename>classDynamicAny_1_1DynEnum__out.html</filename>
    <member kind="function">
      <type></type>
      <name>DynEnum_out</name>
      <anchor>a0</anchor>
      <arglist>(DynEnum_ptr &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynEnum_out</name>
      <anchor>a1</anchor>
      <arglist>(DynEnum_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynEnum_out</name>
      <anchor>a2</anchor>
      <arglist>(const DynEnum_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynEnum_out &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const DynEnum_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynEnum_out &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(const DynEnum_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynEnum_out &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(DynEnum_ptr)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator DynEnum_ptr &amp;</name>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>DynEnum_ptr &amp;</type>
      <name>ptr</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynEnum_ptr</type>
      <name>operator-&gt;</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>DynEnum_ptr &amp;</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::DynEnum_var</name>
    <filename>classDynamicAny_1_1DynEnum__var.html</filename>
    <base>TAO_Base_var</base>
    <member kind="function">
      <type></type>
      <name>DynEnum_var</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynEnum_var</name>
      <anchor>a1</anchor>
      <arglist>(DynEnum_ptr p)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynEnum_var</name>
      <anchor>a2</anchor>
      <arglist>(const DynEnum_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~DynEnum_var</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynEnum_var &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(DynEnum_ptr)</arglist>
    </member>
    <member kind="function">
      <type>DynEnum_var &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(const DynEnum_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynEnum_ptr</type>
      <name>operator-&gt;</name>
      <anchor>a6</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator const DynEnum_ptr &amp;</name>
      <anchor>a7</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator DynEnum_ptr &amp;</name>
      <anchor>a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>DynEnum_ptr</type>
      <name>in</name>
      <anchor>a9</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>DynEnum_ptr &amp;</type>
      <name>inout</name>
      <anchor>a10</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynEnum_ptr &amp;</type>
      <name>out</name>
      <anchor>a11</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynEnum_ptr</type>
      <name>_retn</name>
      <anchor>a12</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynEnum_ptr</type>
      <name>ptr</name>
      <anchor>a13</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynEnum_ptr</type>
      <name>tao_duplicate</name>
      <anchor>d0</anchor>
      <arglist>(DynEnum_ptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>tao_release</name>
      <anchor>d1</anchor>
      <arglist>(DynEnum_ptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynEnum_ptr</type>
      <name>tao_nil</name>
      <anchor>d2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynEnum_ptr</type>
      <name>tao_narrow</name>
      <anchor>d3</anchor>
      <arglist>(CORBA::Object *ACE_ENV_ARG_DECL_NOT_USED)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::Object *</type>
      <name>tao_upcast</name>
      <anchor>d4</anchor>
      <arglist>(void *)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>DynEnum_var</name>
      <anchor>c0</anchor>
      <arglist>(const TAO_Base_var &amp;rhs)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>DynEnum_var &amp;</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const TAO_Base_var &amp;rhs)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>DynEnum_ptr</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>DynamicAny::DynFixed</name>
    <filename>interfaceDynamicAny_1_1DynFixed.html</filename>
    <base virtualness="virtual">DynamicAny::DynAny</base>
    <base>DynamicAny::DynAny</base>
    <member kind="typedef">
      <type>DynFixed_ptr</type>
      <name>_ptr_type</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>DynFixed_var</type>
      <name>_var_type</name>
      <anchor>s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>string</type>
      <name>get_value</name>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>set_value</name>
      <anchor>a1</anchor>
      <arglist>(in string val)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual char *</type>
      <name>get_value</name>
      <anchor>a2</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Boolean</type>
      <name>set_value</name>
      <anchor>a3</anchor>
      <arglist>(const char *val ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>_tao_QueryInterface</name>
      <anchor>a4</anchor>
      <arglist>(ptr_arith_t type)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>_interface_repository_id</name>
      <anchor>a5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynFixed_ptr</type>
      <name>_duplicate</name>
      <anchor>d0</anchor>
      <arglist>(DynFixed_ptr obj)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynFixed_ptr</type>
      <name>_narrow</name>
      <anchor>d1</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynFixed_ptr</type>
      <name>_unchecked_narrow</name>
      <anchor>d2</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynFixed_ptr</type>
      <name>_nil</name>
      <anchor>d3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>int</type>
      <name>_tao_class_id</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="public">
      <type></type>
      <name>DynFixed</name>
      <anchor>b0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual</type>
      <name>~DynFixed</name>
      <anchor>b1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>DynFixed</name>
      <anchor>c0</anchor>
      <arglist>(const DynFixed &amp;)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const DynFixed &amp;)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::DynFixed_out</name>
    <filename>classDynamicAny_1_1DynFixed__out.html</filename>
    <member kind="function">
      <type></type>
      <name>DynFixed_out</name>
      <anchor>a0</anchor>
      <arglist>(DynFixed_ptr &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynFixed_out</name>
      <anchor>a1</anchor>
      <arglist>(DynFixed_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynFixed_out</name>
      <anchor>a2</anchor>
      <arglist>(const DynFixed_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynFixed_out &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const DynFixed_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynFixed_out &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(const DynFixed_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynFixed_out &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(DynFixed_ptr)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator DynFixed_ptr &amp;</name>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>DynFixed_ptr &amp;</type>
      <name>ptr</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynFixed_ptr</type>
      <name>operator-&gt;</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>DynFixed_ptr &amp;</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::DynFixed_var</name>
    <filename>classDynamicAny_1_1DynFixed__var.html</filename>
    <base>TAO_Base_var</base>
    <member kind="function">
      <type></type>
      <name>DynFixed_var</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynFixed_var</name>
      <anchor>a1</anchor>
      <arglist>(DynFixed_ptr p)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynFixed_var</name>
      <anchor>a2</anchor>
      <arglist>(const DynFixed_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~DynFixed_var</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynFixed_var &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(DynFixed_ptr)</arglist>
    </member>
    <member kind="function">
      <type>DynFixed_var &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(const DynFixed_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynFixed_ptr</type>
      <name>operator-&gt;</name>
      <anchor>a6</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator const DynFixed_ptr &amp;</name>
      <anchor>a7</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator DynFixed_ptr &amp;</name>
      <anchor>a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>DynFixed_ptr</type>
      <name>in</name>
      <anchor>a9</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>DynFixed_ptr &amp;</type>
      <name>inout</name>
      <anchor>a10</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynFixed_ptr &amp;</type>
      <name>out</name>
      <anchor>a11</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynFixed_ptr</type>
      <name>_retn</name>
      <anchor>a12</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynFixed_ptr</type>
      <name>ptr</name>
      <anchor>a13</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynFixed_ptr</type>
      <name>tao_duplicate</name>
      <anchor>d0</anchor>
      <arglist>(DynFixed_ptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>tao_release</name>
      <anchor>d1</anchor>
      <arglist>(DynFixed_ptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynFixed_ptr</type>
      <name>tao_nil</name>
      <anchor>d2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynFixed_ptr</type>
      <name>tao_narrow</name>
      <anchor>d3</anchor>
      <arglist>(CORBA::Object *ACE_ENV_ARG_DECL_NOT_USED)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::Object *</type>
      <name>tao_upcast</name>
      <anchor>d4</anchor>
      <arglist>(void *)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>DynFixed_var</name>
      <anchor>c0</anchor>
      <arglist>(const TAO_Base_var &amp;rhs)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>DynFixed_var &amp;</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const TAO_Base_var &amp;rhs)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>DynFixed_ptr</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>DynamicAny::DynSequence</name>
    <filename>interfaceDynamicAny_1_1DynSequence.html</filename>
    <base virtualness="virtual">DynamicAny::DynAny</base>
    <base>DynamicAny::DynAny</base>
    <member kind="typedef">
      <type>DynSequence_ptr</type>
      <name>_ptr_type</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>DynSequence_var</type>
      <name>_var_type</name>
      <anchor>s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>unsigned long</type>
      <name>get_length</name>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_length</name>
      <anchor>a1</anchor>
      <arglist>(in unsigned long len)</arglist>
    </member>
    <member kind="function">
      <type>AnySeq</type>
      <name>get_elements</name>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_elements</name>
      <anchor>a3</anchor>
      <arglist>(in AnySeq value)</arglist>
    </member>
    <member kind="function">
      <type>DynAnySeq</type>
      <name>get_elements_as_dyn_any</name>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_elements_as_dyn_any</name>
      <anchor>a5</anchor>
      <arglist>(in DynAnySeq value)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::ULong</type>
      <name>get_length</name>
      <anchor>a6</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>set_length</name>
      <anchor>a7</anchor>
      <arglist>(CORBA::ULong len ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual::DynamicAny::AnySeq *</type>
      <name>get_elements</name>
      <anchor>a8</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>set_elements</name>
      <anchor>a9</anchor>
      <arglist>(const DynamicAny::AnySeq &amp;value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual::DynamicAny::DynAnySeq *</type>
      <name>get_elements_as_dyn_any</name>
      <anchor>a10</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>set_elements_as_dyn_any</name>
      <anchor>a11</anchor>
      <arglist>(const DynamicAny::DynAnySeq &amp;value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>_tao_QueryInterface</name>
      <anchor>a12</anchor>
      <arglist>(ptr_arith_t type)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>_interface_repository_id</name>
      <anchor>a13</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynSequence_ptr</type>
      <name>_duplicate</name>
      <anchor>d0</anchor>
      <arglist>(DynSequence_ptr obj)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynSequence_ptr</type>
      <name>_narrow</name>
      <anchor>d1</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynSequence_ptr</type>
      <name>_unchecked_narrow</name>
      <anchor>d2</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynSequence_ptr</type>
      <name>_nil</name>
      <anchor>d3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>int</type>
      <name>_tao_class_id</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="public">
      <type></type>
      <name>DynSequence</name>
      <anchor>b0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual</type>
      <name>~DynSequence</name>
      <anchor>b1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>DynSequence</name>
      <anchor>c0</anchor>
      <arglist>(const DynSequence &amp;)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const DynSequence &amp;)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::DynSequence_out</name>
    <filename>classDynamicAny_1_1DynSequence__out.html</filename>
    <member kind="function">
      <type></type>
      <name>DynSequence_out</name>
      <anchor>a0</anchor>
      <arglist>(DynSequence_ptr &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynSequence_out</name>
      <anchor>a1</anchor>
      <arglist>(DynSequence_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynSequence_out</name>
      <anchor>a2</anchor>
      <arglist>(const DynSequence_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynSequence_out &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const DynSequence_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynSequence_out &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(const DynSequence_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynSequence_out &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(DynSequence_ptr)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator DynSequence_ptr &amp;</name>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>DynSequence_ptr &amp;</type>
      <name>ptr</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynSequence_ptr</type>
      <name>operator-&gt;</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>DynSequence_ptr &amp;</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::DynSequence_var</name>
    <filename>classDynamicAny_1_1DynSequence__var.html</filename>
    <base>TAO_Base_var</base>
    <member kind="function">
      <type></type>
      <name>DynSequence_var</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynSequence_var</name>
      <anchor>a1</anchor>
      <arglist>(DynSequence_ptr p)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynSequence_var</name>
      <anchor>a2</anchor>
      <arglist>(const DynSequence_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~DynSequence_var</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynSequence_var &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(DynSequence_ptr)</arglist>
    </member>
    <member kind="function">
      <type>DynSequence_var &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(const DynSequence_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynSequence_ptr</type>
      <name>operator-&gt;</name>
      <anchor>a6</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator const DynSequence_ptr &amp;</name>
      <anchor>a7</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator DynSequence_ptr &amp;</name>
      <anchor>a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>DynSequence_ptr</type>
      <name>in</name>
      <anchor>a9</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>DynSequence_ptr &amp;</type>
      <name>inout</name>
      <anchor>a10</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynSequence_ptr &amp;</type>
      <name>out</name>
      <anchor>a11</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynSequence_ptr</type>
      <name>_retn</name>
      <anchor>a12</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynSequence_ptr</type>
      <name>ptr</name>
      <anchor>a13</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynSequence_ptr</type>
      <name>tao_duplicate</name>
      <anchor>d0</anchor>
      <arglist>(DynSequence_ptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>tao_release</name>
      <anchor>d1</anchor>
      <arglist>(DynSequence_ptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynSequence_ptr</type>
      <name>tao_nil</name>
      <anchor>d2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynSequence_ptr</type>
      <name>tao_narrow</name>
      <anchor>d3</anchor>
      <arglist>(CORBA::Object *ACE_ENV_ARG_DECL_NOT_USED)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::Object *</type>
      <name>tao_upcast</name>
      <anchor>d4</anchor>
      <arglist>(void *)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>DynSequence_var</name>
      <anchor>c0</anchor>
      <arglist>(const TAO_Base_var &amp;rhs)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>DynSequence_var &amp;</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const TAO_Base_var &amp;rhs)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>DynSequence_ptr</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>DynamicAny::DynStruct</name>
    <filename>interfaceDynamicAny_1_1DynStruct.html</filename>
    <base virtualness="virtual">DynamicAny::DynAny</base>
    <base>DynamicAny::DynAny</base>
    <member kind="typedef">
      <type>DynStruct_ptr</type>
      <name>_ptr_type</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>DynStruct_var</type>
      <name>_var_type</name>
      <anchor>s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>FieldName</type>
      <name>current_member_name</name>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>CORBA::TCKind</type>
      <name>current_member_kind</name>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>NameValuePairSeq</type>
      <name>get_members</name>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_members</name>
      <anchor>a3</anchor>
      <arglist>(in NameValuePairSeq value)</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPairSeq</type>
      <name>get_members_as_dyn_any</name>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_members_as_dyn_any</name>
      <anchor>a5</anchor>
      <arglist>(in NameDynAnyPairSeq value)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual char *</type>
      <name>current_member_name</name>
      <anchor>a6</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::TCKind</type>
      <name>current_member_kind</name>
      <anchor>a7</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual::DynamicAny::NameValuePairSeq *</type>
      <name>get_members</name>
      <anchor>a8</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>set_members</name>
      <anchor>a9</anchor>
      <arglist>(const DynamicAny::NameValuePairSeq &amp;value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual::DynamicAny::NameDynAnyPairSeq *</type>
      <name>get_members_as_dyn_any</name>
      <anchor>a10</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>set_members_as_dyn_any</name>
      <anchor>a11</anchor>
      <arglist>(const DynamicAny::NameDynAnyPairSeq &amp;value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>_tao_QueryInterface</name>
      <anchor>a12</anchor>
      <arglist>(ptr_arith_t type)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>_interface_repository_id</name>
      <anchor>a13</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynStruct_ptr</type>
      <name>_duplicate</name>
      <anchor>d0</anchor>
      <arglist>(DynStruct_ptr obj)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynStruct_ptr</type>
      <name>_narrow</name>
      <anchor>d1</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynStruct_ptr</type>
      <name>_unchecked_narrow</name>
      <anchor>d2</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynStruct_ptr</type>
      <name>_nil</name>
      <anchor>d3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>int</type>
      <name>_tao_class_id</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="public">
      <type></type>
      <name>DynStruct</name>
      <anchor>b0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual</type>
      <name>~DynStruct</name>
      <anchor>b1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>DynStruct</name>
      <anchor>c0</anchor>
      <arglist>(const DynStruct &amp;)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const DynStruct &amp;)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::DynStruct_out</name>
    <filename>classDynamicAny_1_1DynStruct__out.html</filename>
    <member kind="function">
      <type></type>
      <name>DynStruct_out</name>
      <anchor>a0</anchor>
      <arglist>(DynStruct_ptr &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynStruct_out</name>
      <anchor>a1</anchor>
      <arglist>(DynStruct_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynStruct_out</name>
      <anchor>a2</anchor>
      <arglist>(const DynStruct_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynStruct_out &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const DynStruct_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynStruct_out &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(const DynStruct_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynStruct_out &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(DynStruct_ptr)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator DynStruct_ptr &amp;</name>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>DynStruct_ptr &amp;</type>
      <name>ptr</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynStruct_ptr</type>
      <name>operator-&gt;</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>DynStruct_ptr &amp;</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::DynStruct_var</name>
    <filename>classDynamicAny_1_1DynStruct__var.html</filename>
    <base>TAO_Base_var</base>
    <member kind="function">
      <type></type>
      <name>DynStruct_var</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynStruct_var</name>
      <anchor>a1</anchor>
      <arglist>(DynStruct_ptr p)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynStruct_var</name>
      <anchor>a2</anchor>
      <arglist>(const DynStruct_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~DynStruct_var</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynStruct_var &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(DynStruct_ptr)</arglist>
    </member>
    <member kind="function">
      <type>DynStruct_var &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(const DynStruct_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynStruct_ptr</type>
      <name>operator-&gt;</name>
      <anchor>a6</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator const DynStruct_ptr &amp;</name>
      <anchor>a7</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator DynStruct_ptr &amp;</name>
      <anchor>a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>DynStruct_ptr</type>
      <name>in</name>
      <anchor>a9</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>DynStruct_ptr &amp;</type>
      <name>inout</name>
      <anchor>a10</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynStruct_ptr &amp;</type>
      <name>out</name>
      <anchor>a11</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynStruct_ptr</type>
      <name>_retn</name>
      <anchor>a12</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynStruct_ptr</type>
      <name>ptr</name>
      <anchor>a13</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynStruct_ptr</type>
      <name>tao_duplicate</name>
      <anchor>d0</anchor>
      <arglist>(DynStruct_ptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>tao_release</name>
      <anchor>d1</anchor>
      <arglist>(DynStruct_ptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynStruct_ptr</type>
      <name>tao_nil</name>
      <anchor>d2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynStruct_ptr</type>
      <name>tao_narrow</name>
      <anchor>d3</anchor>
      <arglist>(CORBA::Object *ACE_ENV_ARG_DECL_NOT_USED)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::Object *</type>
      <name>tao_upcast</name>
      <anchor>d4</anchor>
      <arglist>(void *)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>DynStruct_var</name>
      <anchor>c0</anchor>
      <arglist>(const TAO_Base_var &amp;rhs)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>DynStruct_var &amp;</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const TAO_Base_var &amp;rhs)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>DynStruct_ptr</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>DynamicAny::DynUnion</name>
    <filename>interfaceDynamicAny_1_1DynUnion.html</filename>
    <base virtualness="virtual">DynamicAny::DynAny</base>
    <base>DynamicAny::DynAny</base>
    <member kind="typedef">
      <type>DynUnion_ptr</type>
      <name>_ptr_type</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>DynUnion_var</type>
      <name>_var_type</name>
      <anchor>s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>DynAny</type>
      <name>get_discriminator</name>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_discriminator</name>
      <anchor>a1</anchor>
      <arglist>(in DynAny d)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_to_default_member</name>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_to_no_active_member</name>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>has_no_active_member</name>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>CORBA::TCKind</type>
      <name>discriminator_kind</name>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>DynAny</type>
      <name>member</name>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>FieldName</type>
      <name>member_name</name>
      <anchor>a7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>CORBA::TCKind</type>
      <name>member_kind</name>
      <anchor>a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual::DynamicAny::DynAny_ptr</type>
      <name>get_discriminator</name>
      <anchor>a9</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>set_discriminator</name>
      <anchor>a10</anchor>
      <arglist>(DynamicAny::DynAny_ptr d ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>set_to_default_member</name>
      <anchor>a11</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>set_to_no_active_member</name>
      <anchor>a12</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Boolean</type>
      <name>has_no_active_member</name>
      <anchor>a13</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::TCKind</type>
      <name>discriminator_kind</name>
      <anchor>a14</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual::DynamicAny::DynAny_ptr</type>
      <name>member</name>
      <anchor>a15</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual char *</type>
      <name>member_name</name>
      <anchor>a16</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::TCKind</type>
      <name>member_kind</name>
      <anchor>a17</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>_tao_QueryInterface</name>
      <anchor>a18</anchor>
      <arglist>(ptr_arith_t type)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>_interface_repository_id</name>
      <anchor>a19</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynUnion_ptr</type>
      <name>_duplicate</name>
      <anchor>d0</anchor>
      <arglist>(DynUnion_ptr obj)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynUnion_ptr</type>
      <name>_narrow</name>
      <anchor>d1</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynUnion_ptr</type>
      <name>_unchecked_narrow</name>
      <anchor>d2</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynUnion_ptr</type>
      <name>_nil</name>
      <anchor>d3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>int</type>
      <name>_tao_class_id</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="public">
      <type></type>
      <name>DynUnion</name>
      <anchor>b0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual</type>
      <name>~DynUnion</name>
      <anchor>b1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>DynUnion</name>
      <anchor>c0</anchor>
      <arglist>(const DynUnion &amp;)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const DynUnion &amp;)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::DynUnion_out</name>
    <filename>classDynamicAny_1_1DynUnion__out.html</filename>
    <member kind="function">
      <type></type>
      <name>DynUnion_out</name>
      <anchor>a0</anchor>
      <arglist>(DynUnion_ptr &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynUnion_out</name>
      <anchor>a1</anchor>
      <arglist>(DynUnion_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynUnion_out</name>
      <anchor>a2</anchor>
      <arglist>(const DynUnion_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynUnion_out &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const DynUnion_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynUnion_out &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(const DynUnion_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynUnion_out &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(DynUnion_ptr)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator DynUnion_ptr &amp;</name>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>DynUnion_ptr &amp;</type>
      <name>ptr</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynUnion_ptr</type>
      <name>operator-&gt;</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>DynUnion_ptr &amp;</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::DynUnion_var</name>
    <filename>classDynamicAny_1_1DynUnion__var.html</filename>
    <base>TAO_Base_var</base>
    <member kind="function">
      <type></type>
      <name>DynUnion_var</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynUnion_var</name>
      <anchor>a1</anchor>
      <arglist>(DynUnion_ptr p)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynUnion_var</name>
      <anchor>a2</anchor>
      <arglist>(const DynUnion_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~DynUnion_var</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynUnion_var &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(DynUnion_ptr)</arglist>
    </member>
    <member kind="function">
      <type>DynUnion_var &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(const DynUnion_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynUnion_ptr</type>
      <name>operator-&gt;</name>
      <anchor>a6</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator const DynUnion_ptr &amp;</name>
      <anchor>a7</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator DynUnion_ptr &amp;</name>
      <anchor>a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>DynUnion_ptr</type>
      <name>in</name>
      <anchor>a9</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>DynUnion_ptr &amp;</type>
      <name>inout</name>
      <anchor>a10</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynUnion_ptr &amp;</type>
      <name>out</name>
      <anchor>a11</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynUnion_ptr</type>
      <name>_retn</name>
      <anchor>a12</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynUnion_ptr</type>
      <name>ptr</name>
      <anchor>a13</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynUnion_ptr</type>
      <name>tao_duplicate</name>
      <anchor>d0</anchor>
      <arglist>(DynUnion_ptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>tao_release</name>
      <anchor>d1</anchor>
      <arglist>(DynUnion_ptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynUnion_ptr</type>
      <name>tao_nil</name>
      <anchor>d2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynUnion_ptr</type>
      <name>tao_narrow</name>
      <anchor>d3</anchor>
      <arglist>(CORBA::Object *ACE_ENV_ARG_DECL_NOT_USED)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::Object *</type>
      <name>tao_upcast</name>
      <anchor>d4</anchor>
      <arglist>(void *)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>DynUnion_var</name>
      <anchor>c0</anchor>
      <arglist>(const TAO_Base_var &amp;rhs)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>DynUnion_var &amp;</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const TAO_Base_var &amp;rhs)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>DynUnion_ptr</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>DynamicAny::DynValue</name>
    <filename>interfaceDynamicAny_1_1DynValue.html</filename>
    <base virtualness="virtual">DynamicAny::DynAny</base>
    <base>DynamicAny::DynAny</base>
    <member kind="typedef">
      <type>DynValue_ptr</type>
      <name>_ptr_type</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>DynValue_var</type>
      <name>_var_type</name>
      <anchor>s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>FieldName</type>
      <name>current_member_name</name>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>CORBA::TCKind</type>
      <name>current_member_kind</name>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>NameValuePairSeq</type>
      <name>get_members</name>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_members</name>
      <anchor>a3</anchor>
      <arglist>(in NameValuePairSeq value)</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPairSeq</type>
      <name>get_members_as_dyn_any</name>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_members_as_dyn_any</name>
      <anchor>a5</anchor>
      <arglist>(in NameDynAnyPairSeq value)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual char *</type>
      <name>current_member_name</name>
      <anchor>a6</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::TCKind</type>
      <name>current_member_kind</name>
      <anchor>a7</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual::DynamicAny::NameValuePairSeq *</type>
      <name>get_members</name>
      <anchor>a8</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>set_members</name>
      <anchor>a9</anchor>
      <arglist>(const DynamicAny::NameValuePairSeq &amp;value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual::DynamicAny::NameDynAnyPairSeq *</type>
      <name>get_members_as_dyn_any</name>
      <anchor>a10</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>set_members_as_dyn_any</name>
      <anchor>a11</anchor>
      <arglist>(const DynamicAny::NameDynAnyPairSeq &amp;value ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>_tao_QueryInterface</name>
      <anchor>a12</anchor>
      <arglist>(ptr_arith_t type)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>_interface_repository_id</name>
      <anchor>a13</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynValue_ptr</type>
      <name>_duplicate</name>
      <anchor>d0</anchor>
      <arglist>(DynValue_ptr obj)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynValue_ptr</type>
      <name>_narrow</name>
      <anchor>d1</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynValue_ptr</type>
      <name>_unchecked_narrow</name>
      <anchor>d2</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynValue_ptr</type>
      <name>_nil</name>
      <anchor>d3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>int</type>
      <name>_tao_class_id</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="public">
      <type></type>
      <name>DynValue</name>
      <anchor>b0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual</type>
      <name>~DynValue</name>
      <anchor>b1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>DynValue</name>
      <anchor>c0</anchor>
      <arglist>(const DynValue &amp;)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const DynValue &amp;)</arglist>
    </member>
  </compound>
  <compound kind="exception">
    <name>DynamicAny::DynAnyFactory::InconsistentTypeCode</name>
    <filename>exceptionDynamicAny_1_1DynAnyFactory_1_1InconsistentTypeCode.html</filename>
    <member kind="function">
      <type></type>
      <name>InconsistentTypeCode</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>InconsistentTypeCode</name>
      <anchor>a1</anchor>
      <arglist>(const InconsistentTypeCode &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~InconsistentTypeCode</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>InconsistentTypeCode &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const InconsistentTypeCode &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Exception *</type>
      <name>_tao_duplicate</name>
      <anchor>a4</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_raise</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_tao_encode</name>
      <anchor>a6</anchor>
      <arglist>(TAO_OutputCDR &amp;ACE_ENV_ARG_DECL_NOT_USED) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_tao_decode</name>
      <anchor>a7</anchor>
      <arglist>(TAO_InputCDR &amp;ACE_ENV_ARG_DECL_NOT_USED)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>InconsistentTypeCode *</type>
      <name>_downcast</name>
      <anchor>d0</anchor>
      <arglist>(CORBA::Exception *)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::Exception *</type>
      <name>_alloc</name>
      <anchor>d1</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::DynValue_out</name>
    <filename>classDynamicAny_1_1DynValue__out.html</filename>
    <member kind="function">
      <type></type>
      <name>DynValue_out</name>
      <anchor>a0</anchor>
      <arglist>(DynValue_ptr &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynValue_out</name>
      <anchor>a1</anchor>
      <arglist>(DynValue_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynValue_out</name>
      <anchor>a2</anchor>
      <arglist>(const DynValue_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynValue_out &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const DynValue_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynValue_out &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(const DynValue_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynValue_out &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(DynValue_ptr)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator DynValue_ptr &amp;</name>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>DynValue_ptr &amp;</type>
      <name>ptr</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynValue_ptr</type>
      <name>operator-&gt;</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>DynValue_ptr &amp;</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::DynValue_var</name>
    <filename>classDynamicAny_1_1DynValue__var.html</filename>
    <base>TAO_Base_var</base>
    <member kind="function">
      <type></type>
      <name>DynValue_var</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynValue_var</name>
      <anchor>a1</anchor>
      <arglist>(DynValue_ptr p)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>DynValue_var</name>
      <anchor>a2</anchor>
      <arglist>(const DynValue_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~DynValue_var</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynValue_var &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(DynValue_ptr)</arglist>
    </member>
    <member kind="function">
      <type>DynValue_var &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(const DynValue_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>DynValue_ptr</type>
      <name>operator-&gt;</name>
      <anchor>a6</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator const DynValue_ptr &amp;</name>
      <anchor>a7</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator DynValue_ptr &amp;</name>
      <anchor>a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>DynValue_ptr</type>
      <name>in</name>
      <anchor>a9</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>DynValue_ptr &amp;</type>
      <name>inout</name>
      <anchor>a10</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynValue_ptr &amp;</type>
      <name>out</name>
      <anchor>a11</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynValue_ptr</type>
      <name>_retn</name>
      <anchor>a12</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>DynValue_ptr</type>
      <name>ptr</name>
      <anchor>a13</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynValue_ptr</type>
      <name>tao_duplicate</name>
      <anchor>d0</anchor>
      <arglist>(DynValue_ptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>tao_release</name>
      <anchor>d1</anchor>
      <arglist>(DynValue_ptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynValue_ptr</type>
      <name>tao_nil</name>
      <anchor>d2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>DynValue_ptr</type>
      <name>tao_narrow</name>
      <anchor>d3</anchor>
      <arglist>(CORBA::Object *ACE_ENV_ARG_DECL_NOT_USED)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::Object *</type>
      <name>tao_upcast</name>
      <anchor>d4</anchor>
      <arglist>(void *)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>DynValue_var</name>
      <anchor>c0</anchor>
      <arglist>(const TAO_Base_var &amp;rhs)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>DynValue_var &amp;</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const TAO_Base_var &amp;rhs)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>DynValue_ptr</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>DynamicAny::NameDynAnyPair</name>
    <filename>structDynamicAny_1_1NameDynAnyPair.html</filename>
    <member kind="typedef">
      <type>NameDynAnyPair_var</type>
      <name>_var_type</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACE_NESTED_CLASS</name>
      <anchor>a0</anchor>
      <arglist>(DynamicAny, DynAny_var) value</arglist>
    </member>
    <member kind="variable">
      <type>FieldName</type>
      <name>id</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>DynAny</type>
      <name>value</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>TAO_String_Manager</type>
      <name>id</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::NameDynAnyPair_out</name>
    <filename>classDynamicAny_1_1NameDynAnyPair__out.html</filename>
    <member kind="function">
      <type></type>
      <name>NameDynAnyPair_out</name>
      <anchor>a0</anchor>
      <arglist>(NameDynAnyPair *&amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NameDynAnyPair_out</name>
      <anchor>a1</anchor>
      <arglist>(NameDynAnyPair_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NameDynAnyPair_out</name>
      <anchor>a2</anchor>
      <arglist>(const NameDynAnyPair_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPair_out &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const NameDynAnyPair_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPair_out &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(NameDynAnyPair *)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator NameDynAnyPair *&amp;</name>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPair *&amp;</type>
      <name>ptr</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPair *</type>
      <name>operator-&gt;</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>operator=</name>
      <anchor>c0</anchor>
      <arglist>(const NameDynAnyPair_var &amp;)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>NameDynAnyPair *&amp;</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::NameDynAnyPair_var</name>
    <filename>classDynamicAny_1_1NameDynAnyPair__var.html</filename>
    <member kind="function">
      <type></type>
      <name>NameDynAnyPair_var</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NameDynAnyPair_var</name>
      <anchor>a1</anchor>
      <arglist>(NameDynAnyPair *)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NameDynAnyPair_var</name>
      <anchor>a2</anchor>
      <arglist>(const NameDynAnyPair_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~NameDynAnyPair_var</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPair_var &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(NameDynAnyPair *)</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPair_var &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(const NameDynAnyPair_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPair *</type>
      <name>operator-&gt;</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const NameDynAnyPair *</type>
      <name>operator-&gt;</name>
      <anchor>a7</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator const NameDynAnyPair &amp;</name>
      <anchor>a8</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator NameDynAnyPair &amp;</name>
      <anchor>a9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator NameDynAnyPair &amp;</name>
      <anchor>a10</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator NameDynAnyPair *&amp;</name>
      <anchor>a11</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const NameDynAnyPair &amp;</type>
      <name>in</name>
      <anchor>a12</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPair &amp;</type>
      <name>inout</name>
      <anchor>a13</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPair *&amp;</type>
      <name>out</name>
      <anchor>a14</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPair *</type>
      <name>_retn</name>
      <anchor>a15</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPair *</type>
      <name>ptr</name>
      <anchor>a16</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>NameDynAnyPair *</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::NameDynAnyPairSeq</name>
    <filename>classDynamicAny_1_1NameDynAnyPairSeq.html</filename>
    <base>DynamicAny::_TAO_Unbounded_Sequence_DynamicAny_NameDynAnyPairSeq</base>
    <member kind="typedef">
      <type>NameDynAnyPairSeq_var</type>
      <name>_var_type</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NameDynAnyPairSeq</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NameDynAnyPairSeq</name>
      <anchor>a1</anchor>
      <arglist>(CORBA::ULong max)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NameDynAnyPairSeq</name>
      <anchor>a2</anchor>
      <arglist>(CORBA::ULong max, CORBA::ULong length, NameDynAnyPair *buffer, CORBA::Boolean release=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NameDynAnyPairSeq</name>
      <anchor>a3</anchor>
      <arglist>(const NameDynAnyPairSeq &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~NameDynAnyPairSeq</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>_tao_any_destructor</name>
      <anchor>d0</anchor>
      <arglist>(void *)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::NameDynAnyPairSeq_out</name>
    <filename>classDynamicAny_1_1NameDynAnyPairSeq__out.html</filename>
    <member kind="function">
      <type></type>
      <name>NameDynAnyPairSeq_out</name>
      <anchor>a0</anchor>
      <arglist>(NameDynAnyPairSeq *&amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NameDynAnyPairSeq_out</name>
      <anchor>a1</anchor>
      <arglist>(NameDynAnyPairSeq_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NameDynAnyPairSeq_out</name>
      <anchor>a2</anchor>
      <arglist>(const NameDynAnyPairSeq_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPairSeq_out &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const NameDynAnyPairSeq_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPairSeq_out &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(NameDynAnyPairSeq *)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator NameDynAnyPairSeq *&amp;</name>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPairSeq *&amp;</type>
      <name>ptr</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPairSeq *</type>
      <name>operator-&gt;</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPair &amp;</type>
      <name>operator[]</name>
      <anchor>a8</anchor>
      <arglist>(CORBA::ULong index)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>operator=</name>
      <anchor>c0</anchor>
      <arglist>(const NameDynAnyPairSeq_var &amp;)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>NameDynAnyPairSeq *&amp;</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::NameDynAnyPairSeq_var</name>
    <filename>classDynamicAny_1_1NameDynAnyPairSeq__var.html</filename>
    <member kind="function">
      <type></type>
      <name>NameDynAnyPairSeq_var</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NameDynAnyPairSeq_var</name>
      <anchor>a1</anchor>
      <arglist>(NameDynAnyPairSeq *)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NameDynAnyPairSeq_var</name>
      <anchor>a2</anchor>
      <arglist>(const NameDynAnyPairSeq_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~NameDynAnyPairSeq_var</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPairSeq_var &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(NameDynAnyPairSeq *)</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPairSeq_var &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(const NameDynAnyPairSeq_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPairSeq *</type>
      <name>operator-&gt;</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const NameDynAnyPairSeq *</type>
      <name>operator-&gt;</name>
      <anchor>a7</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator const NameDynAnyPairSeq &amp;</name>
      <anchor>a8</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator NameDynAnyPairSeq &amp;</name>
      <anchor>a9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator NameDynAnyPairSeq &amp;</name>
      <anchor>a10</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator NameDynAnyPairSeq *&amp;</name>
      <anchor>a11</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPair &amp;</type>
      <name>operator[]</name>
      <anchor>a12</anchor>
      <arglist>(CORBA::ULong index)</arglist>
    </member>
    <member kind="function">
      <type>const NameDynAnyPair &amp;</type>
      <name>operator[]</name>
      <anchor>a13</anchor>
      <arglist>(CORBA::ULong index) const</arglist>
    </member>
    <member kind="function">
      <type>const NameDynAnyPairSeq &amp;</type>
      <name>in</name>
      <anchor>a14</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPairSeq &amp;</type>
      <name>inout</name>
      <anchor>a15</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPairSeq *&amp;</type>
      <name>out</name>
      <anchor>a16</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPairSeq *</type>
      <name>_retn</name>
      <anchor>a17</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NameDynAnyPairSeq *</type>
      <name>ptr</name>
      <anchor>a18</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>NameDynAnyPairSeq *</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>DynamicAny::NameValuePair</name>
    <filename>structDynamicAny_1_1NameValuePair.html</filename>
    <member kind="typedef">
      <type>NameValuePair_var</type>
      <name>_var_type</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>_tao_any_destructor</name>
      <anchor>d0</anchor>
      <arglist>(void *)</arglist>
    </member>
    <member kind="variable">
      <type>FieldName</type>
      <name>id</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>any</type>
      <name>value</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>TAO_String_Manager</type>
      <name>id</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>CORBA::Any</type>
      <name>value</name>
      <anchor>m3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::NameValuePair_out</name>
    <filename>classDynamicAny_1_1NameValuePair__out.html</filename>
    <member kind="function">
      <type></type>
      <name>NameValuePair_out</name>
      <anchor>a0</anchor>
      <arglist>(NameValuePair *&amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NameValuePair_out</name>
      <anchor>a1</anchor>
      <arglist>(NameValuePair_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NameValuePair_out</name>
      <anchor>a2</anchor>
      <arglist>(const NameValuePair_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>NameValuePair_out &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const NameValuePair_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>NameValuePair_out &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(NameValuePair *)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator NameValuePair *&amp;</name>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>NameValuePair *&amp;</type>
      <name>ptr</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NameValuePair *</type>
      <name>operator-&gt;</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>operator=</name>
      <anchor>c0</anchor>
      <arglist>(const NameValuePair_var &amp;)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>NameValuePair *&amp;</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::NameValuePair_var</name>
    <filename>classDynamicAny_1_1NameValuePair__var.html</filename>
    <member kind="function">
      <type></type>
      <name>NameValuePair_var</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NameValuePair_var</name>
      <anchor>a1</anchor>
      <arglist>(NameValuePair *)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NameValuePair_var</name>
      <anchor>a2</anchor>
      <arglist>(const NameValuePair_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~NameValuePair_var</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NameValuePair_var &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(NameValuePair *)</arglist>
    </member>
    <member kind="function">
      <type>NameValuePair_var &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(const NameValuePair_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>NameValuePair *</type>
      <name>operator-&gt;</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const NameValuePair *</type>
      <name>operator-&gt;</name>
      <anchor>a7</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator const NameValuePair &amp;</name>
      <anchor>a8</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator NameValuePair &amp;</name>
      <anchor>a9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator NameValuePair &amp;</name>
      <anchor>a10</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator NameValuePair *&amp;</name>
      <anchor>a11</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>const NameValuePair &amp;</type>
      <name>in</name>
      <anchor>a12</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>NameValuePair &amp;</type>
      <name>inout</name>
      <anchor>a13</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NameValuePair *&amp;</type>
      <name>out</name>
      <anchor>a14</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NameValuePair *</type>
      <name>_retn</name>
      <anchor>a15</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NameValuePair *</type>
      <name>ptr</name>
      <anchor>a16</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>NameValuePair *</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::NameValuePairSeq</name>
    <filename>classDynamicAny_1_1NameValuePairSeq.html</filename>
    <base>DynamicAny::_TAO_Unbounded_Sequence_DynamicAny_NameValuePairSeq</base>
    <member kind="typedef">
      <type>NameValuePairSeq_var</type>
      <name>_var_type</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NameValuePairSeq</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NameValuePairSeq</name>
      <anchor>a1</anchor>
      <arglist>(CORBA::ULong max)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NameValuePairSeq</name>
      <anchor>a2</anchor>
      <arglist>(CORBA::ULong max, CORBA::ULong length, NameValuePair *buffer, CORBA::Boolean release=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NameValuePairSeq</name>
      <anchor>a3</anchor>
      <arglist>(const NameValuePairSeq &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~NameValuePairSeq</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>_tao_any_destructor</name>
      <anchor>d0</anchor>
      <arglist>(void *)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::NameValuePairSeq_out</name>
    <filename>classDynamicAny_1_1NameValuePairSeq__out.html</filename>
    <member kind="function">
      <type></type>
      <name>NameValuePairSeq_out</name>
      <anchor>a0</anchor>
      <arglist>(NameValuePairSeq *&amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NameValuePairSeq_out</name>
      <anchor>a1</anchor>
      <arglist>(NameValuePairSeq_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NameValuePairSeq_out</name>
      <anchor>a2</anchor>
      <arglist>(const NameValuePairSeq_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>NameValuePairSeq_out &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const NameValuePairSeq_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>NameValuePairSeq_out &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(NameValuePairSeq *)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator NameValuePairSeq *&amp;</name>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>NameValuePairSeq *&amp;</type>
      <name>ptr</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NameValuePairSeq *</type>
      <name>operator-&gt;</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NameValuePair &amp;</type>
      <name>operator[]</name>
      <anchor>a8</anchor>
      <arglist>(CORBA::ULong index)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>operator=</name>
      <anchor>c0</anchor>
      <arglist>(const NameValuePairSeq_var &amp;)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>NameValuePairSeq *&amp;</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>DynamicAny::NameValuePairSeq_var</name>
    <filename>classDynamicAny_1_1NameValuePairSeq__var.html</filename>
    <member kind="function">
      <type></type>
      <name>NameValuePairSeq_var</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NameValuePairSeq_var</name>
      <anchor>a1</anchor>
      <arglist>(NameValuePairSeq *)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NameValuePairSeq_var</name>
      <anchor>a2</anchor>
      <arglist>(const NameValuePairSeq_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~NameValuePairSeq_var</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NameValuePairSeq_var &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(NameValuePairSeq *)</arglist>
    </member>
    <member kind="function">
      <type>NameValuePairSeq_var &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(const NameValuePairSeq_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>NameValuePairSeq *</type>
      <name>operator-&gt;</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const NameValuePairSeq *</type>
      <name>operator-&gt;</name>
      <anchor>a7</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator const NameValuePairSeq &amp;</name>
      <anchor>a8</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator NameValuePairSeq &amp;</name>
      <anchor>a9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator NameValuePairSeq &amp;</name>
      <anchor>a10</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator NameValuePairSeq *&amp;</name>
      <anchor>a11</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>NameValuePair &amp;</type>
      <name>operator[]</name>
      <anchor>a12</anchor>
      <arglist>(CORBA::ULong index)</arglist>
    </member>
    <member kind="function">
      <type>const NameValuePair &amp;</type>
      <name>operator[]</name>
      <anchor>a13</anchor>
      <arglist>(CORBA::ULong index) const</arglist>
    </member>
    <member kind="function">
      <type>const NameValuePairSeq &amp;</type>
      <name>in</name>
      <anchor>a14</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>NameValuePairSeq &amp;</type>
      <name>inout</name>
      <anchor>a15</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NameValuePairSeq *&amp;</type>
      <name>out</name>
      <anchor>a16</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NameValuePairSeq *</type>
      <name>_retn</name>
      <anchor>a17</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NameValuePairSeq *</type>
      <name>ptr</name>
      <anchor>a18</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>NameValuePairSeq *</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
</tagfile>
