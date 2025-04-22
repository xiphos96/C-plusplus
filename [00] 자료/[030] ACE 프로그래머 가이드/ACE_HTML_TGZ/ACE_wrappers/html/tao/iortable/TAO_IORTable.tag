<?xml version='1.0' encoding='ISO-8859-1' standalone='yes'?>
<tagfile>
  <compound kind="file">
    <name>IOR_Table_Impl.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/IORTable/</path>
    <filename>IOR__Table__Impl_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_IORTable_IOR_Table_Impl</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_IORTable_IOR_Table_Impl</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>IOR_Table_Impl.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/IORTable/</path>
    <filename>IOR__Table__Impl_8h.html</filename>
    <class kind="class">TAO_IOR_Table_Impl</class>
  </compound>
  <compound kind="file">
    <name>IORTable.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/IORTable/</path>
    <filename>IORTable_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_IORTable_IORTable</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_IORTable_IORTable</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>IORTable.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/IORTable/</path>
    <filename>IORTable_8h.html</filename>
    <class kind="class">TAO_IORTable_Initializer</class>
    <member kind="define">
      <type>#define</type>
      <name>TAO_IORTABLE_SAFE_INCLUDE</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>int</type>
      <name>TAO_Requires_IORTable_Initializer</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>IORTable.pidl</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/IORTable/</path>
    <filename>IORTable_8pidl.html</filename>
    <namespace>IORTable</namespace>
  </compound>
  <compound kind="file">
    <name>iortable_export.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/IORTable/</path>
    <filename>iortable__export_8h.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>TAO_IORTABLE_HAS_DLL</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TAO_IORTable_Export</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TAO_IORTABLE_SINGLETON_DECLARATION</name>
      <anchor>a2</anchor>
      <arglist>(T)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TAO_IORTABLE_SINGLETON_DECLARE</name>
      <anchor>a3</anchor>
      <arglist>(SINGLETON_TYPE, CLASS, LOCK)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>IORTableC.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/IORTable/</path>
    <filename>IORTableC_8cpp.html</filename>
    <member kind="function">
      <type>IORTable::Table_ptr</type>
      <name>tao_IORTable_Table_duplicate</name>
      <anchor>a0</anchor>
      <arglist>(IORTable::Table_ptr p)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>tao_IORTable_Table_release</name>
      <anchor>a1</anchor>
      <arglist>(IORTable::Table_ptr p)</arglist>
    </member>
    <member kind="function">
      <type>IORTable::Table_ptr</type>
      <name>tao_IORTable_Table_nil</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>IORTable::Table_ptr</type>
      <name>tao_IORTable_Table_narrow</name>
      <anchor>a3</anchor>
      <arglist>(CORBA::Object *p ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Object *</type>
      <name>tao_IORTable_Table_upcast</name>
      <anchor>a4</anchor>
      <arglist>(void *src)</arglist>
    </member>
    <member kind="function">
      <type>IORTable::Locator_ptr</type>
      <name>tao_IORTable_Locator_duplicate</name>
      <anchor>a5</anchor>
      <arglist>(IORTable::Locator_ptr p)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>tao_IORTable_Locator_release</name>
      <anchor>a6</anchor>
      <arglist>(IORTable::Locator_ptr p)</arglist>
    </member>
    <member kind="function">
      <type>IORTable::Locator_ptr</type>
      <name>tao_IORTable_Locator_nil</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>IORTable::Locator_ptr</type>
      <name>tao_IORTable_Locator_narrow</name>
      <anchor>a8</anchor>
      <arglist>(CORBA::Object *p ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Object *</type>
      <name>tao_IORTable_Locator_upcast</name>
      <anchor>a9</anchor>
      <arglist>(void *src)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>IORTableC.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/IORTable/</path>
    <filename>IORTableC_8h.html</filename>
    <namespace>IORTable</namespace>
    <class kind="exception">IORTable::AlreadyBound</class>
    <class kind="interface">IORTable::Locator</class>
    <class kind="exception">IORTable::NotFound</class>
    <class kind="interface">IORTable::Table</class>
    <member kind="define">
      <type>#define</type>
      <name>TAO_EXPORT_MACRO</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_IORTABLE_LOCATOR___PTR_CH_</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_IORTABLE_LOCATOR___VAR_CH_</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_IORTABLE_LOCATOR___OUT_CH_</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_IORTABLE_ALREADYBOUND_CH_</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_IORTABLE_NOTFOUND_CH_</name>
      <anchor>a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_IORTABLE_TABLE___PTR_CH_</name>
      <anchor>a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_IORTABLE_TABLE___VAR_CH_</name>
      <anchor>a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_IORTABLE_TABLE___OUT_CH_</name>
      <anchor>a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_IORTABLE_TABLE_CH_</name>
      <anchor>a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_IORTABLE_LOCATOR_CH_</name>
      <anchor>a10</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>TAO_NAMESPACE_CLOSE TAO_IORTable_Export CORBA::Boolean</type>
      <name>operator&lt;&lt;</name>
      <anchor>a11</anchor>
      <arglist>(TAO_OutputCDR &amp;, const IORTable::AlreadyBound &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORTable_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;</name>
      <anchor>a12</anchor>
      <arglist>(TAO_InputCDR &amp;, IORTable::AlreadyBound &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORTable_Export CORBA::Boolean</type>
      <name>operator&lt;&lt;</name>
      <anchor>a13</anchor>
      <arglist>(TAO_OutputCDR &amp;, const IORTable::NotFound &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORTable_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;</name>
      <anchor>a14</anchor>
      <arglist>(TAO_InputCDR &amp;, IORTable::NotFound &amp;)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>IORTableC.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/IORTable/</path>
    <filename>IORTableC_8i.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>_IORTABLE_TABLE___CI_</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_IORTABLE_LOCATOR___CI_</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>ACE_INLINE CORBA::Boolean</type>
      <name>operator&lt;&lt;</name>
      <anchor>a2</anchor>
      <arglist>(TAO_OutputCDR &amp;strm, const IORTable::AlreadyBound &amp;_tao_aggregate)</arglist>
    </member>
    <member kind="function">
      <type>ACE_INLINE CORBA::Boolean</type>
      <name>operator&gt;&gt;</name>
      <anchor>a3</anchor>
      <arglist>(TAO_InputCDR &amp;, IORTable::AlreadyBound &amp;)</arglist>
    </member>
    <member kind="function">
      <type>ACE_INLINE CORBA::Boolean</type>
      <name>operator&lt;&lt;</name>
      <anchor>a4</anchor>
      <arglist>(TAO_OutputCDR &amp;strm, const IORTable::NotFound &amp;_tao_aggregate)</arglist>
    </member>
    <member kind="function">
      <type>ACE_INLINE CORBA::Boolean</type>
      <name>operator&gt;&gt;</name>
      <anchor>a5</anchor>
      <arglist>(TAO_InputCDR &amp;, IORTable::NotFound &amp;)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Table_Adapter.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/IORTable/</path>
    <filename>Table__Adapter_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_IORTable_Table_Adapter</name>
      <anchor>a2</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACE_FACTORY_DEFINE</name>
      <anchor>a3</anchor>
      <arglist>(TAO_IORTable, TAO_Table_Adapter_Factory) ACE_STATIC_SVC_DEFINE(TAO_Table_Adapter_Factory</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACE_TEXT</name>
      <anchor>a4</anchor>
      <arglist>(&quot;TAO_IORTable&quot;)</arglist>
    </member>
    <member kind="function">
      <type>&amp;</type>
      <name>ACE_SVC_NAME</name>
      <anchor>a5</anchor>
      <arglist>(TAO_Table_Adapter_Factory)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_IORTable_Table_Adapter</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type></type>
      <name>ACE_SVC_OBJ_T</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Table_Adapter.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/IORTable/</path>
    <filename>Table__Adapter_8h.html</filename>
    <class kind="class">TAO_Table_Adapter</class>
    <class kind="class">TAO_Table_Adapter_Factory</class>
    <member kind="function">
      <type></type>
      <name>ACE_STATIC_SVC_DECLARE</name>
      <anchor>a0</anchor>
      <arglist>(TAO_Table_Adapter_Factory) ACE_FACTORY_DECLARE(TAO_IORTable</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_IOR_Table_Impl</name>
    <filename>classTAO__IOR__Table__Impl.html</filename>
    <base virtualness="virtual">IORTable::Table</base>
    <base virtualness="virtual">TAO_Local_RefCounted_Object</base>
    <member kind="function">
      <type></type>
      <name>TAO_IOR_Table_Impl</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>char *</type>
      <name>find</name>
      <anchor>a1</anchor>
      <arglist>(const char *object_key ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>bind</name>
      <anchor>z0_0</anchor>
      <arglist>(const char *object_key, const char *IOR ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>rebind</name>
      <anchor>z0_1</anchor>
      <arglist>(const char *object_key, const char *IOR ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>unbind</name>
      <anchor>z0_2</anchor>
      <arglist>(const char *object_key ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_locator</name>
      <anchor>z0_3</anchor>
      <arglist>(IORTable::Locator_ptr the_locator ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="typedef" protection="protected">
      <type>ACE_Hash_Map_Manager_Ex&lt; ACE_CString, ACE_CString, ACE_Hash&lt; ACE_CString &gt;, ACE_Equal_To&lt; ACE_CString &gt;, ACE_Null_Mutex &gt;</type>
      <name>Map</name>
      <anchor>u0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>Map</type>
      <name>map_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>IORTable::Locator_var</type>
      <name>locator_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_SYNCH_MUTEX</type>
      <name>lock_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_IORTable_Initializer</name>
    <filename>classTAO__IORTable__Initializer.html</filename>
    <member kind="function" static="yes">
      <type>int</type>
      <name>init</name>
      <anchor>d0</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_Table_Adapter</name>
    <filename>classTAO__Table__Adapter.html</filename>
    <base>TAO_Adapter</base>
    <member kind="function">
      <type></type>
      <name>TAO_Table_Adapter</name>
      <anchor>a0</anchor>
      <arglist>(TAO_ORB_Core *orb_core)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_Table_Adapter</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>open</name>
      <anchor>a2</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>close</name>
      <anchor>a3</anchor>
      <arglist>(int wait_for_completion ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>check_close</name>
      <anchor>a4</anchor>
      <arglist>(int wait_for_completion ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>priority</name>
      <anchor>a5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>dispatch</name>
      <anchor>a6</anchor>
      <arglist>(TAO_ObjectKey &amp;key, TAO_ServerRequest &amp;request, CORBA::Object_out foward_to ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>name</name>
      <anchor>a7</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Object_ptr</type>
      <name>root</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Object_ptr</type>
      <name>create_collocated_object</name>
      <anchor>a9</anchor>
      <arglist>(TAO_Stub *, const TAO_MProfile &amp;)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_ORB_Core *</type>
      <name>orb_core_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_IOR_Table_Impl *</type>
      <name>root_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_Table_Adapter_Factory</name>
    <filename>classTAO__Table__Adapter__Factory.html</filename>
    <base>TAO_Adapter_Factory</base>
    <member kind="function">
      <type></type>
      <name>TAO_Table_Adapter_Factory</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_Adapter *</type>
      <name>create</name>
      <anchor>a1</anchor>
      <arglist>(TAO_ORB_Core *orb_core)</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>IORTable</name>
    <filename>namespaceIORTable.html</filename>
    <class kind="exception">IORTable::AlreadyBound</class>
    <class kind="interface">IORTable::Locator</class>
    <class kind="class">IORTable::Locator_out</class>
    <class kind="class">IORTable::Locator_var</class>
    <class kind="exception">IORTable::NotFound</class>
    <class kind="interface">IORTable::Table</class>
    <class kind="class">IORTable::Table_out</class>
    <class kind="class">IORTable::Table_var</class>
    <member kind="typedef">
      <type>Locator *</type>
      <name>Locator_ptr</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Table *</type>
      <name>Table_ptr</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>local interface</type>
      <name>Locator</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="exception">
    <name>IORTable::AlreadyBound</name>
    <filename>exceptionIORTable_1_1AlreadyBound.html</filename>
    <member kind="function">
      <type></type>
      <name>AlreadyBound</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>AlreadyBound</name>
      <anchor>a1</anchor>
      <arglist>(const AlreadyBound &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~AlreadyBound</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>AlreadyBound &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const AlreadyBound &amp;)</arglist>
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
      <type>void</type>
      <name>_tao_any_destructor</name>
      <anchor>d0</anchor>
      <arglist>(void *)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>AlreadyBound *</type>
      <name>_downcast</name>
      <anchor>d1</anchor>
      <arglist>(CORBA::Exception *)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::Exception *</type>
      <name>_alloc</name>
      <anchor>d2</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>IORTable::Locator</name>
    <filename>interfaceIORTable_1_1Locator.html</filename>
    <base virtualness="virtual">CORBA_Object</base>
    <member kind="typedef">
      <type>Locator_ptr</type>
      <name>_ptr_type</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Locator_var</type>
      <name>_var_type</name>
      <anchor>s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>string</type>
      <name>locate</name>
      <anchor>a0</anchor>
      <arglist>(in string object_key)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual char *</type>
      <name>locate</name>
      <anchor>a1</anchor>
      <arglist>(const char *object_key ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>_tao_QueryInterface</name>
      <anchor>a2</anchor>
      <arglist>(ptr_arith_t type)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>_interface_repository_id</name>
      <anchor>a3</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>Locator_ptr</type>
      <name>_duplicate</name>
      <anchor>d0</anchor>
      <arglist>(Locator_ptr obj)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>Locator_ptr</type>
      <name>_narrow</name>
      <anchor>d1</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>Locator_ptr</type>
      <name>_unchecked_narrow</name>
      <anchor>d2</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>Locator_ptr</type>
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
      <name>Locator</name>
      <anchor>b0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual</type>
      <name>~Locator</name>
      <anchor>b1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>Locator</name>
      <anchor>c0</anchor>
      <arglist>(const Locator &amp;)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const Locator &amp;)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>IORTable::Locator_out</name>
    <filename>classIORTable_1_1Locator__out.html</filename>
    <member kind="function">
      <type></type>
      <name>Locator_out</name>
      <anchor>a0</anchor>
      <arglist>(Locator_ptr &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Locator_out</name>
      <anchor>a1</anchor>
      <arglist>(Locator_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Locator_out</name>
      <anchor>a2</anchor>
      <arglist>(const Locator_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>Locator_out &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const Locator_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>Locator_out &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(const Locator_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>Locator_out &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(Locator_ptr)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator Locator_ptr &amp;</name>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Locator_ptr &amp;</type>
      <name>ptr</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>Locator_ptr</type>
      <name>operator-&gt;</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>Locator_ptr &amp;</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>IORTable::Locator_var</name>
    <filename>classIORTable_1_1Locator__var.html</filename>
    <base>TAO_Base_var</base>
    <member kind="function">
      <type></type>
      <name>Locator_var</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Locator_var</name>
      <anchor>a1</anchor>
      <arglist>(Locator_ptr p)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Locator_var</name>
      <anchor>a2</anchor>
      <arglist>(const Locator_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~Locator_var</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>Locator_var &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(Locator_ptr)</arglist>
    </member>
    <member kind="function">
      <type>Locator_var &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(const Locator_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>Locator_ptr</type>
      <name>operator-&gt;</name>
      <anchor>a6</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator const Locator_ptr &amp;</name>
      <anchor>a7</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator Locator_ptr &amp;</name>
      <anchor>a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Locator_ptr</type>
      <name>in</name>
      <anchor>a9</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>Locator_ptr &amp;</type>
      <name>inout</name>
      <anchor>a10</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>Locator_ptr &amp;</type>
      <name>out</name>
      <anchor>a11</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>Locator_ptr</type>
      <name>_retn</name>
      <anchor>a12</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>Locator_ptr</type>
      <name>ptr</name>
      <anchor>a13</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>Locator_ptr</type>
      <name>tao_duplicate</name>
      <anchor>d0</anchor>
      <arglist>(Locator_ptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>tao_release</name>
      <anchor>d1</anchor>
      <arglist>(Locator_ptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>Locator_ptr</type>
      <name>tao_nil</name>
      <anchor>d2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>Locator_ptr</type>
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
      <name>Locator_var</name>
      <anchor>c0</anchor>
      <arglist>(const TAO_Base_var &amp;rhs)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>Locator_var &amp;</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const TAO_Base_var &amp;rhs)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>Locator_ptr</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="exception">
    <name>IORTable::NotFound</name>
    <filename>exceptionIORTable_1_1NotFound.html</filename>
    <member kind="function">
      <type></type>
      <name>NotFound</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>NotFound</name>
      <anchor>a1</anchor>
      <arglist>(const NotFound &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~NotFound</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>NotFound &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const NotFound &amp;)</arglist>
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
      <type>void</type>
      <name>_tao_any_destructor</name>
      <anchor>d0</anchor>
      <arglist>(void *)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>NotFound *</type>
      <name>_downcast</name>
      <anchor>d1</anchor>
      <arglist>(CORBA::Exception *)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::Exception *</type>
      <name>_alloc</name>
      <anchor>d2</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>IORTable::Table</name>
    <filename>interfaceIORTable_1_1Table.html</filename>
    <base virtualness="virtual">CORBA_Object</base>
    <member kind="typedef">
      <type>Table_ptr</type>
      <name>_ptr_type</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>Table_var</type>
      <name>_var_type</name>
      <anchor>s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>bind</name>
      <anchor>a0</anchor>
      <arglist>(in string object_key, in string IOR)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>rebind</name>
      <anchor>a1</anchor>
      <arglist>(in string object_key, in string IOR)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>unbind</name>
      <anchor>a2</anchor>
      <arglist>(in string object_key)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_locator</name>
      <anchor>a3</anchor>
      <arglist>(in Locator the_locator)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>bind</name>
      <anchor>a4</anchor>
      <arglist>(const char *object_key, const char *IOR ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>rebind</name>
      <anchor>a5</anchor>
      <arglist>(const char *object_key, const char *IOR ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>unbind</name>
      <anchor>a6</anchor>
      <arglist>(const char *object_key ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>set_locator</name>
      <anchor>a7</anchor>
      <arglist>(IORTable::Locator_ptr the_locator ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
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
      <type>Table_ptr</type>
      <name>_duplicate</name>
      <anchor>d0</anchor>
      <arglist>(Table_ptr obj)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>Table_ptr</type>
      <name>_narrow</name>
      <anchor>d1</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>Table_ptr</type>
      <name>_unchecked_narrow</name>
      <anchor>d2</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>Table_ptr</type>
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
      <name>Table</name>
      <anchor>b0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual</type>
      <name>~Table</name>
      <anchor>b1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>Table</name>
      <anchor>c0</anchor>
      <arglist>(const Table &amp;)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const Table &amp;)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>IORTable::Table_out</name>
    <filename>classIORTable_1_1Table__out.html</filename>
    <member kind="function">
      <type></type>
      <name>Table_out</name>
      <anchor>a0</anchor>
      <arglist>(Table_ptr &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Table_out</name>
      <anchor>a1</anchor>
      <arglist>(Table_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Table_out</name>
      <anchor>a2</anchor>
      <arglist>(const Table_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>Table_out &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const Table_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>Table_out &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(const Table_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>Table_out &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(Table_ptr)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator Table_ptr &amp;</name>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Table_ptr &amp;</type>
      <name>ptr</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>Table_ptr</type>
      <name>operator-&gt;</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>Table_ptr &amp;</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>IORTable::Table_var</name>
    <filename>classIORTable_1_1Table__var.html</filename>
    <base>TAO_Base_var</base>
    <member kind="function">
      <type></type>
      <name>Table_var</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Table_var</name>
      <anchor>a1</anchor>
      <arglist>(Table_ptr p)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Table_var</name>
      <anchor>a2</anchor>
      <arglist>(const Table_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~Table_var</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>Table_var &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(Table_ptr)</arglist>
    </member>
    <member kind="function">
      <type>Table_var &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(const Table_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>Table_ptr</type>
      <name>operator-&gt;</name>
      <anchor>a6</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator const Table_ptr &amp;</name>
      <anchor>a7</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator Table_ptr &amp;</name>
      <anchor>a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>Table_ptr</type>
      <name>in</name>
      <anchor>a9</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>Table_ptr &amp;</type>
      <name>inout</name>
      <anchor>a10</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>Table_ptr &amp;</type>
      <name>out</name>
      <anchor>a11</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>Table_ptr</type>
      <name>_retn</name>
      <anchor>a12</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>Table_ptr</type>
      <name>ptr</name>
      <anchor>a13</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>Table_ptr</type>
      <name>tao_duplicate</name>
      <anchor>d0</anchor>
      <arglist>(Table_ptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>tao_release</name>
      <anchor>d1</anchor>
      <arglist>(Table_ptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>Table_ptr</type>
      <name>tao_nil</name>
      <anchor>d2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>Table_ptr</type>
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
      <name>Table_var</name>
      <anchor>c0</anchor>
      <arglist>(const TAO_Base_var &amp;rhs)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>Table_var &amp;</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const TAO_Base_var &amp;rhs)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>Table_ptr</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
</tagfile>
