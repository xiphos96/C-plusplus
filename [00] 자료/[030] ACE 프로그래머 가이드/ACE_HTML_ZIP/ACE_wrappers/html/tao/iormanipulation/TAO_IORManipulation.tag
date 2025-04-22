<?xml version='1.0' encoding='ISO-8859-1' standalone='yes'?>
<tagfile>
  <compound kind="file">
    <name>IOR.pidl</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/IORManipulation/</path>
    <filename>IOR_8pidl.html</filename>
    <namespace>TAO_IOP</namespace>
    <class kind="interface">TAO_IOP::TAO_IOR_Manipulation</class>
    <class kind="interface">TAO_IOP::TAO_IOR_Property</class>
  </compound>
  <compound kind="file">
    <name>ior_manip_export.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/IORManipulation/</path>
    <filename>ior__manip__export_8h.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>TAO_IORMANIP_HAS_DLL</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TAO_IORManip_Export</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TAO_IORMANIP_SINGLETON_DECLARATION</name>
      <anchor>a2</anchor>
      <arglist>(T)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TAO_IORMANIP_SINGLETON_DECLARE</name>
      <anchor>a3</anchor>
      <arglist>(SINGLETON_TYPE, CLASS, LOCK)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>IORC.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/IORManipulation/</path>
    <filename>IORC_8cpp.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>__TAO_UNBOUNDED_OBJECT_SEQUENCE_TAO_IOP_TAO_IOR_MANIPULATION_IORLIST_CS_</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_TAO_IOP_TAO_IOR_MANIPULATION_IORLIST_CS_</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::TypeCode</type>
      <name>_tc_TAO_tc_TAO_IOP_EmptyProfileList</name>
      <anchor>a7</anchor>
      <arglist>(CORBA::tk_except, sizeof(_oc_TAO_IOP_EmptyProfileList),(char *)&amp;_oc_TAO_IOP_EmptyProfileList, 0, sizeof(TAO_IOP::EmptyProfileList))</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_NAMESPACE_TYPE</name>
      <anchor>a8</anchor>
      <arglist>(CORBA::TypeCode_ptr) TAO_NAMESPACE_BEGIN(TAO_IOP) TAO_NAMESPACE_DEFINE(</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::TypeCode</type>
      <name>_tc_TAO_tc_TAO_IOP_NotFound</name>
      <anchor>a9</anchor>
      <arglist>(CORBA::tk_except, sizeof(_oc_TAO_IOP_NotFound),(char *)&amp;_oc_TAO_IOP_NotFound, 0, sizeof(TAO_IOP::NotFound))</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::TypeCode</type>
      <name>_tc_TAO_tc_TAO_IOP_Duplicate</name>
      <anchor>a10</anchor>
      <arglist>(CORBA::tk_except, sizeof(_oc_TAO_IOP_Duplicate),(char *)&amp;_oc_TAO_IOP_Duplicate, 0, sizeof(TAO_IOP::Duplicate))</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::TypeCode</type>
      <name>_tc_TAO_tc_TAO_IOP_Invalid_IOR</name>
      <anchor>a11</anchor>
      <arglist>(CORBA::tk_except, sizeof(_oc_TAO_IOP_Invalid_IOR),(char *)&amp;_oc_TAO_IOP_Invalid_IOR, 0, sizeof(TAO_IOP::Invalid_IOR))</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::TypeCode</type>
      <name>_tc_TAO_tc_TAO_IOP_MultiProfileList</name>
      <anchor>a12</anchor>
      <arglist>(CORBA::tk_except, sizeof(_oc_TAO_IOP_MultiProfileList),(char *)&amp;_oc_TAO_IOP_MultiProfileList, 0, sizeof(TAO_IOP::MultiProfileList))</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOP::TAO_IOR_Property_ptr</type>
      <name>tao_TAO_IOP_TAO_IOR_Property_duplicate</name>
      <anchor>a13</anchor>
      <arglist>(TAO_IOP::TAO_IOR_Property_ptr p)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>tao_TAO_IOP_TAO_IOR_Property_release</name>
      <anchor>a14</anchor>
      <arglist>(TAO_IOP::TAO_IOR_Property_ptr p)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOP::TAO_IOR_Property_ptr</type>
      <name>tao_TAO_IOP_TAO_IOR_Property_nil</name>
      <anchor>a15</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOP::TAO_IOR_Property_ptr</type>
      <name>tao_TAO_IOP_TAO_IOR_Property_narrow</name>
      <anchor>a16</anchor>
      <arglist>(CORBA::Object *p ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Object *</type>
      <name>tao_TAO_IOP_TAO_IOR_Property_upcast</name>
      <anchor>a17</anchor>
      <arglist>(void *src)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOP::TAO_IOR_Manipulation_ptr</type>
      <name>tao_TAO_IOP_TAO_IOR_Manipulation_duplicate</name>
      <anchor>a18</anchor>
      <arglist>(TAO_IOP::TAO_IOR_Manipulation_ptr p)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>tao_TAO_IOP_TAO_IOR_Manipulation_release</name>
      <anchor>a19</anchor>
      <arglist>(TAO_IOP::TAO_IOR_Manipulation_ptr p)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOP::TAO_IOR_Manipulation_ptr</type>
      <name>tao_TAO_IOP_TAO_IOR_Manipulation_nil</name>
      <anchor>a20</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOP::TAO_IOR_Manipulation_ptr</type>
      <name>tao_TAO_IOP_TAO_IOR_Manipulation_narrow</name>
      <anchor>a21</anchor>
      <arglist>(CORBA::Object *p ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Object *</type>
      <name>tao_TAO_IOP_TAO_IOR_Manipulation_upcast</name>
      <anchor>a22</anchor>
      <arglist>(void *src)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const CORBA::Long</type>
      <name>_oc_TAO_IOP_EmptyProfileList</name>
      <anchor>a2</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const CORBA::Long</type>
      <name>_oc_TAO_IOP_NotFound</name>
      <anchor>a3</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const CORBA::Long</type>
      <name>_oc_TAO_IOP_Duplicate</name>
      <anchor>a4</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const CORBA::Long</type>
      <name>_oc_TAO_IOP_Invalid_IOR</name>
      <anchor>a5</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const CORBA::Long</type>
      <name>_oc_TAO_IOP_MultiProfileList</name>
      <anchor>a6</anchor>
      <arglist>[]</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>IORC.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/IORManipulation/</path>
    <filename>IORC_8h.html</filename>
    <namespace>TAO_IOP</namespace>
    <class kind="exception">TAO_IOP::Duplicate</class>
    <class kind="exception">TAO_IOP::EmptyProfileList</class>
    <class kind="exception">TAO_IOP::Invalid_IOR</class>
    <class kind="exception">TAO_IOP::MultiProfileList</class>
    <class kind="exception">TAO_IOP::NotFound</class>
    <class kind="interface">TAO_IOP::TAO_IOR_Manipulation</class>
    <class kind="interface">TAO_IOP::TAO_IOR_Property</class>
    <member kind="define">
      <type>#define</type>
      <name>TAO_EXPORT_MACRO</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_TAO_IOP_EMPTYPROFILELIST_CH_</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_TAO_IOP_NOTFOUND_CH_</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_TAO_IOP_DUPLICATE_CH_</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_TAO_IOP_INVALID_IOR_CH_</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_TAO_IOP_MULTIPROFILELIST_CH_</name>
      <anchor>a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_TAO_IOP_TAO_IOR_PROPERTY___PTR_CH_</name>
      <anchor>a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_TAO_IOP_TAO_IOR_PROPERTY___VAR_CH_</name>
      <anchor>a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_TAO_IOP_TAO_IOR_PROPERTY___OUT_CH_</name>
      <anchor>a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_TAO_IOP_TAO_IOR_PROPERTY_CH_</name>
      <anchor>a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_TAO_IOP_TAO_IOR_MANIPULATION___PTR_CH_</name>
      <anchor>a10</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_TAO_IOP_TAO_IOR_MANIPULATION___VAR_CH_</name>
      <anchor>a11</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_TAO_IOP_TAO_IOR_MANIPULATION___OUT_CH_</name>
      <anchor>a12</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_TAO_IOP_TAO_IOR_MANIPULATION_CH_</name>
      <anchor>a13</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>__TAO_UNBOUNDED_OBJECT_SEQUENCE_TAO_IOP_TAO_IOR_MANIPULATION_IORLIST_CH_</name>
      <anchor>a14</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_TAO_IOP_TAO_IOR_MANIPULATION_IORLIST_CH_</name>
      <anchor>a15</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_TAO_IOP_TAO_IOR_MANIPULATION_IORLIST___VAR_CH_</name>
      <anchor>a16</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_TAO_IOP_TAO_IOR_MANIPULATION_IORLIST___OUT_CH_</name>
      <anchor>a17</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>TAO_NAMESPACE_CLOSE TAO_IORManip_Export void</type>
      <name>operator&lt;&lt;=</name>
      <anchor>a18</anchor>
      <arglist>(CORBA::Any &amp;, const TAO_IOP::EmptyProfileList &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export void</type>
      <name>operator&lt;&lt;=</name>
      <anchor>a19</anchor>
      <arglist>(CORBA::Any &amp;, TAO_IOP::EmptyProfileList *)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;=</name>
      <anchor>a20</anchor>
      <arglist>(const CORBA::Any &amp;, TAO_IOP::EmptyProfileList *&amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;=</name>
      <anchor>a21</anchor>
      <arglist>(const CORBA::Any &amp;, const TAO_IOP::EmptyProfileList *&amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export void</type>
      <name>operator&lt;&lt;=</name>
      <anchor>a22</anchor>
      <arglist>(CORBA::Any &amp;, const TAO_IOP::NotFound &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export void</type>
      <name>operator&lt;&lt;=</name>
      <anchor>a23</anchor>
      <arglist>(CORBA::Any &amp;, TAO_IOP::NotFound *)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;=</name>
      <anchor>a24</anchor>
      <arglist>(const CORBA::Any &amp;, TAO_IOP::NotFound *&amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;=</name>
      <anchor>a25</anchor>
      <arglist>(const CORBA::Any &amp;, const TAO_IOP::NotFound *&amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export void</type>
      <name>operator&lt;&lt;=</name>
      <anchor>a26</anchor>
      <arglist>(CORBA::Any &amp;, const TAO_IOP::Duplicate &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export void</type>
      <name>operator&lt;&lt;=</name>
      <anchor>a27</anchor>
      <arglist>(CORBA::Any &amp;, TAO_IOP::Duplicate *)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;=</name>
      <anchor>a28</anchor>
      <arglist>(const CORBA::Any &amp;, TAO_IOP::Duplicate *&amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;=</name>
      <anchor>a29</anchor>
      <arglist>(const CORBA::Any &amp;, const TAO_IOP::Duplicate *&amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export void</type>
      <name>operator&lt;&lt;=</name>
      <anchor>a30</anchor>
      <arglist>(CORBA::Any &amp;, const TAO_IOP::Invalid_IOR &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export void</type>
      <name>operator&lt;&lt;=</name>
      <anchor>a31</anchor>
      <arglist>(CORBA::Any &amp;, TAO_IOP::Invalid_IOR *)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;=</name>
      <anchor>a32</anchor>
      <arglist>(const CORBA::Any &amp;, TAO_IOP::Invalid_IOR *&amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;=</name>
      <anchor>a33</anchor>
      <arglist>(const CORBA::Any &amp;, const TAO_IOP::Invalid_IOR *&amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export void</type>
      <name>operator&lt;&lt;=</name>
      <anchor>a34</anchor>
      <arglist>(CORBA::Any &amp;, const TAO_IOP::MultiProfileList &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export void</type>
      <name>operator&lt;&lt;=</name>
      <anchor>a35</anchor>
      <arglist>(CORBA::Any &amp;, TAO_IOP::MultiProfileList *)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;=</name>
      <anchor>a36</anchor>
      <arglist>(const CORBA::Any &amp;, TAO_IOP::MultiProfileList *&amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;=</name>
      <anchor>a37</anchor>
      <arglist>(const CORBA::Any &amp;, const TAO_IOP::MultiProfileList *&amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export CORBA::Boolean</type>
      <name>operator&lt;&lt;</name>
      <anchor>a38</anchor>
      <arglist>(TAO_OutputCDR &amp;, const TAO_IOP::EmptyProfileList &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;</name>
      <anchor>a39</anchor>
      <arglist>(TAO_InputCDR &amp;, TAO_IOP::EmptyProfileList &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export CORBA::Boolean</type>
      <name>operator&lt;&lt;</name>
      <anchor>a40</anchor>
      <arglist>(TAO_OutputCDR &amp;, const TAO_IOP::NotFound &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;</name>
      <anchor>a41</anchor>
      <arglist>(TAO_InputCDR &amp;, TAO_IOP::NotFound &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export CORBA::Boolean</type>
      <name>operator&lt;&lt;</name>
      <anchor>a42</anchor>
      <arglist>(TAO_OutputCDR &amp;, const TAO_IOP::Duplicate &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;</name>
      <anchor>a43</anchor>
      <arglist>(TAO_InputCDR &amp;, TAO_IOP::Duplicate &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export CORBA::Boolean</type>
      <name>operator&lt;&lt;</name>
      <anchor>a44</anchor>
      <arglist>(TAO_OutputCDR &amp;, const TAO_IOP::Invalid_IOR &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;</name>
      <anchor>a45</anchor>
      <arglist>(TAO_InputCDR &amp;, TAO_IOP::Invalid_IOR &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export CORBA::Boolean</type>
      <name>operator&lt;&lt;</name>
      <anchor>a46</anchor>
      <arglist>(TAO_OutputCDR &amp;, const TAO_IOP::MultiProfileList &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IORManip_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;</name>
      <anchor>a47</anchor>
      <arglist>(TAO_InputCDR &amp;, TAO_IOP::MultiProfileList &amp;)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>IORC.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/IORManipulation/</path>
    <filename>IORC_8i.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>_TAO_IOP_TAO_IOR_PROPERTY___CI_</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>__TAO_UNBOUNDED_OBJECT_SEQUENCE_TAO_IOP_TAO_IOR_MANIPULATION_IORLIST_CI_</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_TAO_IOP_TAO_IOR_MANIPULATION_IORLIST_CI_</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_TAO_IOP_TAO_IOR_MANIPULATION___CI_</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>ACE_INLINE CORBA::Boolean</type>
      <name>operator&lt;&lt;</name>
      <anchor>a4</anchor>
      <arglist>(TAO_OutputCDR &amp;strm, const TAO_IOP::EmptyProfileList &amp;_tao_aggregate)</arglist>
    </member>
    <member kind="function">
      <type>ACE_INLINE CORBA::Boolean</type>
      <name>operator&gt;&gt;</name>
      <anchor>a5</anchor>
      <arglist>(TAO_InputCDR &amp;, TAO_IOP::EmptyProfileList &amp;)</arglist>
    </member>
    <member kind="function">
      <type>ACE_INLINE CORBA::Boolean</type>
      <name>operator&lt;&lt;</name>
      <anchor>a6</anchor>
      <arglist>(TAO_OutputCDR &amp;strm, const TAO_IOP::NotFound &amp;_tao_aggregate)</arglist>
    </member>
    <member kind="function">
      <type>ACE_INLINE CORBA::Boolean</type>
      <name>operator&gt;&gt;</name>
      <anchor>a7</anchor>
      <arglist>(TAO_InputCDR &amp;, TAO_IOP::NotFound &amp;)</arglist>
    </member>
    <member kind="function">
      <type>ACE_INLINE CORBA::Boolean</type>
      <name>operator&lt;&lt;</name>
      <anchor>a8</anchor>
      <arglist>(TAO_OutputCDR &amp;strm, const TAO_IOP::Duplicate &amp;_tao_aggregate)</arglist>
    </member>
    <member kind="function">
      <type>ACE_INLINE CORBA::Boolean</type>
      <name>operator&gt;&gt;</name>
      <anchor>a9</anchor>
      <arglist>(TAO_InputCDR &amp;, TAO_IOP::Duplicate &amp;)</arglist>
    </member>
    <member kind="function">
      <type>ACE_INLINE CORBA::Boolean</type>
      <name>operator&lt;&lt;</name>
      <anchor>a10</anchor>
      <arglist>(TAO_OutputCDR &amp;strm, const TAO_IOP::Invalid_IOR &amp;_tao_aggregate)</arglist>
    </member>
    <member kind="function">
      <type>ACE_INLINE CORBA::Boolean</type>
      <name>operator&gt;&gt;</name>
      <anchor>a11</anchor>
      <arglist>(TAO_InputCDR &amp;, TAO_IOP::Invalid_IOR &amp;)</arglist>
    </member>
    <member kind="function">
      <type>ACE_INLINE CORBA::Boolean</type>
      <name>operator&lt;&lt;</name>
      <anchor>a12</anchor>
      <arglist>(TAO_OutputCDR &amp;strm, const TAO_IOP::MultiProfileList &amp;_tao_aggregate)</arglist>
    </member>
    <member kind="function">
      <type>ACE_INLINE CORBA::Boolean</type>
      <name>operator&gt;&gt;</name>
      <anchor>a13</anchor>
      <arglist>(TAO_InputCDR &amp;, TAO_IOP::MultiProfileList &amp;)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>IORManip_Loader.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/IORManipulation/</path>
    <filename>IORManip__Loader_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_IORManip_IORManip</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACE_STATIC_SVC_DEFINE</name>
      <anchor>a2</anchor>
      <arglist>(TAO_IORManip_Loader, ACE_TEXT(&quot;IORManip_Loader&quot;), ACE_SVC_OBJ_T,&amp;ACE_SVC_NAME(TAO_IORManip_Loader), ACE_Service_Type::DELETE_THIS|ACE_Service_Type::DELETE_OBJ, 0) ACE_FACTORY_DEFINE(TAO_IORManip</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_IORManip_IORManip</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>IORManip_Loader.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/IORManipulation/</path>
    <filename>IORManip__Loader_8h.html</filename>
    <class kind="class">TAO_IORManip_Loader</class>
    <member kind="define">
      <type>#define</type>
      <name>TAO_IORMANIP_SAFE_INCLUDE</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACE_STATIC_SVC_DECLARE</name>
      <anchor>a2</anchor>
      <arglist>(TAO_IORManip_Loader) ACE_FACTORY_DECLARE(TAO_IORManip</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>TAO_IORManip_Loader int</type>
      <name>TAO_Requires_IORManip_Initializer</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>IORManipulation.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/IORManipulation/</path>
    <filename>IORManipulation_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_tao_IORManipulation</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_tao_IORManipulation</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>IORManipulation.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/IORManipulation/</path>
    <filename>IORManipulation_8h.html</filename>
    <class kind="class">TAO_IOR_Manipulation_impl</class>
  </compound>
  <compound kind="class">
    <name>TAO_IOR_Manipulation_impl</name>
    <filename>classTAO__IOR__Manipulation__impl.html</filename>
    <base>TAO_IOP::TAO_IOR_Manipulation</base>
    <base>TAO_Local_RefCounted_Object</base>
    <member kind="function">
      <type></type>
      <name>TAO_IOR_Manipulation_impl</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_IOR_Manipulation_impl</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Object_ptr</type>
      <name>merge_iors</name>
      <anchor>a2</anchor>
      <arglist>(const TAO_IOP::TAO_IOR_Manipulation::IORList &amp;iors ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Object_ptr</type>
      <name>add_profiles</name>
      <anchor>a3</anchor>
      <arglist>(CORBA::Object_ptr ior1, CORBA::Object_ptr ior2 ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Object_ptr</type>
      <name>remove_profiles</name>
      <anchor>a4</anchor>
      <arglist>(CORBA::Object_ptr ior1, CORBA::Object_ptr ior2 ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>set_property</name>
      <anchor>a5</anchor>
      <arglist>(TAO_IOP::TAO_IOR_Property_ptr prop, CORBA::Object_ptr ior ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>set_primary</name>
      <anchor>a6</anchor>
      <arglist>(TAO_IOP::TAO_IOR_Property_ptr prop, CORBA::Object_ptr ior1, CORBA::Object_ptr ior2 ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Object_ptr</type>
      <name>get_primary</name>
      <anchor>a7</anchor>
      <arglist>(TAO_IOP::TAO_IOR_Property_ptr prop, CORBA::Object_ptr ior ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>is_primary_set</name>
      <anchor>a8</anchor>
      <arglist>(TAO_IOP::TAO_IOR_Property_ptr prop, CORBA::Object_ptr ior ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::ULong</type>
      <name>is_in_ior</name>
      <anchor>a9</anchor>
      <arglist>(CORBA::Object_ptr ior1, CORBA::Object_ptr ior2 ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::ULong</type>
      <name>get_profile_count</name>
      <anchor>a10</anchor>
      <arglist>(CORBA::Object_ptr ior ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_IORManip_Loader</name>
    <filename>classTAO__IORManip__Loader.html</filename>
    <base>TAO_Object_Loader</base>
    <member kind="function">
      <type></type>
      <name>TAO_IORManip_Loader</name>
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
  <compound kind="namespace">
    <name>TAO_IOP</name>
    <filename>namespaceTAO__IOP.html</filename>
    <class kind="class">TAO_IOP::TAO_IOR_Manipulation::IORList_out</class>
    <class kind="class">TAO_IOP::TAO_IOR_Manipulation::IORList_var</class>
    <class kind="class">TAO_IOP::TAO_IOR_Manipulation::IORList</class>
    <class kind="class">TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList</class>
    <class kind="exception">TAO_IOP::Duplicate</class>
    <class kind="exception">TAO_IOP::EmptyProfileList</class>
    <class kind="exception">TAO_IOP::Invalid_IOR</class>
    <class kind="exception">TAO_IOP::MultiProfileList</class>
    <class kind="exception">TAO_IOP::NotFound</class>
    <class kind="interface">TAO_IOP::TAO_IOR_Manipulation</class>
    <class kind="class">TAO_IOP::TAO_IOR_Manipulation_out</class>
    <class kind="class">TAO_IOP::TAO_IOR_Manipulation_var</class>
    <class kind="interface">TAO_IOP::TAO_IOR_Property</class>
    <class kind="class">TAO_IOP::TAO_IOR_Property_out</class>
    <class kind="class">TAO_IOP::TAO_IOR_Property_var</class>
    <member kind="typedef">
      <type>TAO_IOR_Property *</type>
      <name>TAO_IOR_Property_ptr</name>
      <anchor>a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TAO_IOR_Manipulation *</type>
      <name>TAO_IOR_Manipulation_ptr</name>
      <anchor>a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>TAO_NAMESPACE_STORAGE_CLASS::CORBA::TypeCode_ptr</type>
      <name>_tc_EmptyProfileList</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>TAO_NAMESPACE_STORAGE_CLASS::CORBA::TypeCode_ptr</type>
      <name>_tc_NotFound</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>TAO_NAMESPACE_STORAGE_CLASS::CORBA::TypeCode_ptr</type>
      <name>_tc_Duplicate</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>TAO_NAMESPACE_STORAGE_CLASS::CORBA::TypeCode_ptr</type>
      <name>_tc_Invalid_IOR</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>TAO_NAMESPACE_STORAGE_CLASS::CORBA::TypeCode_ptr</type>
      <name>_tc_MultiProfileList</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_IOP::TAO_IOR_Manipulation::IORList_out</name>
    <filename>classTAO__IOP_1_1TAO__IOR__Manipulation_1_1IORList__out.html</filename>
    <member kind="function">
      <type></type>
      <name>IORList_out</name>
      <anchor>a0</anchor>
      <arglist>(IORList *&amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>IORList_out</name>
      <anchor>a1</anchor>
      <arglist>(IORList_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>IORList_out</name>
      <anchor>a2</anchor>
      <arglist>(const IORList_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>IORList_out &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const IORList_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>IORList_out &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(IORList *)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator IORList *&amp;</name>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IORList *&amp;</type>
      <name>ptr</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>IORList *</type>
      <name>operator-&gt;</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_Object_Manager&lt; CORBA::Object, CORBA::Object_var &gt;</type>
      <name>operator[]</name>
      <anchor>a8</anchor>
      <arglist>(CORBA::ULong index)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>operator=</name>
      <anchor>c0</anchor>
      <arglist>(const IORList_var &amp;)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>IORList *&amp;</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_IOP::TAO_IOR_Manipulation::IORList_var</name>
    <filename>classTAO__IOP_1_1TAO__IOR__Manipulation_1_1IORList__var.html</filename>
    <member kind="function">
      <type></type>
      <name>IORList_var</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>IORList_var</name>
      <anchor>a1</anchor>
      <arglist>(IORList *)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>IORList_var</name>
      <anchor>a2</anchor>
      <arglist>(const IORList_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~IORList_var</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>IORList_var &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(IORList *)</arglist>
    </member>
    <member kind="function">
      <type>IORList_var &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(const IORList_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>IORList *</type>
      <name>operator-&gt;</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const IORList *</type>
      <name>operator-&gt;</name>
      <anchor>a7</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator const IORList &amp;</name>
      <anchor>a8</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator IORList &amp;</name>
      <anchor>a9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator IORList &amp;</name>
      <anchor>a10</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator IORList *&amp;</name>
      <anchor>a11</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>TAO_Object_Manager&lt; CORBA::Object, CORBA::Object_var &gt;</type>
      <name>operator[]</name>
      <anchor>a12</anchor>
      <arglist>(CORBA::ULong index)</arglist>
    </member>
    <member kind="function">
      <type>const IORList &amp;</type>
      <name>in</name>
      <anchor>a13</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>IORList &amp;</type>
      <name>inout</name>
      <anchor>a14</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>IORList *&amp;</type>
      <name>out</name>
      <anchor>a15</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>IORList *</type>
      <name>_retn</name>
      <anchor>a16</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>IORList *</type>
      <name>ptr</name>
      <anchor>a17</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>IORList *</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_IOP::TAO_IOR_Manipulation::IORList</name>
    <filename>classTAO__IOP_1_1TAO__IOR__Manipulation_1_1IORList.html</filename>
    <base>TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList</base>
    <member kind="typedef">
      <type>IORList_var</type>
      <name>_var_type</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>IORList</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>IORList</name>
      <anchor>a1</anchor>
      <arglist>(CORBA::ULong max)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>IORList</name>
      <anchor>a2</anchor>
      <arglist>(CORBA::ULong max, CORBA::ULong length, CORBA::Object_ptr *buffer, CORBA::Boolean release=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>IORList</name>
      <anchor>a3</anchor>
      <arglist>(const IORList &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~IORList</name>
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
    <name>TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList</name>
    <filename>classTAO__IOP_1_1TAO__IOR__Manipulation_1_1__TAO__Unbounded__Object__Sequence__TAO__IOP__TAO__IOR__Manipulation__IORList.html</filename>
    <base>TAO_Unbounded_Base_Sequence</base>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList</name>
      <anchor>a1</anchor>
      <arglist>(CORBA::ULong maximum)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList</name>
      <anchor>a2</anchor>
      <arglist>(CORBA::ULong maximum, CORBA::ULong length, CORBA::Object **value, CORBA::Boolean release=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList</name>
      <anchor>a3</anchor>
      <arglist>(const _TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(const _TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList &amp;rhs)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_Object_Manager&lt; CORBA::Object, CORBA::Object_var &gt;</type>
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
      <type>CORBA::Object **</type>
      <name>get_buffer</name>
      <anchor>a9</anchor>
      <arglist>(CORBA::Boolean orphan=0)</arglist>
    </member>
    <member kind="function">
      <type>const CORBA::Object **</type>
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
      <type>CORBA::Object **</type>
      <name>allocbuf</name>
      <anchor>d0</anchor>
      <arglist>(CORBA::ULong nelems)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>freebuf</name>
      <anchor>d1</anchor>
      <arglist>(CORBA::Object **buffer)</arglist>
    </member>
  </compound>
  <compound kind="exception">
    <name>TAO_IOP::Duplicate</name>
    <filename>exceptionTAO__IOP_1_1Duplicate.html</filename>
    <member kind="function">
      <type></type>
      <name>Duplicate</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Duplicate</name>
      <anchor>a1</anchor>
      <arglist>(const Duplicate &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~Duplicate</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>Duplicate &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const Duplicate &amp;)</arglist>
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
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::TypeCode_ptr</type>
      <name>_type</name>
      <anchor>a8</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>_tao_any_destructor</name>
      <anchor>d0</anchor>
      <arglist>(void *)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>Duplicate *</type>
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
  <compound kind="exception">
    <name>TAO_IOP::EmptyProfileList</name>
    <filename>exceptionTAO__IOP_1_1EmptyProfileList.html</filename>
    <member kind="function">
      <type></type>
      <name>EmptyProfileList</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>EmptyProfileList</name>
      <anchor>a1</anchor>
      <arglist>(const EmptyProfileList &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~EmptyProfileList</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>EmptyProfileList &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const EmptyProfileList &amp;)</arglist>
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
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::TypeCode_ptr</type>
      <name>_type</name>
      <anchor>a8</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>_tao_any_destructor</name>
      <anchor>d0</anchor>
      <arglist>(void *)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>EmptyProfileList *</type>
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
  <compound kind="exception">
    <name>TAO_IOP::Invalid_IOR</name>
    <filename>exceptionTAO__IOP_1_1Invalid__IOR.html</filename>
    <member kind="function">
      <type></type>
      <name>Invalid_IOR</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>Invalid_IOR</name>
      <anchor>a1</anchor>
      <arglist>(const Invalid_IOR &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~Invalid_IOR</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>Invalid_IOR &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const Invalid_IOR &amp;)</arglist>
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
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::TypeCode_ptr</type>
      <name>_type</name>
      <anchor>a8</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>_tao_any_destructor</name>
      <anchor>d0</anchor>
      <arglist>(void *)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>Invalid_IOR *</type>
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
  <compound kind="exception">
    <name>TAO_IOP::MultiProfileList</name>
    <filename>exceptionTAO__IOP_1_1MultiProfileList.html</filename>
    <member kind="function">
      <type></type>
      <name>MultiProfileList</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>MultiProfileList</name>
      <anchor>a1</anchor>
      <arglist>(const MultiProfileList &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~MultiProfileList</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>MultiProfileList &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const MultiProfileList &amp;)</arglist>
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
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::TypeCode_ptr</type>
      <name>_type</name>
      <anchor>a8</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>_tao_any_destructor</name>
      <anchor>d0</anchor>
      <arglist>(void *)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>MultiProfileList *</type>
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
  <compound kind="exception">
    <name>TAO_IOP::NotFound</name>
    <filename>exceptionTAO__IOP_1_1NotFound.html</filename>
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
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::TypeCode_ptr</type>
      <name>_type</name>
      <anchor>a8</anchor>
      <arglist>(void) const</arglist>
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
    <name>TAO_IOP::TAO_IOR_Manipulation</name>
    <filename>interfaceTAO__IOP_1_1TAO__IOR__Manipulation.html</filename>
    <base virtualness="virtual">CORBA_Object</base>
    <member kind="typedef">
      <type>sequence&lt; Object &gt;</type>
      <name>IORList</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TAO_IOR_Manipulation_ptr</type>
      <name>_ptr_type</name>
      <anchor>s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TAO_IOR_Manipulation_var</type>
      <name>_var_type</name>
      <anchor>s2</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>Object</type>
      <name>merge_iors</name>
      <anchor>a0</anchor>
      <arglist>(in IORList iors)</arglist>
    </member>
    <member kind="function">
      <type>Object</type>
      <name>add_profiles</name>
      <anchor>a1</anchor>
      <arglist>(in Object ior1, in Object ior2)</arglist>
    </member>
    <member kind="function">
      <type>Object</type>
      <name>remove_profiles</name>
      <anchor>a2</anchor>
      <arglist>(in Object ior1, in Object ior2)</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>set_property</name>
      <anchor>a3</anchor>
      <arglist>(in TAO_IOR_Property prop, in Object ior)</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>set_primary</name>
      <anchor>a4</anchor>
      <arglist>(in TAO_IOR_Property prop, in Object ior1, in Object ior2)</arglist>
    </member>
    <member kind="function">
      <type>Object</type>
      <name>get_primary</name>
      <anchor>a5</anchor>
      <arglist>(in TAO_IOR_Property prop, in Object ior)</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>is_primary_set</name>
      <anchor>a6</anchor>
      <arglist>(in TAO_IOR_Property prop, in Object ior)</arglist>
    </member>
    <member kind="function">
      <type>unsigned long</type>
      <name>is_in_ior</name>
      <anchor>a7</anchor>
      <arglist>(in Object ior1, in Object ior2)</arglist>
    </member>
    <member kind="function">
      <type>unsigned long</type>
      <name>get_profile_count</name>
      <anchor>a8</anchor>
      <arglist>(in Object ior)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Object_ptr</type>
      <name>merge_iors</name>
      <anchor>a9</anchor>
      <arglist>(const TAO_IOP::TAO_IOR_Manipulation::IORList &amp;iors ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Object_ptr</type>
      <name>add_profiles</name>
      <anchor>a10</anchor>
      <arglist>(CORBA::Object_ptr ior1, CORBA::Object_ptr ior2 ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Object_ptr</type>
      <name>remove_profiles</name>
      <anchor>a11</anchor>
      <arglist>(CORBA::Object_ptr ior1, CORBA::Object_ptr ior2 ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Boolean</type>
      <name>set_property</name>
      <anchor>a12</anchor>
      <arglist>(TAO_IOP::TAO_IOR_Property_ptr prop, CORBA::Object_ptr ior ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Boolean</type>
      <name>set_primary</name>
      <anchor>a13</anchor>
      <arglist>(TAO_IOP::TAO_IOR_Property_ptr prop, CORBA::Object_ptr ior1, CORBA::Object_ptr ior2 ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Object_ptr</type>
      <name>get_primary</name>
      <anchor>a14</anchor>
      <arglist>(TAO_IOP::TAO_IOR_Property_ptr prop, CORBA::Object_ptr ior ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Boolean</type>
      <name>is_primary_set</name>
      <anchor>a15</anchor>
      <arglist>(TAO_IOP::TAO_IOR_Property_ptr prop, CORBA::Object_ptr ior ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::ULong</type>
      <name>is_in_ior</name>
      <anchor>a16</anchor>
      <arglist>(CORBA::Object_ptr ior1, CORBA::Object_ptr ior2 ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::ULong</type>
      <name>get_profile_count</name>
      <anchor>a17</anchor>
      <arglist>(CORBA::Object_ptr ior ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
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
      <type>TAO_IOR_Manipulation_ptr</type>
      <name>_duplicate</name>
      <anchor>d0</anchor>
      <arglist>(TAO_IOR_Manipulation_ptr obj)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>TAO_IOR_Manipulation_ptr</type>
      <name>_narrow</name>
      <anchor>d1</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>TAO_IOR_Manipulation_ptr</type>
      <name>_unchecked_narrow</name>
      <anchor>d2</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>TAO_IOR_Manipulation_ptr</type>
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
      <name>TAO_IOR_Manipulation</name>
      <anchor>b0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_IOR_Manipulation</name>
      <anchor>b1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>TAO_IOR_Manipulation</name>
      <anchor>c0</anchor>
      <arglist>(const TAO_IOR_Manipulation &amp;)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const TAO_IOR_Manipulation &amp;)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_IOP::TAO_IOR_Manipulation::IORList_out</name>
    <filename>classTAO__IOP_1_1TAO__IOR__Manipulation_1_1IORList__out.html</filename>
    <member kind="function">
      <type></type>
      <name>IORList_out</name>
      <anchor>a0</anchor>
      <arglist>(IORList *&amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>IORList_out</name>
      <anchor>a1</anchor>
      <arglist>(IORList_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>IORList_out</name>
      <anchor>a2</anchor>
      <arglist>(const IORList_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>IORList_out &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const IORList_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>IORList_out &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(IORList *)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator IORList *&amp;</name>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>IORList *&amp;</type>
      <name>ptr</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>IORList *</type>
      <name>operator-&gt;</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_Object_Manager&lt; CORBA::Object, CORBA::Object_var &gt;</type>
      <name>operator[]</name>
      <anchor>a8</anchor>
      <arglist>(CORBA::ULong index)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>operator=</name>
      <anchor>c0</anchor>
      <arglist>(const IORList_var &amp;)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>IORList *&amp;</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_IOP::TAO_IOR_Manipulation::IORList_var</name>
    <filename>classTAO__IOP_1_1TAO__IOR__Manipulation_1_1IORList__var.html</filename>
    <member kind="function">
      <type></type>
      <name>IORList_var</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>IORList_var</name>
      <anchor>a1</anchor>
      <arglist>(IORList *)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>IORList_var</name>
      <anchor>a2</anchor>
      <arglist>(const IORList_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~IORList_var</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>IORList_var &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(IORList *)</arglist>
    </member>
    <member kind="function">
      <type>IORList_var &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(const IORList_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>IORList *</type>
      <name>operator-&gt;</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const IORList *</type>
      <name>operator-&gt;</name>
      <anchor>a7</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator const IORList &amp;</name>
      <anchor>a8</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator IORList &amp;</name>
      <anchor>a9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator IORList &amp;</name>
      <anchor>a10</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator IORList *&amp;</name>
      <anchor>a11</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>TAO_Object_Manager&lt; CORBA::Object, CORBA::Object_var &gt;</type>
      <name>operator[]</name>
      <anchor>a12</anchor>
      <arglist>(CORBA::ULong index)</arglist>
    </member>
    <member kind="function">
      <type>const IORList &amp;</type>
      <name>in</name>
      <anchor>a13</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>IORList &amp;</type>
      <name>inout</name>
      <anchor>a14</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>IORList *&amp;</type>
      <name>out</name>
      <anchor>a15</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>IORList *</type>
      <name>_retn</name>
      <anchor>a16</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>IORList *</type>
      <name>ptr</name>
      <anchor>a17</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>IORList *</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_IOP::TAO_IOR_Manipulation::IORList</name>
    <filename>classTAO__IOP_1_1TAO__IOR__Manipulation_1_1IORList.html</filename>
    <base>TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList</base>
    <member kind="typedef">
      <type>IORList_var</type>
      <name>_var_type</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>IORList</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>IORList</name>
      <anchor>a1</anchor>
      <arglist>(CORBA::ULong max)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>IORList</name>
      <anchor>a2</anchor>
      <arglist>(CORBA::ULong max, CORBA::ULong length, CORBA::Object_ptr *buffer, CORBA::Boolean release=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>IORList</name>
      <anchor>a3</anchor>
      <arglist>(const IORList &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~IORList</name>
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
    <name>TAO_IOP::TAO_IOR_Manipulation::_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList</name>
    <filename>classTAO__IOP_1_1TAO__IOR__Manipulation_1_1__TAO__Unbounded__Object__Sequence__TAO__IOP__TAO__IOR__Manipulation__IORList.html</filename>
    <base>TAO_Unbounded_Base_Sequence</base>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList</name>
      <anchor>a1</anchor>
      <arglist>(CORBA::ULong maximum)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList</name>
      <anchor>a2</anchor>
      <arglist>(CORBA::ULong maximum, CORBA::ULong length, CORBA::Object **value, CORBA::Boolean release=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList</name>
      <anchor>a3</anchor>
      <arglist>(const _TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(const _TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList &amp;rhs)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~_TAO_Unbounded_Object_Sequence_TAO_IOP_TAO_IOR_Manipulation_IORList</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_Object_Manager&lt; CORBA::Object, CORBA::Object_var &gt;</type>
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
      <type>CORBA::Object **</type>
      <name>get_buffer</name>
      <anchor>a9</anchor>
      <arglist>(CORBA::Boolean orphan=0)</arglist>
    </member>
    <member kind="function">
      <type>const CORBA::Object **</type>
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
      <type>CORBA::Object **</type>
      <name>allocbuf</name>
      <anchor>d0</anchor>
      <arglist>(CORBA::ULong nelems)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>freebuf</name>
      <anchor>d1</anchor>
      <arglist>(CORBA::Object **buffer)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_IOP::TAO_IOR_Manipulation_out</name>
    <filename>classTAO__IOP_1_1TAO__IOR__Manipulation__out.html</filename>
    <member kind="function">
      <type></type>
      <name>TAO_IOR_Manipulation_out</name>
      <anchor>a0</anchor>
      <arglist>(TAO_IOR_Manipulation_ptr &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_IOR_Manipulation_out</name>
      <anchor>a1</anchor>
      <arglist>(TAO_IOR_Manipulation_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_IOR_Manipulation_out</name>
      <anchor>a2</anchor>
      <arglist>(const TAO_IOR_Manipulation_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOR_Manipulation_out &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const TAO_IOR_Manipulation_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOR_Manipulation_out &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(const TAO_IOR_Manipulation_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOR_Manipulation_out &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(TAO_IOR_Manipulation_ptr)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator TAO_IOR_Manipulation_ptr &amp;</name>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOR_Manipulation_ptr &amp;</type>
      <name>ptr</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOR_Manipulation_ptr</type>
      <name>operator-&gt;</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_IOR_Manipulation_ptr &amp;</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_IOP::TAO_IOR_Manipulation_var</name>
    <filename>classTAO__IOP_1_1TAO__IOR__Manipulation__var.html</filename>
    <base>TAO_Base_var</base>
    <member kind="function">
      <type></type>
      <name>TAO_IOR_Manipulation_var</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_IOR_Manipulation_var</name>
      <anchor>a1</anchor>
      <arglist>(TAO_IOR_Manipulation_ptr p)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_IOR_Manipulation_var</name>
      <anchor>a2</anchor>
      <arglist>(const TAO_IOR_Manipulation_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_IOR_Manipulation_var</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOR_Manipulation_var &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(TAO_IOR_Manipulation_ptr)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOR_Manipulation_var &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(const TAO_IOR_Manipulation_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOR_Manipulation_ptr</type>
      <name>operator-&gt;</name>
      <anchor>a6</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator const TAO_IOR_Manipulation_ptr &amp;</name>
      <anchor>a7</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator TAO_IOR_Manipulation_ptr &amp;</name>
      <anchor>a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOR_Manipulation_ptr</type>
      <name>in</name>
      <anchor>a9</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOR_Manipulation_ptr &amp;</type>
      <name>inout</name>
      <anchor>a10</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOR_Manipulation_ptr &amp;</type>
      <name>out</name>
      <anchor>a11</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOR_Manipulation_ptr</type>
      <name>_retn</name>
      <anchor>a12</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOR_Manipulation_ptr</type>
      <name>ptr</name>
      <anchor>a13</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>TAO_IOR_Manipulation_ptr</type>
      <name>tao_duplicate</name>
      <anchor>d0</anchor>
      <arglist>(TAO_IOR_Manipulation_ptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>tao_release</name>
      <anchor>d1</anchor>
      <arglist>(TAO_IOR_Manipulation_ptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>TAO_IOR_Manipulation_ptr</type>
      <name>tao_nil</name>
      <anchor>d2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>TAO_IOR_Manipulation_ptr</type>
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
      <name>TAO_IOR_Manipulation_var</name>
      <anchor>c0</anchor>
      <arglist>(const TAO_Base_var &amp;rhs)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>TAO_IOR_Manipulation_var &amp;</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const TAO_Base_var &amp;rhs)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_IOR_Manipulation_ptr</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>TAO_IOP::TAO_IOR_Property</name>
    <filename>interfaceTAO__IOP_1_1TAO__IOR__Property.html</filename>
    <base virtualness="virtual">CORBA_Object</base>
    <member kind="typedef">
      <type>TAO_IOR_Property_ptr</type>
      <name>_ptr_type</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TAO_IOR_Property_var</type>
      <name>_var_type</name>
      <anchor>s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>set_property</name>
      <anchor>a0</anchor>
      <arglist>(in Object ior)</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>set_primary</name>
      <anchor>a1</anchor>
      <arglist>(in Object ior1, in Object ior2)</arglist>
    </member>
    <member kind="function">
      <type>Object</type>
      <name>get_primary</name>
      <anchor>a2</anchor>
      <arglist>(in Object ior)</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>is_primary_set</name>
      <anchor>a3</anchor>
      <arglist>(in Object ior)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Boolean</type>
      <name>set_property</name>
      <anchor>a4</anchor>
      <arglist>(CORBA::Object_ptr ior ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Boolean</type>
      <name>set_primary</name>
      <anchor>a5</anchor>
      <arglist>(CORBA::Object_ptr ior1, CORBA::Object_ptr ior2 ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Object_ptr</type>
      <name>get_primary</name>
      <anchor>a6</anchor>
      <arglist>(CORBA::Object_ptr ior ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Boolean</type>
      <name>is_primary_set</name>
      <anchor>a7</anchor>
      <arglist>(CORBA::Object_ptr ior ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
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
      <type>TAO_IOR_Property_ptr</type>
      <name>_duplicate</name>
      <anchor>d0</anchor>
      <arglist>(TAO_IOR_Property_ptr obj)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>TAO_IOR_Property_ptr</type>
      <name>_narrow</name>
      <anchor>d1</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>TAO_IOR_Property_ptr</type>
      <name>_unchecked_narrow</name>
      <anchor>d2</anchor>
      <arglist>(CORBA::Object_ptr obj ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>TAO_IOR_Property_ptr</type>
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
      <name>TAO_IOR_Property</name>
      <anchor>b0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_IOR_Property</name>
      <anchor>b1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>TAO_IOR_Property</name>
      <anchor>c0</anchor>
      <arglist>(const TAO_IOR_Property &amp;)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const TAO_IOR_Property &amp;)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_IOP::TAO_IOR_Property_out</name>
    <filename>classTAO__IOP_1_1TAO__IOR__Property__out.html</filename>
    <member kind="function">
      <type></type>
      <name>TAO_IOR_Property_out</name>
      <anchor>a0</anchor>
      <arglist>(TAO_IOR_Property_ptr &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_IOR_Property_out</name>
      <anchor>a1</anchor>
      <arglist>(TAO_IOR_Property_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_IOR_Property_out</name>
      <anchor>a2</anchor>
      <arglist>(const TAO_IOR_Property_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOR_Property_out &amp;</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(const TAO_IOR_Property_out &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOR_Property_out &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(const TAO_IOR_Property_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOR_Property_out &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(TAO_IOR_Property_ptr)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator TAO_IOR_Property_ptr &amp;</name>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOR_Property_ptr &amp;</type>
      <name>ptr</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOR_Property_ptr</type>
      <name>operator-&gt;</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_IOR_Property_ptr &amp;</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_IOP::TAO_IOR_Property_var</name>
    <filename>classTAO__IOP_1_1TAO__IOR__Property__var.html</filename>
    <base>TAO_Base_var</base>
    <member kind="function">
      <type></type>
      <name>TAO_IOR_Property_var</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_IOR_Property_var</name>
      <anchor>a1</anchor>
      <arglist>(TAO_IOR_Property_ptr p)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_IOR_Property_var</name>
      <anchor>a2</anchor>
      <arglist>(const TAO_IOR_Property_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_IOR_Property_var</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOR_Property_var &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(TAO_IOR_Property_ptr)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOR_Property_var &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(const TAO_IOR_Property_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOR_Property_ptr</type>
      <name>operator-&gt;</name>
      <anchor>a6</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator const TAO_IOR_Property_ptr &amp;</name>
      <anchor>a7</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator TAO_IOR_Property_ptr &amp;</name>
      <anchor>a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOR_Property_ptr</type>
      <name>in</name>
      <anchor>a9</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOR_Property_ptr &amp;</type>
      <name>inout</name>
      <anchor>a10</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOR_Property_ptr &amp;</type>
      <name>out</name>
      <anchor>a11</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOR_Property_ptr</type>
      <name>_retn</name>
      <anchor>a12</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_IOR_Property_ptr</type>
      <name>ptr</name>
      <anchor>a13</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>TAO_IOR_Property_ptr</type>
      <name>tao_duplicate</name>
      <anchor>d0</anchor>
      <arglist>(TAO_IOR_Property_ptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>tao_release</name>
      <anchor>d1</anchor>
      <arglist>(TAO_IOR_Property_ptr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>TAO_IOR_Property_ptr</type>
      <name>tao_nil</name>
      <anchor>d2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>TAO_IOR_Property_ptr</type>
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
      <name>TAO_IOR_Property_var</name>
      <anchor>c0</anchor>
      <arglist>(const TAO_Base_var &amp;rhs)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>TAO_IOR_Property_var &amp;</type>
      <name>operator=</name>
      <anchor>c1</anchor>
      <arglist>(const TAO_Base_var &amp;rhs)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_IOR_Property_ptr</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
</tagfile>
