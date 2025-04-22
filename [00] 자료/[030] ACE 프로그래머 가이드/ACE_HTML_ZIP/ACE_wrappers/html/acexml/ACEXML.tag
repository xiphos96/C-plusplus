<?xml version='1.0' encoding='ISO-8859-1' standalone='yes'?>
<tagfile>
  <compound kind="page">
    <filename>index</filename>
    <title>ACEXML - A Small and Portable XML Parser</title>
    <name>index</name>
    <docanchor>acexml_others</docanchor>
    <docanchor>acexml_synopsis</docanchor>
    <docanchor>acexml_features</docanchor>
  </compound>
  <compound kind="file">
    <name>ACEXML_Export.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>ACEXML__Export_8h.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_HAS_DLL</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_Export</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_SINGLETON_DECLARATION</name>
      <anchor>a2</anchor>
      <arglist>(T)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_SINGLETON_DECLARE</name>
      <anchor>a3</anchor>
      <arglist>(SINGLETON_TYPE, CLASS, LOCK)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Attributes.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>Attributes_8h.html</filename>
    <class kind="class">ACEXML_Attributes</class>
  </compound>
  <compound kind="file">
    <name>Attributes_Def_Builder.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>Attributes__Def__Builder_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>Attributes_Def_Builder.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>Attributes__Def__Builder_8h.html</filename>
    <class kind="class">ACEXML_Attribute_Def_Builder</class>
    <class kind="class">ACEXML_Attributes_Def_Builder</class>
  </compound>
  <compound kind="file">
    <name>AttributesImpl.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>AttributesImpl_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>AttributesImpl.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>AttributesImpl_8h.html</filename>
    <class kind="class">ACEXML_Attribute</class>
    <class kind="class">ACEXML_AttributesImpl</class>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_AttributesImpl_Default_Size</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Array&lt; ACEXML_Attribute &gt;</type>
      <name>ACEXML_Attribute_Array</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>AttributesImpl.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>AttributesImpl_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>bugs.txt</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/docs/</path>
    <filename>bugs_8txt.html</filename>
  </compound>
  <compound kind="file">
    <name>CharStream.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>CharStream_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>CharStream.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>CharStream_8h.html</filename>
    <class kind="class">ACEXML_CharStream</class>
  </compound>
  <compound kind="file">
    <name>ContentHandler.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>ContentHandler_8h.html</filename>
    <class kind="class">ACEXML_ContentHandler</class>
  </compound>
  <compound kind="file">
    <name>Debug_Attributes_Builder.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/parser/debug_validator/</path>
    <filename>Debug__Attributes__Builder_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>Debug_Attributes_Builder.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/parser/debug_validator/</path>
    <filename>Debug__Attributes__Builder_8h.html</filename>
    <class kind="class">ACEXML_Debug_Attribute_Builder</class>
    <class kind="class">ACEXML_Debug_Attributes_Builder</class>
    <member kind="typedef">
      <type>ACE_Unbounded_Queue&lt; ACEXML_String &gt;</type>
      <name>ACEXML_STRING_QUEUE</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Unbounded_Queue_Iterator&lt; ACEXML_String &gt;</type>
      <name>ACEXML_STRING_QUEUE_ITERATOR</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Hash_Map_Entry&lt; ACEXML_String, ACEXML_Debug_Attribute_Builder &gt;</type>
      <name>ACEXML_ATT_MAP_ENTRY</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Hash_Map_Manager_Ex&lt; ACEXML_String, ACEXML_Debug_Attribute_Builder, ACE_Hash&lt; ACEXML_String &gt;, ACE_Equal_To&lt; ACEXML_String &gt;, ACE_Null_Mutex &gt;</type>
      <name>ACEXML_ATT_MAP</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Hash_Map_Iterator_Ex&lt; ACEXML_String, ACEXML_Debug_Attribute_Builder, ACE_Hash&lt; ACEXML_String &gt;, ACE_Equal_To&lt; ACEXML_String &gt;, ACE_Null_Mutex &gt;</type>
      <name>ACEXML_ATT_MAP_ITER</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Hash_Map_Reverse_Iterator_Ex&lt; ACEXML_String, ACEXML_Debug_Attribute_Builder, ACE_Hash&lt; ACEXML_String &gt;, ACE_Equal_To&lt; ACEXML_String &gt;, ACE_Null_Mutex &gt;</type>
      <name>ACEXML_ATT_MAP_REVERSE_ITER</name>
      <anchor>a5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Debug_DTD_Manager.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/parser/debug_validator/</path>
    <filename>Debug__DTD__Manager_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>Debug_DTD_Manager.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/parser/debug_validator/</path>
    <filename>Debug__DTD__Manager_8h.html</filename>
    <class kind="class">ACEXML_Debug_DTD_Manager</class>
  </compound>
  <compound kind="file">
    <name>Debug_DTD_Manager_Export.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/parser/debug_validator/</path>
    <filename>Debug__DTD__Manager__Export_8h.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_DEBUG_DTD_MANAGER_HAS_DLL</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_DEBUG_DTD_MANAGER_Export</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_DEBUG_DTD_MANAGER_SINGLETON_DECLARATION</name>
      <anchor>a2</anchor>
      <arglist>(T)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_DEBUG_DTD_MANAGER_SINGLETON_DECLARE</name>
      <anchor>a3</anchor>
      <arglist>(SINGLETON_TYPE, CLASS, LOCK)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Debug_Element_Builder.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/parser/debug_validator/</path>
    <filename>Debug__Element__Builder_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>Debug_Element_Builder.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/parser/debug_validator/</path>
    <filename>Debug__Element__Builder_8h.html</filename>
    <class kind="class">ACEXML_Debug_Element_Builder</class>
  </compound>
  <compound kind="file">
    <name>DefaultHandler.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>DefaultHandler_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>DefaultHandler.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>DefaultHandler_8h.html</filename>
    <class kind="class">ACEXML_DefaultHandler</class>
  </compound>
  <compound kind="file">
    <name>DefaultHandler.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>DefaultHandler_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>DTD_Manager.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>DTD__Manager_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>DTD_Manager.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>DTD__Manager_8h.html</filename>
    <class kind="class">ACEXML_DTD_Manager</class>
  </compound>
  <compound kind="file">
    <name>DTDHandler.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>DTDHandler_8h.html</filename>
    <class kind="class">ACEXML_DTDHandler</class>
  </compound>
  <compound kind="file">
    <name>Element_Def_Builder.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>Element__Def__Builder_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>Element_Def_Builder.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>Element__Def__Builder_8h.html</filename>
    <class kind="class">ACEXML_Element_Def_Builder</class>
  </compound>
  <compound kind="file">
    <name>Element_Tree.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/parser/debug_validator/</path>
    <filename>Element__Tree_8cpp.html</filename>
    <member kind="function">
      <type></type>
      <name>ACE_ALLOC_HOOK_DEFINE</name>
      <anchor>a0</anchor>
      <arglist>(ACEXML_Element_Tree_Node) void ACEXML_Element_Tree_Name_Node</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Element_Tree.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/parser/debug_validator/</path>
    <filename>Element__Tree_8h.html</filename>
    <class kind="class">ACEXML_Element_Tree_List_Node</class>
    <class kind="class">ACEXML_Element_Tree_List_Stack</class>
    <class kind="class">ACEXML_Element_Tree_Name_Node</class>
    <class kind="class">ACEXML_Element_Tree_Node</class>
  </compound>
  <compound kind="file">
    <name>Element_Tree.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/parser/debug_validator/</path>
    <filename>Element__Tree_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>Encoding.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>Encoding_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>Encoding.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>Encoding_8h.html</filename>
    <class kind="class">ACEXML_Encoding</class>
  </compound>
  <compound kind="file">
    <name>Entity_Manager.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/parser/parser/</path>
    <filename>Entity__Manager_8cpp.html</filename>
    <member kind="variable" static="yes">
      <type>const ACEXML_Char</type>
      <name>amp_name</name>
      <anchor>a0</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const ACEXML_Char</type>
      <name>amp_value</name>
      <anchor>a1</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const ACEXML_Char</type>
      <name>lt_name</name>
      <anchor>a2</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const ACEXML_Char</type>
      <name>lt_value</name>
      <anchor>a3</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const ACEXML_Char</type>
      <name>gt_name</name>
      <anchor>a4</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const ACEXML_Char</type>
      <name>gt_value</name>
      <anchor>a5</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const ACEXML_Char</type>
      <name>apos_name</name>
      <anchor>a6</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const ACEXML_Char</type>
      <name>apos_value</name>
      <anchor>a7</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const ACEXML_Char</type>
      <name>quot_name</name>
      <anchor>a8</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const ACEXML_Char</type>
      <name>quot_value</name>
      <anchor>a9</anchor>
      <arglist>[]</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Entity_Manager.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/parser/parser/</path>
    <filename>Entity__Manager_8h.html</filename>
    <class kind="class">ACEXML_Entity_Manager</class>
    <member kind="typedef">
      <type>ACE_Hash_Map_Entry&lt; ACEXML_String, ACEXML_String &gt;</type>
      <name>ACEXML_ENTITY_ENTRY</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Hash_Map_Manager_Ex&lt; ACEXML_String, ACEXML_String, ACE_Hash&lt; ACEXML_String &gt;, ACE_Equal_To&lt; ACEXML_String &gt;, ACE_Null_Mutex &gt;</type>
      <name>ACEXML_ENTITIES_MANAGER</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Hash_Map_Iterator_Ex&lt; ACEXML_String, ACEXML_String, ACE_Hash&lt; ACEXML_String &gt;, ACE_Equal_To&lt; ACEXML_String &gt;, ACE_Null_Mutex &gt;</type>
      <name>ACEXML_ENTITIES_MANAGER_ITER</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Hash_Map_Reverse_Iterator_Ex&lt; ACEXML_String, ACEXML_String, ACE_Hash&lt; ACEXML_String &gt;, ACE_Equal_To&lt; ACEXML_String &gt;, ACE_Null_Mutex &gt;</type>
      <name>ACEXML_ENTITIES_MANAGER_REVERSE_ITER</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Entity_Manager.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/parser/parser/</path>
    <filename>Entity__Manager_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>EntityResolver.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>EntityResolver_8h.html</filename>
    <class kind="class">ACEXML_EntityResolver</class>
  </compound>
  <compound kind="file">
    <name>Env.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>Env_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>Env.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>Env_8h.html</filename>
    <class kind="class">ACEXML_Env</class>
  </compound>
  <compound kind="file">
    <name>Env.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>Env_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>ErrorHandler.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>ErrorHandler_8h.html</filename>
    <class kind="class">ACEXML_ErrorHandler</class>
  </compound>
  <compound kind="file">
    <name>Exception.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>Exception_8cpp.html</filename>
    <member kind="variable" static="yes">
      <type>const ACEXML_Char</type>
      <name>ACEXML_Exception_name</name>
      <anchor>a0</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const ACEXML_Char</type>
      <name>ACEXML_Exception_null</name>
      <anchor>a1</anchor>
      <arglist>[]</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Exception.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>Exception_8h.html</filename>
    <class kind="class">ACEXML_Exception</class>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_RAISE</name>
      <anchor>a0</anchor>
      <arglist>(EXCEPTION)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Exception.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>Exception_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>FileCharStream.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>FileCharStream_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>FileCharStream.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>FileCharStream_8h.html</filename>
    <class kind="class">ACEXML_FileCharStream</class>
  </compound>
  <compound kind="file">
    <name>guidelines.txt</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/docs/</path>
    <filename>guidelines_8txt.html</filename>
  </compound>
  <compound kind="file">
    <name>HttpCharStream.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>HttpCharStream_8cpp.html</filename>
    <member kind="function" virtualness="pure">
      <type></type>
      <name>ACE_RCSID</name>
      <anchor>a8</anchor>
      <arglist>(common, HttpCharStream,&quot;HttpCharStream.cpp, v 1.14 2002/10/21 02:40:58 kitty Exp&quot;) static const int HDST_LINE1_PROTOCOL=0</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const int</type>
      <name>HDST_LINE1_WHITESPACE</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const int</type>
      <name>HDST_LINE1_STATUS</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const int</type>
      <name>HDST_BOL</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const int</type>
      <name>HDST_TEXT</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const int</type>
      <name>HDST_LF</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const int</type>
      <name>HDST_CR</name>
      <anchor>a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const int</type>
      <name>HDST_CRLF</name>
      <anchor>a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const int</type>
      <name>HDST_CRLFCR</name>
      <anchor>a7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>HttpCharStream.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>HttpCharStream_8h.html</filename>
    <class kind="class">ACEXML_HttpCharStream</class>
  </compound>
  <compound kind="file">
    <name>HttpCharStream_Test.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/tests/</path>
    <filename>HttpCharStream__Test_8cpp.html</filename>
    <member kind="function">
      <type>int</type>
      <name>ACE_TMAIN</name>
      <anchor>a0</anchor>
      <arglist>(int, ACE_TCHAR *[])</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>InputSource.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>InputSource_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>InputSource.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>InputSource_8h.html</filename>
    <class kind="class">ACEXML_InputSource</class>
  </compound>
  <compound kind="file">
    <name>Locator.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>Locator_8h.html</filename>
    <class kind="class">ACEXML_Locator</class>
  </compound>
  <compound kind="file">
    <name>LocatorImpl.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>LocatorImpl_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>LocatorImpl.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>LocatorImpl_8h.html</filename>
    <class kind="class">ACEXML_LocatorImpl</class>
  </compound>
  <compound kind="file">
    <name>LocatorImpl.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>LocatorImpl_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>SAXPrint/main.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/examples/SAXPrint/</path>
    <filename>SAXPrint_2main_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>void</type>
      <name>usage</name>
      <anchor>a1</anchor>
      <arglist>(const ACE_TCHAR *program)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>ACE_TMAIN</name>
      <anchor>a2</anchor>
      <arglist>(int argc, ACE_TCHAR *argv[])</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const ACEXML_Char *</type>
      <name>test_string</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>svcconf/main.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/examples/svcconf/</path>
    <filename>svcconf_2main_8cpp.html</filename>
    <member kind="function">
      <type>int</type>
      <name>ACE_TMAIN</name>
      <anchor>a0</anchor>
      <arglist>(int argc, ACE_TCHAR *argv[])</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Mem_Map_Stream.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>Mem__Map__Stream_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>Mem_Map_Stream.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>Mem__Map__Stream_8h.html</filename>
    <class kind="class">ACEXML_Mem_Map_Stream</class>
    <member kind="typedef">
      <type>ACE_Svc_Handler&lt; ACE_SOCK_STREAM, ACE_NULL_SYNCH &gt;</type>
      <name>Svc_Handler</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Connector&lt; Svc_Handler, ACE_SOCK_CONNECTOR &gt;</type>
      <name>Connector</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>NamespaceSupport.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>NamespaceSupport_8cpp.html</filename>
    <member kind="variable" static="yes">
      <type>const ACEXML_Char</type>
      <name>ACEXML_XMLNS_PREFIX_name</name>
      <anchor>a0</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const ACEXML_Char</type>
      <name>ACEXML_DEFAULT_NS_PREFIX</name>
      <anchor>a1</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const ACEXML_Char</type>
      <name>ACEXML_TABOO_NS_PREFIX</name>
      <anchor>a2</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const ACEXML_Char</type>
      <name>ACEXML_XMLNS_URI_name</name>
      <anchor>a3</anchor>
      <arglist>[]</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>NamespaceSupport.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>NamespaceSupport_8h.html</filename>
    <class kind="class">ACEXML_Namespace_Context_Stack</class>
    <class kind="struct">ACEXML_Namespace_Context_Stack::NS_Node_T</class>
    <class kind="class">ACEXML_NamespaceSupport</class>
    <member kind="typedef">
      <type>ACE_Hash_Map_Entry&lt; ACEXML_String, ACEXML_String &gt;</type>
      <name>ACEXML_NS_CONTEXT_ENTRY</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Hash_Map_Manager_Ex&lt; ACEXML_String, ACEXML_String, ACE_Hash&lt; ACEXML_String &gt;, ACE_Equal_To&lt; ACEXML_String &gt;, ACE_Null_Mutex &gt;</type>
      <name>ACEXML_NS_CONTEXT</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Hash_Map_Iterator_Ex&lt; ACEXML_String, ACEXML_String, ACE_Hash&lt; ACEXML_String &gt;, ACE_Equal_To&lt; ACEXML_String &gt;, ACE_Null_Mutex &gt;</type>
      <name>ACEXML_NS_CONTEXT_ITER</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Hash_Map_Reverse_Iterator_Ex&lt; ACEXML_String, ACEXML_String, ACE_Hash&lt; ACEXML_String &gt;, ACE_Equal_To&lt; ACEXML_String &gt;, ACE_Null_Mutex &gt;</type>
      <name>ACEXML_NS_CONTEXT_REVERSE_ITER</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Unbounded_Queue&lt; const ACEXML_Char *&gt;</type>
      <name>ACEXML_STR_LIST</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>NamespaceSupport.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>NamespaceSupport_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>NamespaceSupport_Test.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/tests/</path>
    <filename>NamespaceSupport__Test_8cpp.html</filename>
    <member kind="function">
      <type>int</type>
      <name>ACE_TMAIN</name>
      <anchor>a0</anchor>
      <arglist>(int, ACE_TCHAR *[])</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Parser.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/parser/parser/</path>
    <filename>Parser_8cpp.html</filename>
    <member kind="variable" static="yes">
      <type>const ACEXML_Char</type>
      <name>default_attribute_type</name>
      <anchor>a0</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const ACEXML_Char</type>
      <name>empty_string</name>
      <anchor>a1</anchor>
      <arglist>[]</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Parser.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/parser/parser/</path>
    <filename>Parser_8h.html</filename>
    <class kind="class">ACEXML_Parser</class>
  </compound>
  <compound kind="file">
    <name>Parser.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/parser/parser/</path>
    <filename>Parser_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>Parser_export.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/parser/parser/</path>
    <filename>Parser__export_8h.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_PARSER_HAS_DLL</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_PARSER_Export</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_PARSER_SINGLETON_DECLARATION</name>
      <anchor>a2</anchor>
      <arglist>(T)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_PARSER_SINGLETON_DECLARE</name>
      <anchor>a3</anchor>
      <arglist>(SINGLETON_TYPE, CLASS, LOCK)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>parser_features.txt</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/docs/</path>
    <filename>parser__features_8txt.html</filename>
  </compound>
  <compound kind="file">
    <name>Print_Handler.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/examples/SAXPrint/</path>
    <filename>Print__Handler_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>Print_Handler.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/examples/SAXPrint/</path>
    <filename>Print__Handler_8h.html</filename>
    <class kind="class">ACEXML_Print_Handler</class>
  </compound>
  <compound kind="file">
    <name>Print_Handler.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/examples/SAXPrint/</path>
    <filename>Print__Handler_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>readme.txt</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/docs/</path>
    <filename>readme_8txt.html</filename>
  </compound>
  <compound kind="file">
    <name>SAXExceptions.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>SAXExceptions_8cpp.html</filename>
    <member kind="variable" static="yes">
      <type>const ACEXML_Char</type>
      <name>ACEXML_SAXException_name</name>
      <anchor>a0</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const ACEXML_Char</type>
      <name>ACEXML_SAXNotSupportedException_name</name>
      <anchor>a1</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const ACEXML_Char</type>
      <name>ACEXML_SAXNotRecognizedException_name</name>
      <anchor>a2</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const ACEXML_Char</type>
      <name>ACEXML_SAXParseException_name</name>
      <anchor>a3</anchor>
      <arglist>[]</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>SAXExceptions.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>SAXExceptions_8h.html</filename>
    <class kind="class">ACEXML_SAXException</class>
    <class kind="class">ACEXML_SAXNotRecognizedException</class>
    <class kind="class">ACEXML_SAXNotSupportedException</class>
    <class kind="class">ACEXML_SAXParseException</class>
  </compound>
  <compound kind="file">
    <name>SAXExceptions.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>SAXExceptions_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>SAXPrint_Handler.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/examples/SAXPrint/</path>
    <filename>SAXPrint__Handler_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>SAXPrint_Handler.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/examples/SAXPrint/</path>
    <filename>SAXPrint__Handler_8h.html</filename>
    <class kind="class">ACEXML_SAXPrint_Handler</class>
  </compound>
  <compound kind="file">
    <name>SAXPrint_Handler.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/examples/SAXPrint/</path>
    <filename>SAXPrint__Handler_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>StrCharStream.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>StrCharStream_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>StrCharStream.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>StrCharStream_8h.html</filename>
    <class kind="class">ACEXML_StrCharStream</class>
  </compound>
  <compound kind="file">
    <name>StreamFactory.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>StreamFactory_8cpp.html</filename>
    <member kind="function">
      <type></type>
      <name>ACE_RCSID</name>
      <anchor>a0</anchor>
      <arglist>(common, StreamFactory,&quot;StreamFactory.cpp, v 1.2 2002/08/22 06:38:16 kitty Exp&quot;) ACEXML_CharStream *ACEXML_StreamFactory</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>StreamFactory.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>StreamFactory_8h.html</filename>
    <class kind="class">ACEXML_StreamFactory</class>
  </compound>
  <compound kind="file">
    <name>Svcconf.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/apps/svcconf/</path>
    <filename>Svcconf_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>Svcconf.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/apps/svcconf/</path>
    <filename>Svcconf_8h.html</filename>
  </compound>
  <compound kind="file">
    <name>apps/svcconf/Svcconf_Handler.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/apps/svcconf/</path>
    <filename>apps_2svcconf_2Svcconf__Handler_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>examples/svcconf/Svcconf_Handler.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/examples/svcconf/</path>
    <filename>examples_2svcconf_2Svcconf__Handler_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>apps/svcconf/Svcconf_Handler.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/apps/svcconf/</path>
    <filename>apps_2svcconf_2Svcconf__Handler_8h.html</filename>
  </compound>
  <compound kind="file">
    <name>examples/svcconf/Svcconf_Handler.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/examples/svcconf/</path>
    <filename>examples_2svcconf_2Svcconf__Handler_8h.html</filename>
    <class kind="class">ACE_Parsed_Info</class>
    <class kind="class">ACEXML_Svcconf_Handler</class>
  </compound>
  <compound kind="file">
    <name>apps/svcconf/Svcconf_Handler.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/apps/svcconf/</path>
    <filename>apps_2svcconf_2Svcconf__Handler_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>examples/svcconf/Svcconf_Handler.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/examples/svcconf/</path>
    <filename>examples_2svcconf_2Svcconf__Handler_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>TODO.txt</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/docs/</path>
    <filename>TODO_8txt.html</filename>
  </compound>
  <compound kind="file">
    <name>Transcode.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>Transcode_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>Transcode.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>Transcode_8h.html</filename>
    <class kind="class">ACEXML_Transcoder</class>
  </compound>
  <compound kind="file">
    <name>Transcode.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>Transcode_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>Transcoder_Test.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/tests/</path>
    <filename>Transcoder__Test_8cpp.html</filename>
    <member kind="function">
      <type>void</type>
      <name>dump_utf16</name>
      <anchor>a0</anchor>
      <arglist>(const ACEXML_UTF16 *data, size_t len)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>ACE_TMAIN</name>
      <anchor>a1</anchor>
      <arglist>(int, ACE_TCHAR *[])</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>URL_Addr.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>URL__Addr_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>URL_Addr.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>URL__Addr_8h.html</filename>
    <class kind="class">ACEXML_URL_Addr</class>
  </compound>
  <compound kind="file">
    <name>URL_Addr.inl</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>URL__Addr_8inl.html</filename>
  </compound>
  <compound kind="file">
    <name>Validator.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>Validator_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>Validator.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>Validator_8h.html</filename>
    <class kind="class">ACEXML_Validator</class>
  </compound>
  <compound kind="file">
    <name>XML_Codecs.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>XML__Codecs_8cpp.html</filename>
    <member kind="function">
      <type></type>
      <name>ACE_RCSID</name>
      <anchor>a0</anchor>
      <arglist>(common, XML_Codecs,&quot;XML_Codecs.cpp, v 1.4 2002/12/03 01:10:18 shuston Exp&quot;) ACEXML_Char *ACEXML_Base64</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>XML_Codecs.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>XML__Codecs_8h.html</filename>
    <class kind="class">ACEXML_Base64</class>
  </compound>
  <compound kind="file">
    <name>XML_Macros.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>XML__Macros_8h.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_ENV_EMIT_CODE</name>
      <anchor>a28</anchor>
      <arglist>(X)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_ENV_EMIT_CODE2</name>
      <anchor>a29</anchor>
      <arglist>(X, Y)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_ENV_EMIT_DUMMY</name>
      <anchor>a30</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_ENV_ARG_DECL</name>
      <anchor>a31</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_ENV_ARG_DECL_NOT_USED</name>
      <anchor>a32</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_ENV_SINGLE_ARG_DECL</name>
      <anchor>a33</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_ENV_SINGLE_ARG_DECL_NOT_USED</name>
      <anchor>a34</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_ENV_ARG_PARAMETER</name>
      <anchor>a35</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_ENV_SINGLE_ARG_PARAMETER</name>
      <anchor>a36</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_ENV_ARG_NOT_USED</name>
      <anchor>a37</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_ENV_TYPE</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_TRY_ENV</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_EXCEPTION_TYPE</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_ANY_EXCEPTION</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_DECLARE_NEW_ENV</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_ADOPT_ENV</name>
      <anchor>a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_CHECK</name>
      <anchor>a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_CHECK_RETURN</name>
      <anchor>a7</anchor>
      <arglist>(RETV)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_THROW_R_INT</name>
      <anchor>a8</anchor>
      <arglist>(EXCEPTION)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_THROW</name>
      <anchor>a9</anchor>
      <arglist>(EXCEPTION)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_THROW_RETURN</name>
      <anchor>a10</anchor>
      <arglist>(EXCEPTION, RETV)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_TRY</name>
      <anchor>a11</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_TRY_NEW_ENV</name>
      <anchor>a12</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_TRY_EX</name>
      <anchor>a13</anchor>
      <arglist>(LABEL)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_TRY_CHECK</name>
      <anchor>a14</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_TRY_CHECK_EX</name>
      <anchor>a15</anchor>
      <arglist>(LABEL)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_TRY_THROW</name>
      <anchor>a16</anchor>
      <arglist>(EXCEPTION)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_TRY_THROW_EX</name>
      <anchor>a17</anchor>
      <arglist>(EXCEPTION, LABEL)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_CATCH</name>
      <anchor>a18</anchor>
      <arglist>(EXCEPTION, VAR)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_CATCHANY</name>
      <anchor>a19</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_CATCHALL</name>
      <anchor>a20</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_RE_THROW</name>
      <anchor>a21</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_RE_THROW_EX</name>
      <anchor>a22</anchor>
      <arglist>(LABEL)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_ENDTRY</name>
      <anchor>a23</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_NEW_THROW_EX</name>
      <anchor>a24</anchor>
      <arglist>(POINTER, CONSTRUCTOR, EXCEPTION)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_GUARD_THROW_EX</name>
      <anchor>a25</anchor>
      <arglist>(MUTEX, OBJ, LOCK, EXCEPTION)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_READ_GUARD_THROW_EX</name>
      <anchor>a26</anchor>
      <arglist>(MUTEX, OBJ, LOCK, EXCEPTION)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_WRITE_GUARD_THROW_EX</name>
      <anchor>a27</anchor>
      <arglist>(MUTEX, OBJ, LOCK, EXCEPTION)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_ENV_RAISE</name>
      <anchor>a38</anchor>
      <arglist>(ex)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>XML_Types.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>XML__Types_8h.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>ACEXML_INLINE</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_USHORT16</type>
      <name>ACEXML_UTF16</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_UINT32</type>
      <name>ACEXML_UCS4</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>char</type>
      <name>ACEXML_UTF8</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACEXML_UTF8</type>
      <name>ACEXML_Char</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_CString</type>
      <name>ACEXML_String</name>
      <anchor>a5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>XMLFilter.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>XMLFilter_8h.html</filename>
    <class kind="class">ACEXML_XMLFilter</class>
  </compound>
  <compound kind="file">
    <name>XMLFilterImpl.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>XMLFilterImpl_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>XMLFilterImpl.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>XMLFilterImpl_8h.html</filename>
    <class kind="class">ACEXML_XMLFilterImpl</class>
  </compound>
  <compound kind="file">
    <name>XMLFilterImpl.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>XMLFilterImpl_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>XMLReader.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/ACEXML/common/</path>
    <filename>XMLReader_8h.html</filename>
    <class kind="class">ACEXML_XMLReader</class>
  </compound>
  <compound kind="class">
    <name>ACE_Parsed_Info</name>
    <filename>classACE__Parsed__Info.html</filename>
    <member kind="enumeration">
      <name>Service_Type</name>
      <anchor>s4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>MODULE_TYPE</name>
      <anchor>s4s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SERVICE_OBJECT_TYPE</name>
      <anchor>s4s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>STREAM_TYPE</name>
      <anchor>s4s2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>INVALID_TYPE</name>
      <anchor>s4s3</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACE_Parsed_Info</name>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~ACE_Parsed_Info</name>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>name</name>
      <anchor>a2</anchor>
      <arglist>(const ACEXML_Char *n)</arglist>
    </member>
    <member kind="function">
      <type>const ACEXML_Char *</type>
      <name>name</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>service_type</name>
      <anchor>a4</anchor>
      <arglist>(Service_Type type)</arglist>
    </member>
    <member kind="function">
      <type>Service_Type</type>
      <name>service_type</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>active</name>
      <anchor>a6</anchor>
      <arglist>(int a)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>active</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>path</name>
      <anchor>a8</anchor>
      <arglist>(const ACEXML_Char *n)</arglist>
    </member>
    <member kind="function">
      <type>const ACEXML_Char *</type>
      <name>path</name>
      <anchor>a9</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>init_func</name>
      <anchor>a10</anchor>
      <arglist>(const ACEXML_Char *n)</arglist>
    </member>
    <member kind="function">
      <type>const ACEXML_Char *</type>
      <name>init_func</name>
      <anchor>a11</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>init_params</name>
      <anchor>a12</anchor>
      <arglist>(const ACEXML_Char *n)</arglist>
    </member>
    <member kind="function">
      <type>const ACEXML_Char *</type>
      <name>init_params</name>
      <anchor>a13</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>reset</name>
      <anchor>a14</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACEXML_Char *</type>
      <name>name_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>Service_Type</type>
      <name>service_type_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>int</type>
      <name>active_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACEXML_Char *</type>
      <name>path_</name>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACEXML_Char *</type>
      <name>init_func_</name>
      <anchor>n4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACEXML_Char *</type>
      <name>init_params_</name>
      <anchor>n5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_Attribute</name>
    <filename>classACEXML__Attribute.html</filename>
    <member kind="function">
      <type></type>
      <name>ACEXML_Attribute</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACEXML_Attribute</name>
      <anchor>a1</anchor>
      <arglist>(const ACEXML_Attribute &amp;attr)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACEXML_Attribute</name>
      <anchor>a2</anchor>
      <arglist>(const ACEXML_Char *uri, const ACEXML_Char *localName, const ACEXML_Char *qName, const ACEXML_Char *type, const ACEXML_Char *value)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~ACEXML_Attribute</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setAttribute</name>
      <anchor>a4</anchor>
      <arglist>(const ACEXML_Char *uri, const ACEXML_Char *localName, const ACEXML_Char *qName, const ACEXML_Char *type, const ACEXML_Char *value)</arglist>
    </member>
    <member kind="function">
      <type>const ACEXML_Char *</type>
      <name>uri</name>
      <anchor>a5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>uri</name>
      <anchor>a6</anchor>
      <arglist>(const ACEXML_Char *uri)</arglist>
    </member>
    <member kind="function">
      <type>const ACEXML_Char *</type>
      <name>localName</name>
      <anchor>a7</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>localName</name>
      <anchor>a8</anchor>
      <arglist>(const ACEXML_Char *localName)</arglist>
    </member>
    <member kind="function">
      <type>const ACEXML_Char *</type>
      <name>qName</name>
      <anchor>a9</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>qName</name>
      <anchor>a10</anchor>
      <arglist>(const ACEXML_Char *qName)</arglist>
    </member>
    <member kind="function">
      <type>const ACEXML_Char *</type>
      <name>type</name>
      <anchor>a11</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>type</name>
      <anchor>a12</anchor>
      <arglist>(const ACEXML_Char *type)</arglist>
    </member>
    <member kind="function">
      <type>const ACEXML_Char *</type>
      <name>value</name>
      <anchor>a13</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>value</name>
      <anchor>a14</anchor>
      <arglist>(const ACEXML_Char *value)</arglist>
    </member>
    <member kind="function">
      <type>ACEXML_Attribute &amp;</type>
      <name>operator=</name>
      <anchor>a15</anchor>
      <arglist>(const ACEXML_Attribute &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>operator!=</name>
      <anchor>a16</anchor>
      <arglist>(const ACEXML_Attribute &amp;rhs) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Char *</type>
      <name>uri_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Char *</type>
      <name>localName_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Char *</type>
      <name>qName_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Char *</type>
      <name>type_</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Char *</type>
      <name>value_</name>
      <anchor>o4</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>ACEXML_AttributesImpl</name>
      <anchor>l0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_Attribute_Def_Builder</name>
    <filename>classACEXML__Attribute__Def__Builder.html</filename>
    <member kind="typedef">
      <type>auto_ptr&lt; ACEXML_Attribute_Def_Builder &gt;</type>
      <name>VAR</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>ATT_TYPE</name>
      <anchor>s16</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>CDATA</name>
      <anchor>s16s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ID</name>
      <anchor>s16s2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IDREF</name>
      <anchor>s16s3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IDREFS</name>
      <anchor>s16s4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ENTITY</name>
      <anchor>s16s5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ENTITIES</name>
      <anchor>s16s6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>NMTOKEN</name>
      <anchor>s16s7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>NMTOKENS</name>
      <anchor>s16s8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>NOTATION</name>
      <anchor>s16s9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ENUMERATION</name>
      <anchor>s16s10</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ERROR_TYPE</name>
      <anchor>s16s11</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>DEFAULT_DECL</name>
      <anchor>s17</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>REQUIRED</name>
      <anchor>s17s12</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IMPLIED</name>
      <anchor>s17s13</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>FIXED</name>
      <anchor>s17s14</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>INVALID</name>
      <anchor>s17s15</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual</type>
      <name>~ACEXML_Attribute_Def_Builder</name>
      <anchor>a0</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>setName</name>
      <anchor>a1</anchor>
      <arglist>(const ACEXML_Char *n)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual const ACEXML_Char *</type>
      <name>getName</name>
      <anchor>a2</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>setAttType</name>
      <anchor>a3</anchor>
      <arglist>(const ATT_TYPE type ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>insertList</name>
      <anchor>a4</anchor>
      <arglist>(const ACEXML_Char *Name ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>setDefault</name>
      <anchor>a5</anchor>
      <arglist>(const DEFAULT_DECL def, const ACEXML_Char *value ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>validAttr</name>
      <anchor>a6</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>dump</name>
      <anchor>a7</anchor>
      <arglist>(void)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_Attributes</name>
    <filename>classACEXML__Attributes.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>getIndex</name>
      <anchor>a0</anchor>
      <arglist>(const ACEXML_Char *qName)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>getIndex</name>
      <anchor>a1</anchor>
      <arglist>(const ACEXML_Char *uri, const ACEXML_Char *localPart)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual size_t</type>
      <name>getLength</name>
      <anchor>a2</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual const ACEXML_Char *</type>
      <name>getLocalName</name>
      <anchor>a3</anchor>
      <arglist>(size_t index)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual const ACEXML_Char *</type>
      <name>getQName</name>
      <anchor>a4</anchor>
      <arglist>(size_t index)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual const ACEXML_Char *</type>
      <name>getType</name>
      <anchor>a5</anchor>
      <arglist>(size_t index)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual const ACEXML_Char *</type>
      <name>getType</name>
      <anchor>a6</anchor>
      <arglist>(const ACEXML_Char *qName)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual const ACEXML_Char *</type>
      <name>getType</name>
      <anchor>a7</anchor>
      <arglist>(const ACEXML_Char *uri, const ACEXML_Char *localPart)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual const ACEXML_Char *</type>
      <name>getURI</name>
      <anchor>a8</anchor>
      <arglist>(size_t index)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual const ACEXML_Char *</type>
      <name>getValue</name>
      <anchor>a9</anchor>
      <arglist>(size_t index)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual const ACEXML_Char *</type>
      <name>getValue</name>
      <anchor>a10</anchor>
      <arglist>(const ACEXML_Char *qName)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual const ACEXML_Char *</type>
      <name>getValue</name>
      <anchor>a11</anchor>
      <arglist>(const ACEXML_Char *uri, const ACEXML_Char *localPart)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_Attributes_Def_Builder</name>
    <filename>classACEXML__Attributes__Def__Builder.html</filename>
    <member kind="typedef">
      <type>auto_ptr&lt; ACEXML_Attributes_Def_Builder &gt;</type>
      <name>VAR</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual</type>
      <name>~ACEXML_Attributes_Def_Builder</name>
      <anchor>a0</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>setElement</name>
      <anchor>a1</anchor>
      <arglist>(const ACEXML_Char *namespaceURI, const ACEXML_Char *localName, const ACEXML_Char *qName ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual ACEXML_Attribute_Def_Builder *</type>
      <name>getAttribute_Def_Builder</name>
      <anchor>a2</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>insertAttribute</name>
      <anchor>a3</anchor>
      <arglist>(ACEXML_Attribute_Def_Builder *def ACEXML_ENV_ARG_DECL)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>dump</name>
      <anchor>a4</anchor>
      <arglist>(void)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_AttributesImpl</name>
    <filename>classACEXML__AttributesImpl.html</filename>
    <base>ACEXML_Attributes</base>
    <member kind="function">
      <type></type>
      <name>ACEXML_AttributesImpl</name>
      <anchor>a0</anchor>
      <arglist>(int size=ACEXML_AttributesImpl_Default_Size)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACEXML_AttributesImpl</name>
      <anchor>a1</anchor>
      <arglist>(const ACEXML_AttributesImpl &amp;attrs)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ACEXML_AttributesImpl</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>addAttribute</name>
      <anchor>a3</anchor>
      <arglist>(const ACEXML_Char *uri, const ACEXML_Char *localName, const ACEXML_Char *qName, const ACEXML_Char *type, const ACEXML_Char *value)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>addAttribute</name>
      <anchor>a4</anchor>
      <arglist>(const ACEXML_Attribute &amp;att)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>isDuplicate</name>
      <anchor>a5</anchor>
      <arglist>(const ACEXML_Char *uri, const ACEXML_Char *localName, const ACEXML_Char *qName)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>removeAttribute</name>
      <anchor>a6</anchor>
      <arglist>(size_t index)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getIndex</name>
      <anchor>a7</anchor>
      <arglist>(const ACEXML_Char *qName)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getIndex</name>
      <anchor>a8</anchor>
      <arglist>(const ACEXML_Char *uri, const ACEXML_Char *localPart)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual size_t</type>
      <name>getLength</name>
      <anchor>a9</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const ACEXML_Char *</type>
      <name>getLocalName</name>
      <anchor>a10</anchor>
      <arglist>(size_t index)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const ACEXML_Char *</type>
      <name>getQName</name>
      <anchor>a11</anchor>
      <arglist>(size_t index)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const ACEXML_Char *</type>
      <name>getType</name>
      <anchor>a12</anchor>
      <arglist>(size_t index)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const ACEXML_Char *</type>
      <name>getType</name>
      <anchor>a13</anchor>
      <arglist>(const ACEXML_Char *qName)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const ACEXML_Char *</type>
      <name>getType</name>
      <anchor>a14</anchor>
      <arglist>(const ACEXML_Char *uri, const ACEXML_Char *localPart)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const ACEXML_Char *</type>
      <name>getURI</name>
      <anchor>a15</anchor>
      <arglist>(size_t index)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const ACEXML_Char *</type>
      <name>getValue</name>
      <anchor>a16</anchor>
      <arglist>(size_t index)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const ACEXML_Char *</type>
      <name>getValue</name>
      <anchor>a17</anchor>
      <arglist>(const ACEXML_Char *qName)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const ACEXML_Char *</type>
      <name>getValue</name>
      <anchor>a18</anchor>
      <arglist>(const ACEXML_Char *uri, const ACEXML_Char *localPart)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>setAttribute</name>
      <anchor>a19</anchor>
      <arglist>(size_t index, const ACEXML_Char *uri, const ACEXML_Char *localName, const ACEXML_Char *qName, const ACEXML_Char *type, const ACEXML_Char *value)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>setLocalName</name>
      <anchor>a20</anchor>
      <arglist>(size_t index, const ACEXML_Char *localName)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>setQName</name>
      <anchor>a21</anchor>
      <arglist>(size_t index, const ACEXML_Char *qName)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>setURI</name>
      <anchor>a22</anchor>
      <arglist>(size_t index, const ACEXML_Char *uri)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>setType</name>
      <anchor>a23</anchor>
      <arglist>(size_t index, const ACEXML_Char *type)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>setValue</name>
      <anchor>a24</anchor>
      <arglist>(size_t index, const ACEXML_Char *value)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Attribute_Array</type>
      <name>attrs_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_Base64</name>
    <filename>classACEXML__Base64.html</filename>
    <base>ACE_Base64</base>
    <member kind="function" static="yes">
      <type>ACEXML_Char *</type>
      <name>encode</name>
      <anchor>z1_0</anchor>
      <arglist>(const ACEXML_Char *input, size_t *output_len)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>ACEXML_Char *</type>
      <name>decode</name>
      <anchor>z1_1</anchor>
      <arglist>(const ACEXML_Char *input, size_t *output_len)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_CharStream</name>
    <filename>classACEXML__CharStream.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual</type>
      <name>~ACEXML_CharStream</name>
      <anchor>a0</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>available</name>
      <anchor>a1</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>close</name>
      <anchor>a2</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>get</name>
      <anchor>a3</anchor>
      <arglist>(ACEXML_Char &amp;ch)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>read</name>
      <anchor>a4</anchor>
      <arglist>(ACEXML_Char *str, size_t len)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>peek</name>
      <anchor>a5</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual const ACEXML_Char *</type>
      <name>getEncoding</name>
      <anchor>a6</anchor>
      <arglist>(void)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_ContentHandler</name>
    <filename>classACEXML__ContentHandler.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>characters</name>
      <anchor>a0</anchor>
      <arglist>(const ACEXML_Char *ch, int start, int length ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>endDocument</name>
      <anchor>a1</anchor>
      <arglist>(ACEXML_ENV_SINGLE_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>endElement</name>
      <anchor>a2</anchor>
      <arglist>(const ACEXML_Char *namespaceURI, const ACEXML_Char *localName, const ACEXML_Char *qName ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>endPrefixMapping</name>
      <anchor>a3</anchor>
      <arglist>(const ACEXML_Char *prefix ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>ignorableWhitespace</name>
      <anchor>a4</anchor>
      <arglist>(const ACEXML_Char *ch, int start, int length ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>processingInstruction</name>
      <anchor>a5</anchor>
      <arglist>(const ACEXML_Char *target, const ACEXML_Char *data ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>setDocumentLocator</name>
      <anchor>a6</anchor>
      <arglist>(ACEXML_Locator *locator)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>skippedEntity</name>
      <anchor>a7</anchor>
      <arglist>(const ACEXML_Char *name ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>startDocument</name>
      <anchor>a8</anchor>
      <arglist>(ACEXML_ENV_SINGLE_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>startElement</name>
      <anchor>a9</anchor>
      <arglist>(const ACEXML_Char *namespaceURI, const ACEXML_Char *localName, const ACEXML_Char *qName, ACEXML_Attributes *atts ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>startPrefixMapping</name>
      <anchor>a10</anchor>
      <arglist>(const ACEXML_Char *prefix, const ACEXML_Char *uri ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_Debug_Attribute_Builder</name>
    <filename>classACEXML__Debug__Attribute__Builder.html</filename>
    <base>ACEXML_Attribute_Def_Builder</base>
    <member kind="function">
      <type></type>
      <name>ACEXML_Debug_Attribute_Builder</name>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACEXML_Debug_Attribute_Builder</name>
      <anchor>a1</anchor>
      <arglist>(const ACEXML_Debug_Attribute_Builder &amp;rhs)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ACEXML_Debug_Attribute_Builder</name>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>setName</name>
      <anchor>a3</anchor>
      <arglist>(const ACEXML_Char *n)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const ACEXML_Char *</type>
      <name>getName</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>setAttType</name>
      <anchor>a5</anchor>
      <arglist>(const ATT_TYPE type ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>insertList</name>
      <anchor>a6</anchor>
      <arglist>(const ACEXML_Char *Name ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>setDefault</name>
      <anchor>a7</anchor>
      <arglist>(const DEFAULT_DECL def, const ACEXML_Char *value ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>validAttr</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>dump</name>
      <anchor>a9</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_String</type>
      <name>name_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ATT_TYPE</type>
      <name>type_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>DEFAULT_DECL</type>
      <name>default_decl_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_String</type>
      <name>default_value_</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_STRING_QUEUE</type>
      <name>att_value_queue_</name>
      <anchor>o4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_Debug_Attributes_Builder</name>
    <filename>classACEXML__Debug__Attributes__Builder.html</filename>
    <base>ACEXML_Attributes_Def_Builder</base>
    <member kind="function">
      <type></type>
      <name>ACEXML_Debug_Attributes_Builder</name>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ACEXML_Debug_Attributes_Builder</name>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>setElement</name>
      <anchor>a2</anchor>
      <arglist>(const ACEXML_Char *namespaceURI, const ACEXML_Char *localName, const ACEXML_Char *qName ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACEXML_Attribute_Def_Builder *</type>
      <name>getAttribute_Def_Builder</name>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>insertAttribute</name>
      <anchor>a4</anchor>
      <arglist>(ACEXML_Attribute_Def_Builder *def ACEXML_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>dump</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACEXML_String</type>
      <name>element_name_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACEXML_ATT_MAP</type>
      <name>attributes_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_Debug_DTD_Manager</name>
    <filename>classACEXML__Debug__DTD__Manager.html</filename>
    <base>ACEXML_DTD_Manager</base>
    <member kind="function">
      <type></type>
      <name>ACEXML_Debug_DTD_Manager</name>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ACEXML_Debug_DTD_Manager</name>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACEXML_Element_Def_Builder *</type>
      <name>getElement_Def_Builder</name>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>insertElement_Definition</name>
      <anchor>a3</anchor>
      <arglist>(ACEXML_Element_Def_Builder *def ACEXML_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACEXML_Attributes_Def_Builder *</type>
      <name>getAttribute_Def_Builder</name>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>insertAttributes_Definition</name>
      <anchor>a5</anchor>
      <arglist>(ACEXML_Attributes_Def_Builder *def ACEXML_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACEXML_Validator *</type>
      <name>getValidator</name>
      <anchor>a6</anchor>
      <arglist>(const ACEXML_Char *namespaceURI, const ACEXML_Char *localName, const ACEXML_Char *qName ACEXML_ENV_ARG_DECL)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_Debug_Element_Builder</name>
    <filename>classACEXML__Debug__Element__Builder.html</filename>
    <base>ACEXML_Element_Def_Builder</base>
    <member kind="function">
      <type></type>
      <name>ACEXML_Debug_Element_Builder</name>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ACEXML_Debug_Element_Builder</name>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>setElementName</name>
      <anchor>a2</anchor>
      <arglist>(const ACEXML_Char *namespaceURI, const ACEXML_Char *localName, const ACEXML_Char *qName ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>setContentType</name>
      <anchor>a3</anchor>
      <arglist>(CONTENT_TYPE type ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>insertMixedElement</name>
      <anchor>a4</anchor>
      <arglist>(const ACEXML_Char *namespaceURI, const ACEXML_Char *localName, const ACEXML_Char *qName ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>startChildGroup</name>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>endChildGroup</name>
      <anchor>a6</anchor>
      <arglist>(CARDINALITY card ACEXML_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>setChoice</name>
      <anchor>a7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>setSequence</name>
      <anchor>a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>insertElement</name>
      <anchor>a9</anchor>
      <arglist>(const ACEXML_Char *namespaceURI, const ACEXML_Char *localName, const ACEXML_Char *qName ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>dump</name>
      <anchor>a10</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>CONTENT_TYPE</type>
      <name>type_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_String</type>
      <name>element_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Element_Tree_List_Node *</type>
      <name>root_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Element_Tree_List_Stack</type>
      <name>active_list_</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_DefaultHandler</name>
    <filename>classACEXML__DefaultHandler.html</filename>
    <base>ACEXML_ContentHandler</base>
    <base>ACEXML_DTDHandler</base>
    <base>ACEXML_EntityResolver</base>
    <base>ACEXML_ErrorHandler</base>
    <member kind="function">
      <type></type>
      <name>ACEXML_DefaultHandler</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ACEXML_DefaultHandler</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>characters</name>
      <anchor>a2</anchor>
      <arglist>(const ACEXML_Char *ch, int start, int length ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>endDocument</name>
      <anchor>a3</anchor>
      <arglist>(ACEXML_ENV_SINGLE_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>endElement</name>
      <anchor>a4</anchor>
      <arglist>(const ACEXML_Char *namespaceURI, const ACEXML_Char *localName, const ACEXML_Char *qName ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>endPrefixMapping</name>
      <anchor>a5</anchor>
      <arglist>(const ACEXML_Char *prefix ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>ignorableWhitespace</name>
      <anchor>a6</anchor>
      <arglist>(const ACEXML_Char *ch, int start, int length ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>processingInstruction</name>
      <anchor>a7</anchor>
      <arglist>(const ACEXML_Char *target, const ACEXML_Char *data ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setDocumentLocator</name>
      <anchor>a8</anchor>
      <arglist>(ACEXML_Locator *locator)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>skippedEntity</name>
      <anchor>a9</anchor>
      <arglist>(const ACEXML_Char *name ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>startDocument</name>
      <anchor>a10</anchor>
      <arglist>(ACEXML_ENV_SINGLE_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>startElement</name>
      <anchor>a11</anchor>
      <arglist>(const ACEXML_Char *namespaceURI, const ACEXML_Char *localName, const ACEXML_Char *qName, ACEXML_Attributes *atts ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>startPrefixMapping</name>
      <anchor>a12</anchor>
      <arglist>(const ACEXML_Char *prefix, const ACEXML_Char *uri ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>notationDecl</name>
      <anchor>a13</anchor>
      <arglist>(const ACEXML_Char *name, const ACEXML_Char *publicId, const ACEXML_Char *systemId ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>unparsedEntityDecl</name>
      <anchor>a14</anchor>
      <arglist>(const ACEXML_Char *name, const ACEXML_Char *publicId, const ACEXML_Char *systemId, const ACEXML_Char *notationName ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACEXML_InputSource *</type>
      <name>resolveEntity</name>
      <anchor>a15</anchor>
      <arglist>(const ACEXML_Char *publicId, const ACEXML_Char *systemId ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>error</name>
      <anchor>a16</anchor>
      <arglist>(ACEXML_SAXParseException &amp;exception ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>fatalError</name>
      <anchor>a17</anchor>
      <arglist>(ACEXML_SAXParseException &amp;exception ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>warning</name>
      <anchor>a18</anchor>
      <arglist>(ACEXML_SAXParseException &amp;exception ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_DTD_Manager</name>
    <filename>classACEXML__DTD__Manager.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual</type>
      <name>~ACEXML_DTD_Manager</name>
      <anchor>a0</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual ACEXML_Element_Def_Builder *</type>
      <name>getElement_Def_Builder</name>
      <anchor>a1</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>insertElement_Definition</name>
      <anchor>a2</anchor>
      <arglist>(ACEXML_Element_Def_Builder *def ACEXML_ENV_ARG_DECL)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual ACEXML_Attributes_Def_Builder *</type>
      <name>getAttribute_Def_Builder</name>
      <anchor>a3</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>insertAttributes_Definition</name>
      <anchor>a4</anchor>
      <arglist>(ACEXML_Attributes_Def_Builder *def ACEXML_ENV_ARG_DECL)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual ACEXML_Validator *</type>
      <name>getValidator</name>
      <anchor>a5</anchor>
      <arglist>(const ACEXML_Char *namespaceURI, const ACEXML_Char *localName, const ACEXML_Char *qName ACEXML_ENV_ARG_DECL)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_DTDHandler</name>
    <filename>classACEXML__DTDHandler.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>notationDecl</name>
      <anchor>a0</anchor>
      <arglist>(const ACEXML_Char *name, const ACEXML_Char *publicId, const ACEXML_Char *systemId ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>unparsedEntityDecl</name>
      <anchor>a1</anchor>
      <arglist>(const ACEXML_Char *name, const ACEXML_Char *publicId, const ACEXML_Char *systemId, const ACEXML_Char *notationName ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_Element_Def_Builder</name>
    <filename>classACEXML__Element__Def__Builder.html</filename>
    <member kind="typedef">
      <type>auto_ptr&lt; ACEXML_Element_Def_Builder &gt;</type>
      <name>VAR</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>CONTENT_TYPE</name>
      <anchor>s10</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>EMPTY</name>
      <anchor>s10s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ANY</name>
      <anchor>s10s2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>MIXED</name>
      <anchor>s10s3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>CHILDREN</name>
      <anchor>s10s4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>UNDEFINED</name>
      <anchor>s10s5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>CARDINALITY</name>
      <anchor>s11</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ONE</name>
      <anchor>s11s6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ZERO_OR_MORE</name>
      <anchor>s11s7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ONE_OR_MORE</name>
      <anchor>s11s8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ONE_OR_ZERO</name>
      <anchor>s11s9</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual</type>
      <name>~ACEXML_Element_Def_Builder</name>
      <anchor>a0</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>setElementName</name>
      <anchor>a1</anchor>
      <arglist>(const ACEXML_Char *namespaceURI, const ACEXML_Char *localName, const ACEXML_Char *qName ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>setContentType</name>
      <anchor>a2</anchor>
      <arglist>(CONTENT_TYPE type ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>insertMixedElement</name>
      <anchor>a3</anchor>
      <arglist>(const ACEXML_Char *namespaceURI, const ACEXML_Char *localName, const ACEXML_Char *qName ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>startChildGroup</name>
      <anchor>a4</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>endChildGroup</name>
      <anchor>a5</anchor>
      <arglist>(CARDINALITY card ACEXML_ENV_ARG_DECL)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>setChoice</name>
      <anchor>a6</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>setSequence</name>
      <anchor>a7</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>insertElement</name>
      <anchor>a8</anchor>
      <arglist>(const ACEXML_Char *namespaceURI, const ACEXML_Char *localName, const ACEXML_Char *qName ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>dump</name>
      <anchor>a9</anchor>
      <arglist>(void)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_Element_Tree_List_Node</name>
    <filename>classACEXML__Element__Tree__List__Node.html</filename>
    <base>ACEXML_Element_Tree_Node</base>
    <member kind="enumeration">
      <name>LIST_TYPE</name>
      <anchor>s2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SEQUENCE</name>
      <anchor>s2s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>CHOICE</name>
      <anchor>s2s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACEXML_Element_Tree_List_Node</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ACEXML_Element_Tree_List_Node</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>insert</name>
      <anchor>a2</anchor>
      <arglist>(ACEXML_Element_Tree_Node *node)</arglist>
    </member>
    <member kind="function">
      <type>LIST_TYPE</type>
      <name>get</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>set</name>
      <anchor>a4</anchor>
      <arglist>(LIST_TYPE type)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>dump</name>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type></type>
      <name>ACE_ALLOC_HOOK_DECLARE</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>LIST_TYPE</type>
      <name>type_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACEXML_Element_Tree_Node *</type>
      <name>head_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACEXML_Element_Tree_Node *</type>
      <name>tail_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACEXML_Element_Tree_List_Node *</type>
      <name>pop_next_</name>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>ACEXML_Element_Tree_List_Stack</name>
      <anchor>l0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_Element_Tree_List_Stack</name>
    <filename>classACEXML__Element__Tree__List__Stack.html</filename>
    <member kind="function">
      <type></type>
      <name>ACEXML_Element_Tree_List_Stack</name>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>push</name>
      <anchor>a1</anchor>
      <arglist>(ACEXML_Element_Tree_List_Node *n)</arglist>
    </member>
    <member kind="function">
      <type>ACEXML_Element_Tree_List_Node *</type>
      <name>pop</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>ACEXML_Element_Tree_List_Node *</type>
      <name>top</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>empty</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable">
      <type></type>
      <name>ACE_ALLOC_HOOK_DECLARE</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACEXML_Element_Tree_List_Node *</type>
      <name>top_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_Element_Tree_Name_Node</name>
    <filename>classACEXML__Element__Tree__Name__Node.html</filename>
    <base>ACEXML_Element_Tree_Node</base>
    <member kind="function">
      <type></type>
      <name>ACEXML_Element_Tree_Name_Node</name>
      <anchor>a0</anchor>
      <arglist>(const ACEXML_Char *name, int release=1)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set</name>
      <anchor>a1</anchor>
      <arglist>(const ACEXML_Char *name, int release=1)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>dump</name>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type></type>
      <name>ACE_ALLOC_HOOK_DECLARE</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACEXML_String</type>
      <name>name_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_Element_Tree_Node</name>
    <filename>classACEXML__Element__Tree__Node.html</filename>
    <member kind="function">
      <type></type>
      <name>ACEXML_Element_Tree_Node</name>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ACEXML_Element_Tree_Node</name>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>ACEXML_Element_Tree_Node *</type>
      <name>next</name>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>next</name>
      <anchor>a3</anchor>
      <arglist>(ACEXML_Element_Tree_Node *n)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>dump</name>
      <anchor>a4</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="variable">
      <type></type>
      <name>ACE_ALLOC_HOOK_DECLARE</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACEXML_Element_Tree_Node *</type>
      <name>next_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_Encoding</name>
    <filename>classACEXML__Encoding.html</filename>
    <member kind="enumvalue">
      <name>UCS4BE</name>
      <anchor>s8s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>UCS4LE</name>
      <anchor>s8s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>UCS4_2143</name>
      <anchor>s8s2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>UCS4_3412</name>
      <anchor>s8s3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>UTF16BE</name>
      <anchor>s8s4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>UTF16LE</name>
      <anchor>s8s5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>UTF8</name>
      <anchor>s8s6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>OTHER</name>
      <anchor>s8s7</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" static="yes">
      <type>const ACEXML_Char *</type>
      <name>get_encoding</name>
      <anchor>d0</anchor>
      <arglist>(const char *input)</arglist>
    </member>
    <member kind="variable">
      <type>enum ACEXML_Encoding::@0</type>
      <name>ENCODING</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const ACEXML_Char *</type>
      <name>encoding_names_</name>
      <anchor>p0</anchor>
      <arglist>[8]</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const ACEXML_UTF8</type>
      <name>byte_order_mark_</name>
      <anchor>p1</anchor>
      <arglist>[][4]</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const ACEXML_UTF8</type>
      <name>magic_values_</name>
      <anchor>p2</anchor>
      <arglist>[][4]</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_Entity_Manager</name>
    <filename>classACEXML__Entity__Manager.html</filename>
    <member kind="function">
      <type></type>
      <name>ACEXML_Entity_Manager</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~ACEXML_Entity_Manager</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>add_entity</name>
      <anchor>a2</anchor>
      <arglist>(const ACEXML_Char *ref, const ACEXML_Char *value)</arglist>
    </member>
    <member kind="function">
      <type>const ACEXML_String *</type>
      <name>resolve_entity</name>
      <anchor>a3</anchor>
      <arglist>(const ACEXML_Char *ref)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_ENTITIES_MANAGER</type>
      <name>entities_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_EntityResolver</name>
    <filename>classACEXML__EntityResolver.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual ACEXML_InputSource *</type>
      <name>resolveEntity</name>
      <anchor>a0</anchor>
      <arglist>(const ACEXML_Char *publicId, const ACEXML_Char *systemId ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_Env</name>
    <filename>classACEXML__Env.html</filename>
    <member kind="function">
      <type></type>
      <name>ACEXML_Env</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACEXML_Env</name>
      <anchor>a1</anchor>
      <arglist>(const ACEXML_Env &amp;ACEXML_TRY_ENV)</arglist>
    </member>
    <member kind="function">
      <type>ACEXML_Env &amp;</type>
      <name>operator=</name>
      <anchor>a2</anchor>
      <arglist>(const ACEXML_Env &amp;ACEXML_TRY_ENV)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~ACEXML_Env</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>clear</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable">
      <type>ACEXML_Exception *exception void</type>
      <name>const</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>void exception ACEXML_Exception *</type>
      <name>ex</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Exception *</type>
      <name>exception_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_ErrorHandler</name>
    <filename>classACEXML__ErrorHandler.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>error</name>
      <anchor>a0</anchor>
      <arglist>(ACEXML_SAXParseException &amp;exception ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>fatalError</name>
      <anchor>a1</anchor>
      <arglist>(ACEXML_SAXParseException &amp;exception ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>warning</name>
      <anchor>a2</anchor>
      <arglist>(ACEXML_SAXParseException &amp;exception ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_Exception</name>
    <filename>classACEXML__Exception.html</filename>
    <member kind="function">
      <type></type>
      <name>ACEXML_Exception</name>
      <anchor>a0</anchor>
      <arglist>(const ACEXML_Exception &amp;src)</arglist>
    </member>
    <member kind="function">
      <type>ACEXML_Exception &amp;</type>
      <name>operator=</name>
      <anchor>a1</anchor>
      <arglist>(const ACEXML_Exception &amp;src)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ACEXML_Exception</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>_raise</name>
      <anchor>a3</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const ACEXML_Char *</type>
      <name>id</name>
      <anchor>a4</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual ACEXML_Exception *</type>
      <name>duplicate</name>
      <anchor>a5</anchor>
      <arglist>(void) const=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>is_a</name>
      <anchor>a6</anchor>
      <arglist>(const ACEXML_Char *name)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>print</name>
      <anchor>a7</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="function" static="yes">
      <type>ACEXML_Exception *</type>
      <name>_downcast</name>
      <anchor>d0</anchor>
      <arglist>(ACEXML_Exception *ex)</arglist>
    </member>
    <member kind="function" protection="public">
      <type></type>
      <name>ACEXML_Exception</name>
      <anchor>b0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="public" static="yes">
      <type>const ACEXML_Char *</type>
      <name>exception_name_</name>
      <anchor>q0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public" static="yes">
      <type>const ACEXML_Char *</type>
      <name>null_</name>
      <anchor>q1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_FileCharStream</name>
    <filename>classACEXML__FileCharStream.html</filename>
    <base>ACEXML_CharStream</base>
    <member kind="function">
      <type></type>
      <name>ACEXML_FileCharStream</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ACEXML_FileCharStream</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>open</name>
      <anchor>a2</anchor>
      <arglist>(const ACEXML_Char *name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>available</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>close</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>get</name>
      <anchor>a5</anchor>
      <arglist>(ACEXML_Char &amp;ch)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>read</name>
      <anchor>a6</anchor>
      <arglist>(ACEXML_Char *str, size_t len)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>determine_encoding</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>peek</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>rewind</name>
      <anchor>a9</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const ACEXML_Char *</type>
      <name>getEncoding</name>
      <anchor>a10</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual int</type>
      <name>getchar_i</name>
      <anchor>b0</anchor>
      <arglist>(char &amp;ch)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Char *</type>
      <name>filename_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Char *</type>
      <name>encoding_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>off_t</type>
      <name>size_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>FILE *</type>
      <name>infile_</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Char</type>
      <name>peek_</name>
      <anchor>o4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_HttpCharStream</name>
    <filename>classACEXML__HttpCharStream.html</filename>
    <base>ACEXML_CharStream</base>
    <member kind="function">
      <type></type>
      <name>ACEXML_HttpCharStream</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ACEXML_HttpCharStream</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>open</name>
      <anchor>a2</anchor>
      <arglist>(const ACEXML_Char *url)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>available</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>close</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>get</name>
      <anchor>a5</anchor>
      <arglist>(ACEXML_Char &amp;ch)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>read</name>
      <anchor>a6</anchor>
      <arglist>(ACEXML_Char *str, size_t len)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>peek</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>rewind</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const ACEXML_Char *</type>
      <name>getEncoding</name>
      <anchor>a9</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>int</type>
      <name>send_request</name>
      <anchor>c0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>int</type>
      <name>get_url</name>
      <anchor>c1</anchor>
      <arglist>(size_t &amp;len)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Char *</type>
      <name>url_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_URL_Addr *</type>
      <name>url_addr_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Mem_Map_Stream *</type>
      <name>stream_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>Connector *</type>
      <name>connector_</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>off_t</type>
      <name>size_</name>
      <anchor>o4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Char *</type>
      <name>encoding_</name>
      <anchor>o5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_InputSource</name>
    <filename>classACEXML__InputSource.html</filename>
    <member kind="function">
      <type></type>
      <name>ACEXML_InputSource</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACEXML_InputSource</name>
      <anchor>a1</anchor>
      <arglist>(ACEXML_CharStream *stream)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACEXML_InputSource</name>
      <anchor>a2</anchor>
      <arglist>(const ACEXML_Char *systemId)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ACEXML_InputSource</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACEXML_CharStream *</type>
      <name>getCharStream</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const ACEXML_Char *</type>
      <name>getEncoding</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const ACEXML_Char *</type>
      <name>getPublicId</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const ACEXML_Char *</type>
      <name>getSystemId</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setCharStream</name>
      <anchor>a8</anchor>
      <arglist>(ACEXML_CharStream *charStream)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setEncoding</name>
      <anchor>a9</anchor>
      <arglist>(const ACEXML_Char *encoding)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setPublicId</name>
      <anchor>a10</anchor>
      <arglist>(const ACEXML_Char *publicId)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setSystemId</name>
      <anchor>a11</anchor>
      <arglist>(const ACEXML_Char *systemId)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Char *</type>
      <name>publicId_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Char *</type>
      <name>systemId_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_CharStream *</type>
      <name>charStream_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Char *</type>
      <name>encoding_</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_Locator</name>
    <filename>classACEXML__Locator.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>getColumnNumber</name>
      <anchor>a0</anchor>
      <arglist>(void) const=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>getLineNumber</name>
      <anchor>a1</anchor>
      <arglist>(void) const=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual const ACEXML_Char *</type>
      <name>getPublicId</name>
      <anchor>a2</anchor>
      <arglist>(void) const=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual const ACEXML_Char *</type>
      <name>getSystemId</name>
      <anchor>a3</anchor>
      <arglist>(void) const=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_LocatorImpl</name>
    <filename>classACEXML__LocatorImpl.html</filename>
    <base>ACEXML_Locator</base>
    <member kind="function">
      <type></type>
      <name>ACEXML_LocatorImpl</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACEXML_LocatorImpl</name>
      <anchor>a1</anchor>
      <arglist>(const ACEXML_Locator &amp;locator)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ACEXML_LocatorImpl</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getColumnNumber</name>
      <anchor>a3</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getLineNumber</name>
      <anchor>a4</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const ACEXML_Char *</type>
      <name>getPublicId</name>
      <anchor>a5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const ACEXML_Char *</type>
      <name>getSystemId</name>
      <anchor>a6</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setColumnNumber</name>
      <anchor>a7</anchor>
      <arglist>(int cn)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setLineNumber</name>
      <anchor>a8</anchor>
      <arglist>(int ln)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setPublicId</name>
      <anchor>a9</anchor>
      <arglist>(const ACEXML_Char *id)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>setSystemId</name>
      <anchor>a10</anchor>
      <arglist>(const ACEXML_Char *id)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>incrLineNumber</name>
      <anchor>a11</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>incrColumnNumber</name>
      <anchor>a12</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>reset</name>
      <anchor>a13</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Char *</type>
      <name>publicId_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Char *</type>
      <name>systemId_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>lineNumber_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>columnNumber_</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_Mem_Map_Stream</name>
    <filename>classACEXML__Mem__Map__Stream.html</filename>
    <member kind="function">
      <type></type>
      <name>ACEXML_Mem_Map_Stream</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>open</name>
      <anchor>a1</anchor>
      <arglist>(Connector *connector, const ACE_INET_Addr &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ACEXML_Mem_Map_Stream</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>ACE_SOCK_Stream &amp;</type>
      <name>stream</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ssize_t</type>
      <name>send_n</name>
      <anchor>a4</anchor>
      <arglist>(const void *buf, size_t size, ACE_Time_Value *tv=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>get_char</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>recv</name>
      <anchor>a6</anchor>
      <arglist>(size_t &amp;len)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>recv</name>
      <anchor>a7</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual size_t</type>
      <name>recv_len</name>
      <anchor>a8</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual size_t</type>
      <name>available</name>
      <anchor>a9</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>rewind</name>
      <anchor>a10</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>peek_char</name>
      <anchor>a11</anchor>
      <arglist>(size_t offset)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>peek_str</name>
      <anchor>a12</anchor>
      <arglist>(size_t offset, size_t size)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual off_t</type>
      <name>seek</name>
      <anchor>a13</anchor>
      <arglist>(off_t offset, int whence=SEEK_CUR)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>eof</name>
      <anchor>a14</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>Svc_Handler *</type>
      <name>svc_handler</name>
      <anchor>a15</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>int</type>
      <name>grow_file_and_remap</name>
      <anchor>c0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>Svc_Handler *</type>
      <name>svc_handler_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_Mem_Map</type>
      <name>mem_map_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>char *</type>
      <name>recv_pos_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>char *</type>
      <name>get_pos_</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>char *</type>
      <name>end_of_mapping_plus1_</name>
      <anchor>o4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_Namespace_Context_Stack</name>
    <filename>classACEXML__Namespace__Context__Stack.html</filename>
    <member kind="function">
      <type></type>
      <name>ACEXML_Namespace_Context_Stack</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~ACEXML_Namespace_Context_Stack</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>push</name>
      <anchor>a2</anchor>
      <arglist>(ACEXML_NS_CONTEXT *old)</arglist>
    </member>
    <member kind="function">
      <type>ACEXML_NS_CONTEXT *</type>
      <name>pop</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>NS_Node_T *</type>
      <name>head_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>ACEXML_Namespace_Context_Stack::NS_Node_T</name>
    <filename>structACEXML__Namespace__Context__Stack_1_1NS__Node__T.html</filename>
    <member kind="variable">
      <type>ACEXML_NS_CONTEXT *</type>
      <name>item_</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>NS_Node_T *</type>
      <name>next_</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_NamespaceSupport</name>
    <filename>classACEXML__NamespaceSupport.html</filename>
    <member kind="function">
      <type></type>
      <name>ACEXML_NamespaceSupport</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~ACEXML_NamespaceSupport</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>declarePrefix</name>
      <anchor>a2</anchor>
      <arglist>(const ACEXML_Char *prefix, const ACEXML_Char *uri)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getDeclaredPrefixes</name>
      <anchor>a3</anchor>
      <arglist>(ACEXML_STR_LIST &amp;prefixes) const</arglist>
    </member>
    <member kind="function">
      <type>const ACEXML_Char *</type>
      <name>getPrefix</name>
      <anchor>a4</anchor>
      <arglist>(const ACEXML_Char *uri) const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getPrefixes</name>
      <anchor>a5</anchor>
      <arglist>(ACEXML_STR_LIST &amp;prefixes) const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>getPrefixes</name>
      <anchor>a6</anchor>
      <arglist>(const ACEXML_Char *uri, ACEXML_STR_LIST &amp;prefixes) const</arglist>
    </member>
    <member kind="function">
      <type>const ACEXML_Char *</type>
      <name>getURI</name>
      <anchor>a7</anchor>
      <arglist>(const ACEXML_Char *prefix) const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>popContext</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>processName</name>
      <anchor>a9</anchor>
      <arglist>(const ACEXML_Char *qName, const ACEXML_Char *&amp;uri, const ACEXML_Char *&amp;name, int is_attribute) const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>pushContext</name>
      <anchor>a10</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>reset</name>
      <anchor>a11</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const ACEXML_Char *</type>
      <name>XMLNS_PREFIX</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const ACEXML_Char *</type>
      <name>XMLNS</name>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Namespace_Context_Stack</type>
      <name>ns_stack_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_NS_CONTEXT *</type>
      <name>effective_context_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_Parser</name>
    <filename>classACEXML__Parser.html</filename>
    <base>ACEXML_XMLReader</base>
    <member kind="function">
      <type></type>
      <name>ACEXML_Parser</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ACEXML_Parser</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACEXML_ContentHandler *</type>
      <name>getContentHandler</name>
      <anchor>a2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACEXML_DTDHandler *</type>
      <name>getDTDHandler</name>
      <anchor>a3</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACEXML_EntityResolver *</type>
      <name>getEntityResolver</name>
      <anchor>a4</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACEXML_ErrorHandler *</type>
      <name>getErrorHandler</name>
      <anchor>a5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getFeature</name>
      <anchor>a6</anchor>
      <arglist>(const ACEXML_Char *name ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXNotRecognizedException</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setFeature</name>
      <anchor>a7</anchor>
      <arglist>(const ACEXML_Char *name, int boolean_value ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXNotRecognizedException</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>getProperty</name>
      <anchor>a8</anchor>
      <arglist>(const ACEXML_Char *name ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXNotRecognizedException</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setProperty</name>
      <anchor>a9</anchor>
      <arglist>(const ACEXML_Char *name, void *value ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXNotRecognizedException</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>parse</name>
      <anchor>a10</anchor>
      <arglist>(ACEXML_InputSource *input ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>parse</name>
      <anchor>a11</anchor>
      <arglist>(const ACEXML_Char *systemId ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setContentHandler</name>
      <anchor>a12</anchor>
      <arglist>(ACEXML_ContentHandler *handler)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setDTDHandler</name>
      <anchor>a13</anchor>
      <arglist>(ACEXML_DTDHandler *handler)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setEntityResolver</name>
      <anchor>a14</anchor>
      <arglist>(ACEXML_EntityResolver *resolver)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setErrorHandler</name>
      <anchor>a15</anchor>
      <arglist>(ACEXML_ErrorHandler *handler)</arglist>
    </member>
    <member kind="function">
      <type>ACEXML_Char</type>
      <name>skip_whitespace</name>
      <anchor>a16</anchor>
      <arglist>(ACEXML_Char **whitespace)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>skip_whitespace_count</name>
      <anchor>a17</anchor>
      <arglist>(ACEXML_Char *peek=0)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>is_whitespace</name>
      <anchor>a18</anchor>
      <arglist>(ACEXML_Char c)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>is_whitespace_or_equal</name>
      <anchor>a19</anchor>
      <arglist>(ACEXML_Char c)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>is_nonname</name>
      <anchor>a20</anchor>
      <arglist>(ACEXML_Char c)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>skip_equal</name>
      <anchor>a21</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>get_quoted_string</name>
      <anchor>a22</anchor>
      <arglist>(ACEXML_Char *&amp;str)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>parse_processing_instruction</name>
      <anchor>a23</anchor>
      <arglist>(ACEXML_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>grok_comment</name>
      <anchor>a24</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>ACEXML_Char *</type>
      <name>read_name</name>
      <anchor>a25</anchor>
      <arglist>(ACEXML_Char ch=0)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>parse_doctypedecl</name>
      <anchor>a26</anchor>
      <arglist>(ACEXML_ENV_SINGLE_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>parse_element</name>
      <anchor>a27</anchor>
      <arglist>(int is_root ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>parse_xml_prolog</name>
      <anchor>a28</anchor>
      <arglist>(ACEXML_ENV_SINGLE_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>parse_char_reference</name>
      <anchor>a29</anchor>
      <arglist>(ACEXML_Char *buf, size_t len)</arglist>
    </member>
    <member kind="function">
      <type>const ACEXML_String *</type>
      <name>parse_reference</name>
      <anchor>a30</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>parse_cdata</name>
      <anchor>a31</anchor>
      <arglist>(ACEXML_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>parse_internal_dtd</name>
      <anchor>a32</anchor>
      <arglist>(ACEXML_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>parse_element_decl</name>
      <anchor>a33</anchor>
      <arglist>(ACEXML_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>parse_entity_decl</name>
      <anchor>a34</anchor>
      <arglist>(ACEXML_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>parse_attlist_decl</name>
      <anchor>a35</anchor>
      <arglist>(ACEXML_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>parse_notation_decl</name>
      <anchor>a36</anchor>
      <arglist>(ACEXML_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>parse_external_id_and_ref</name>
      <anchor>a37</anchor>
      <arglist>(ACEXML_Char *&amp;publicId, ACEXML_Char *&amp;systemId ACEXML_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>parse_children_definition</name>
      <anchor>a38</anchor>
      <arglist>(ACEXML_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>parse_child</name>
      <anchor>a39</anchor>
      <arglist>(int skip_open_paren ACEXML_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="variable">
      <type>virtual int</type>
      <name>ACEXML_SAXNotSupportedException</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>virtual void</type>
      <name>ACEXML_SAXNotSupportedException</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>virtual void *</type>
      <name>ACEXML_SAXNotSupportedException</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="public">
      <type>ACEXML_Char</type>
      <name>get</name>
      <anchor>b0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>ACEXML_Char</type>
      <name>peek</name>
      <anchor>b1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>try_grow_cdata</name>
      <anchor>b2</anchor>
      <arglist>(size_t size, size_t &amp;len ACEXML_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="variable" protection="public" static="yes">
      <type>const ACEXML_Char</type>
      <name>simple_parsing_feature_</name>
      <anchor>a0</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable" protection="public" static="yes">
      <type>const ACEXML_Char</type>
      <name>namespaces_feature_</name>
      <anchor>a1</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable" protection="public" static="yes">
      <type>const ACEXML_Char</type>
      <name>namespace_prefixes_feature_</name>
      <anchor>a2</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>report_error</name>
      <anchor>c0</anchor>
      <arglist>(const ACEXML_Char *message ACEXML_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>report_warning</name>
      <anchor>c1</anchor>
      <arglist>(const ACEXML_Char *message ACEXML_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>report_fatal_error</name>
      <anchor>c2</anchor>
      <arglist>(const ACEXML_Char *message ACEXML_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>report_prefix_mapping</name>
      <anchor>c3</anchor>
      <arglist>(const ACEXML_Char *prefix, const ACEXML_Char *uri, const ACEXML_Char *name, int start ACEXML_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>int</type>
      <name>parse_token</name>
      <anchor>c4</anchor>
      <arglist>(const ACEXML_Char *keyword)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_DTDHandler *</type>
      <name>dtd_handler_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_EntityResolver *</type>
      <name>entity_resolver_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_ContentHandler *</type>
      <name>content_handler_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_ErrorHandler *</type>
      <name>error_handler_</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_CharStream *</type>
      <name>instream_</name>
      <anchor>o4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Char *</type>
      <name>doctype_</name>
      <anchor>o5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Char *</type>
      <name>dtd_system_</name>
      <anchor>o6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Char *</type>
      <name>dtd_public_</name>
      <anchor>o7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_Obstack_T&lt; ACEXML_Char &gt;</type>
      <name>obstack_</name>
      <anchor>o8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_NamespaceSupport</type>
      <name>xml_namespace_</name>
      <anchor>o9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Entity_Manager</type>
      <name>entities_</name>
      <anchor>o10</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_LocatorImpl</type>
      <name>locator_</name>
      <anchor>o11</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>simple_parsing_</name>
      <anchor>o12</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>namespaces_</name>
      <anchor>o13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>namespace_prefixes_</name>
      <anchor>o14</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_Print_Handler</name>
    <filename>classACEXML__Print__Handler.html</filename>
    <base>ACEXML_DefaultHandler</base>
    <member kind="function">
      <type></type>
      <name>ACEXML_Print_Handler</name>
      <anchor>a0</anchor>
      <arglist>(ACEXML_Char *fileName)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ACEXML_Print_Handler</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>characters</name>
      <anchor>a2</anchor>
      <arglist>(const ACEXML_Char *ch, int start, int length ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>endDocument</name>
      <anchor>a3</anchor>
      <arglist>(ACEXML_ENV_SINGLE_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>endElement</name>
      <anchor>a4</anchor>
      <arglist>(const ACEXML_Char *namespaceURI, const ACEXML_Char *localName, const ACEXML_Char *qName ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>endPrefixMapping</name>
      <anchor>a5</anchor>
      <arglist>(const ACEXML_Char *prefix ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>ignorableWhitespace</name>
      <anchor>a6</anchor>
      <arglist>(const ACEXML_Char *ch, int start, int length ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>processingInstruction</name>
      <anchor>a7</anchor>
      <arglist>(const ACEXML_Char *target, const ACEXML_Char *data ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setDocumentLocator</name>
      <anchor>a8</anchor>
      <arglist>(ACEXML_Locator *locator)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>skippedEntity</name>
      <anchor>a9</anchor>
      <arglist>(const ACEXML_Char *name ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>startDocument</name>
      <anchor>a10</anchor>
      <arglist>(ACEXML_ENV_SINGLE_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>startElement</name>
      <anchor>a11</anchor>
      <arglist>(const ACEXML_Char *namespaceURI, const ACEXML_Char *localName, const ACEXML_Char *qName, ACEXML_Attributes *atts ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>startPrefixMapping</name>
      <anchor>a12</anchor>
      <arglist>(const ACEXML_Char *prefix, const ACEXML_Char *uri ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>notationDecl</name>
      <anchor>a13</anchor>
      <arglist>(const ACEXML_Char *name, const ACEXML_Char *publicId, const ACEXML_Char *systemId ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>unparsedEntityDecl</name>
      <anchor>a14</anchor>
      <arglist>(const ACEXML_Char *name, const ACEXML_Char *publicId, const ACEXML_Char *systemId, const ACEXML_Char *notationName ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACEXML_InputSource *</type>
      <name>resolveEntity</name>
      <anchor>a15</anchor>
      <arglist>(const ACEXML_Char *publicId, const ACEXML_Char *systemId ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>error</name>
      <anchor>a16</anchor>
      <arglist>(ACEXML_SAXParseException &amp;exception ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>fatalError</name>
      <anchor>a17</anchor>
      <arglist>(ACEXML_SAXParseException &amp;exception ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>warning</name>
      <anchor>a18</anchor>
      <arglist>(ACEXML_SAXParseException &amp;exception ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Char *</type>
      <name>fileName_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Locator *</type>
      <name>locator_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_SAXException</name>
    <filename>classACEXML__SAXException.html</filename>
    <base>ACEXML_Exception</base>
    <member kind="function">
      <type></type>
      <name>ACEXML_SAXException</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACEXML_SAXException</name>
      <anchor>a1</anchor>
      <arglist>(const ACEXML_Char *msg)</arglist>
    </member>
    <member kind="function">
      <type>ACEXML_SAXException &amp;</type>
      <name>operator=</name>
      <anchor>a2</anchor>
      <arglist>(const ACEXML_SAXException &amp;src)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACEXML_SAXException</name>
      <anchor>a3</anchor>
      <arglist>(const ACEXML_SAXException &amp;ex)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ACEXML_SAXException</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_raise</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const ACEXML_Char *</type>
      <name>id</name>
      <anchor>a6</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const ACEXML_Char *</type>
      <name>message</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACEXML_Exception *</type>
      <name>duplicate</name>
      <anchor>a8</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>is_a</name>
      <anchor>a9</anchor>
      <arglist>(const ACEXML_Char *name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>print</name>
      <anchor>a10</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>ACEXML_SAXException *</type>
      <name>_downcast</name>
      <anchor>d0</anchor>
      <arglist>(ACEXML_Exception *ex)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACEXML_Char *</type>
      <name>message_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public" static="yes">
      <type>const ACEXML_Char *</type>
      <name>exception_name_</name>
      <anchor>q0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_SAXNotRecognizedException</name>
    <filename>classACEXML__SAXNotRecognizedException.html</filename>
    <base>ACEXML_SAXException</base>
    <member kind="function">
      <type></type>
      <name>ACEXML_SAXNotRecognizedException</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACEXML_SAXNotRecognizedException</name>
      <anchor>a1</anchor>
      <arglist>(const ACEXML_Char *msg)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACEXML_SAXNotRecognizedException</name>
      <anchor>a2</anchor>
      <arglist>(const ACEXML_SAXNotRecognizedException &amp;ex)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ACEXML_SAXNotRecognizedException</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_raise</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const ACEXML_Char *</type>
      <name>id</name>
      <anchor>a5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACEXML_Exception *</type>
      <name>duplicate</name>
      <anchor>a6</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>is_a</name>
      <anchor>a7</anchor>
      <arglist>(const ACEXML_Char *name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>print</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>ACEXML_SAXNotRecognizedException *</type>
      <name>_downcast</name>
      <anchor>d0</anchor>
      <arglist>(ACEXML_Exception *ex)</arglist>
    </member>
    <member kind="variable" protection="public" static="yes">
      <type>const ACEXML_Char *</type>
      <name>exception_name_</name>
      <anchor>q0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_SAXNotSupportedException</name>
    <filename>classACEXML__SAXNotSupportedException.html</filename>
    <base>ACEXML_SAXException</base>
    <member kind="function">
      <type></type>
      <name>ACEXML_SAXNotSupportedException</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACEXML_SAXNotSupportedException</name>
      <anchor>a1</anchor>
      <arglist>(const ACEXML_SAXNotSupportedException &amp;ex)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACEXML_SAXNotSupportedException</name>
      <anchor>a2</anchor>
      <arglist>(const ACEXML_Char *msg)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ACEXML_SAXNotSupportedException</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_raise</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const ACEXML_Char *</type>
      <name>id</name>
      <anchor>a5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACEXML_Exception *</type>
      <name>duplicate</name>
      <anchor>a6</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>is_a</name>
      <anchor>a7</anchor>
      <arglist>(const ACEXML_Char *name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>print</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>ACEXML_SAXNotSupportedException *</type>
      <name>_downcast</name>
      <anchor>d0</anchor>
      <arglist>(ACEXML_Exception *ex)</arglist>
    </member>
    <member kind="variable" protection="public" static="yes">
      <type>const ACEXML_Char *</type>
      <name>exception_name_</name>
      <anchor>q0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_SAXParseException</name>
    <filename>classACEXML__SAXParseException.html</filename>
    <base>ACEXML_SAXException</base>
    <member kind="function">
      <type></type>
      <name>ACEXML_SAXParseException</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACEXML_SAXParseException</name>
      <anchor>a1</anchor>
      <arglist>(const ACEXML_Char *msg)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACEXML_SAXParseException</name>
      <anchor>a2</anchor>
      <arglist>(const ACEXML_SAXParseException &amp;ex)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ACEXML_SAXParseException</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>_raise</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const ACEXML_Char *</type>
      <name>id</name>
      <anchor>a5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACEXML_Exception *</type>
      <name>duplicate</name>
      <anchor>a6</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>is_a</name>
      <anchor>a7</anchor>
      <arglist>(const ACEXML_Char *name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>print</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>ACEXML_SAXParseException *</type>
      <name>_downcast</name>
      <anchor>d0</anchor>
      <arglist>(ACEXML_Exception *ex)</arglist>
    </member>
    <member kind="variable" protection="public" static="yes">
      <type>const ACEXML_Char *</type>
      <name>exception_name_</name>
      <anchor>q0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_SAXPrint_Handler</name>
    <filename>classACEXML__SAXPrint__Handler.html</filename>
    <base>ACEXML_DefaultHandler</base>
    <member kind="function">
      <type></type>
      <name>ACEXML_SAXPrint_Handler</name>
      <anchor>a0</anchor>
      <arglist>(const ACEXML_Char *name)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ACEXML_SAXPrint_Handler</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>characters</name>
      <anchor>a2</anchor>
      <arglist>(const ACEXML_Char *ch, int start, int length ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>endDocument</name>
      <anchor>a3</anchor>
      <arglist>(ACEXML_ENV_SINGLE_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>endElement</name>
      <anchor>a4</anchor>
      <arglist>(const ACEXML_Char *namespaceURI, const ACEXML_Char *localName, const ACEXML_Char *qName ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>endPrefixMapping</name>
      <anchor>a5</anchor>
      <arglist>(const ACEXML_Char *prefix ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>ignorableWhitespace</name>
      <anchor>a6</anchor>
      <arglist>(const ACEXML_Char *ch, int start, int length ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>processingInstruction</name>
      <anchor>a7</anchor>
      <arglist>(const ACEXML_Char *target, const ACEXML_Char *data ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setDocumentLocator</name>
      <anchor>a8</anchor>
      <arglist>(ACEXML_Locator *locator)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>skippedEntity</name>
      <anchor>a9</anchor>
      <arglist>(const ACEXML_Char *name ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>startDocument</name>
      <anchor>a10</anchor>
      <arglist>(ACEXML_ENV_SINGLE_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>startElement</name>
      <anchor>a11</anchor>
      <arglist>(const ACEXML_Char *namespaceURI, const ACEXML_Char *localName, const ACEXML_Char *qName, ACEXML_Attributes *atts ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>startPrefixMapping</name>
      <anchor>a12</anchor>
      <arglist>(const ACEXML_Char *prefix, const ACEXML_Char *uri ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>notationDecl</name>
      <anchor>a13</anchor>
      <arglist>(const ACEXML_Char *name, const ACEXML_Char *publicId, const ACEXML_Char *systemId ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>unparsedEntityDecl</name>
      <anchor>a14</anchor>
      <arglist>(const ACEXML_Char *name, const ACEXML_Char *publicId, const ACEXML_Char *systemId, const ACEXML_Char *notationName ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACEXML_InputSource *</type>
      <name>resolveEntity</name>
      <anchor>a15</anchor>
      <arglist>(const ACEXML_Char *publicId, const ACEXML_Char *systemId ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>error</name>
      <anchor>a16</anchor>
      <arglist>(ACEXML_SAXParseException &amp;exception ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>fatalError</name>
      <anchor>a17</anchor>
      <arglist>(ACEXML_SAXParseException &amp;exception ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>warning</name>
      <anchor>a18</anchor>
      <arglist>(ACEXML_SAXParseException &amp;exception ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>inc_indent</name>
      <anchor>a19</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>dec_indent</name>
      <anchor>a20</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>print_indent</name>
      <anchor>a21</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>size_t</type>
      <name>indent_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Char *</type>
      <name>fileName_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Locator *</type>
      <name>locator_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_StrCharStream</name>
    <filename>classACEXML__StrCharStream.html</filename>
    <base>ACEXML_CharStream</base>
    <member kind="function">
      <type></type>
      <name>ACEXML_StrCharStream</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACEXML_StrCharStream</name>
      <anchor>a1</anchor>
      <arglist>(const ACEXML_Char *str)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ACEXML_StrCharStream</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>open</name>
      <anchor>a3</anchor>
      <arglist>(const ACEXML_Char *str)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>available</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>close</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>determine_encoding</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>get</name>
      <anchor>a7</anchor>
      <arglist>(ACEXML_Char &amp;ch)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>read</name>
      <anchor>a8</anchor>
      <arglist>(ACEXML_Char *str, size_t len)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>peek</name>
      <anchor>a9</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const ACEXML_Char *</type>
      <name>getEncoding</name>
      <anchor>a10</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>rewind</name>
      <anchor>a11</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Char *</type>
      <name>start_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Char *</type>
      <name>ptr_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Char *</type>
      <name>end_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Char *</type>
      <name>encoding_</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_StreamFactory</name>
    <filename>classACEXML__StreamFactory.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ACEXML_StreamFactory</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACEXML_CharStream *</type>
      <name>create_stream</name>
      <anchor>a1</anchor>
      <arglist>(const ACEXML_Char *uri)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_Svcconf_Handler</name>
    <filename>classACEXML__Svcconf__Handler.html</filename>
    <base>ACEXML_DefaultHandler</base>
    <member kind="function">
      <type></type>
      <name>ACEXML_Svcconf_Handler</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ACEXML_Svcconf_Handler</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>characters</name>
      <anchor>a2</anchor>
      <arglist>(const ACEXML_Char *ch, int start, int length ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>endDocument</name>
      <anchor>a3</anchor>
      <arglist>(ACEXML_ENV_SINGLE_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>endElement</name>
      <anchor>a4</anchor>
      <arglist>(const ACEXML_Char *namespaceURI, const ACEXML_Char *localName, const ACEXML_Char *qName ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>endPrefixMapping</name>
      <anchor>a5</anchor>
      <arglist>(const ACEXML_Char *prefix ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>ignorableWhitespace</name>
      <anchor>a6</anchor>
      <arglist>(const ACEXML_Char *ch, int start, int length ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>processingInstruction</name>
      <anchor>a7</anchor>
      <arglist>(const ACEXML_Char *target, const ACEXML_Char *data ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setDocumentLocator</name>
      <anchor>a8</anchor>
      <arglist>(ACEXML_Locator *)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>skippedEntity</name>
      <anchor>a9</anchor>
      <arglist>(const ACEXML_Char *name ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>startDocument</name>
      <anchor>a10</anchor>
      <arglist>(ACEXML_ENV_SINGLE_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>startElement</name>
      <anchor>a11</anchor>
      <arglist>(const ACEXML_Char *namespaceURI, const ACEXML_Char *localName, const ACEXML_Char *qName, ACEXML_Attributes *atts ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>startPrefixMapping</name>
      <anchor>a12</anchor>
      <arglist>(const ACEXML_Char *prefix, const ACEXML_Char *uri ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>notationDecl</name>
      <anchor>a13</anchor>
      <arglist>(const ACEXML_Char *name, const ACEXML_Char *publicId, const ACEXML_Char *systemId ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>unparsedEntityDecl</name>
      <anchor>a14</anchor>
      <arglist>(const ACEXML_Char *name, const ACEXML_Char *publicId, const ACEXML_Char *systemId, const ACEXML_Char *notationName ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACEXML_InputSource *</type>
      <name>resolveEntity</name>
      <anchor>a15</anchor>
      <arglist>(const ACEXML_Char *publicId, const ACEXML_Char *systemId ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>error</name>
      <anchor>a16</anchor>
      <arglist>(ACEXML_SAXParseException &amp;exception ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>fatalError</name>
      <anchor>a17</anchor>
      <arglist>(ACEXML_SAXParseException &amp;exception ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>warning</name>
      <anchor>a18</anchor>
      <arglist>(ACEXML_SAXParseException &amp;exception ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>get_stream_id</name>
      <anchor>b0</anchor>
      <arglist>(ACEXML_Attributes *alist ACEXML_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>get_id</name>
      <anchor>b1</anchor>
      <arglist>(ACEXML_Attributes *alist ACEXML_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>get_dynamic_attrs</name>
      <anchor>b2</anchor>
      <arglist>(ACEXML_Attributes *alist ACEXML_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>get_initializer_attrs</name>
      <anchor>b3</anchor>
      <arglist>(ACEXML_Attributes *alist ACEXML_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>get_static_attrs</name>
      <anchor>b4</anchor>
      <arglist>(ACEXML_Attributes *alist ACEXML_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>in_stream_def_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>in_module_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_Parsed_Info</type>
      <name>parsed_info_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_Parsed_Info</type>
      <name>stream_info_</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_Transcoder</name>
    <filename>classACEXML__Transcoder.html</filename>
    <member kind="enumvalue">
      <name>SUCCESS</name>
      <anchor>s6s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>DESTINATION_TOO_SHORT</name>
      <anchor>s6s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>END_OF_SOURCE</name>
      <anchor>s6s2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>INVALID_ARGS</name>
      <anchor>s6s3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>IS_SURROGATE</name>
      <anchor>s6s4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>NON_UNICODE</name>
      <anchor>s6s5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" static="yes">
      <type>int</type>
      <name>utf162utf8</name>
      <anchor>d0</anchor>
      <arglist>(ACEXML_UTF16 src, ACEXML_UTF8 *dst, size_t len)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>int</type>
      <name>ucs42utf8</name>
      <anchor>d1</anchor>
      <arglist>(ACEXML_UCS4 src, ACEXML_UTF8 *dst, size_t len)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>int</type>
      <name>ucs42utf16</name>
      <anchor>d2</anchor>
      <arglist>(ACEXML_UCS4 src, ACEXML_UTF16 *dst, size_t len)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>int</type>
      <name>surrogate2utf8</name>
      <anchor>d3</anchor>
      <arglist>(ACEXML_UTF16 high, ACEXML_UTF16 low, ACEXML_UTF8 *dst, size_t len)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>int</type>
      <name>surrogate2ucs4</name>
      <anchor>d4</anchor>
      <arglist>(ACEXML_UTF16 high, ACEXML_UTF16 low, ACEXML_UCS4 &amp;dst)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>int</type>
      <name>utf82ucs4</name>
      <anchor>d5</anchor>
      <arglist>(const ACEXML_UTF8 *src, size_t len, ACEXML_UCS4 &amp;dst)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>int</type>
      <name>utf162ucs4</name>
      <anchor>d6</anchor>
      <arglist>(const ACEXML_UTF16 *src, size_t len, ACEXML_UCS4 &amp;dst)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>int</type>
      <name>utf8s2utf16s</name>
      <anchor>d7</anchor>
      <arglist>(const ACEXML_UTF8 *src, ACEXML_UTF16 *dst, size_t len)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>int</type>
      <name>utf16s2utf8s</name>
      <anchor>d8</anchor>
      <arglist>(const ACEXML_UTF16 *src, ACEXML_UTF8 *dst, size_t len)</arglist>
    </member>
    <member kind="variable">
      <type>enum ACEXML_Transcoder::@1</type>
      <name>STATUS</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_URL_Addr</name>
    <filename>classACEXML__URL__Addr.html</filename>
    <base>ACE_INET_Addr</base>
    <member kind="function">
      <type></type>
      <name>ACEXML_URL_Addr</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACEXML_URL_Addr</name>
      <anchor>a1</anchor>
      <arglist>(const ACEXML_Char *host_name, const ACEXML_Char *path_name, unsigned short port=ACE_DEFAULT_HTTP_PORT)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACEXML_URL_Addr</name>
      <anchor>a2</anchor>
      <arglist>(const ACEXML_URL_Addr &amp;addr)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>set</name>
      <anchor>a3</anchor>
      <arglist>(const ACEXML_URL_Addr &amp;addr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>string_to_addr</name>
      <anchor>a4</anchor>
      <arglist>(const ACEXML_Char *address)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>addr_to_string</name>
      <anchor>a5</anchor>
      <arglist>(ACEXML_Char *s, size_t size, int ipaddr_format=1) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const ACEXML_Char *</type>
      <name>addr_to_string</name>
      <anchor>a6</anchor>
      <arglist>(int ipaddr_format=1)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchor>a7</anchor>
      <arglist>(const ACEXML_URL_Addr &amp;addr)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~ACEXML_URL_Addr</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>operator==</name>
      <anchor>a9</anchor>
      <arglist>(const ACEXML_URL_Addr &amp;SAP) const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>operator!=</name>
      <anchor>a10</anchor>
      <arglist>(const ACEXML_URL_Addr &amp;SAP) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual u_long</type>
      <name>hash</name>
      <anchor>a11</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const ACEXML_Char *</type>
      <name>get_path_name</name>
      <anchor>a12</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>destroy</name>
      <anchor>a13</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>size_t</type>
      <name>calculate_length</name>
      <anchor>c0</anchor>
      <arglist>(int ipaddr_format) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Char *</type>
      <name>path_name_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Char *</type>
      <name>addr_string_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>size_t</type>
      <name>addr_string_len_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_Validator</name>
    <filename>classACEXML__Validator.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual</type>
      <name>~ACEXML_Validator</name>
      <anchor>a0</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>startElement</name>
      <anchor>a1</anchor>
      <arglist>(ACEXML_Attributes *atts ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>nextElement</name>
      <anchor>a2</anchor>
      <arglist>(const ACEXML_Char *namespaceURI, const ACEXML_Char *localName, const ACEXML_Char *qName ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_XMLFilter</name>
    <filename>classACEXML__XMLFilter.html</filename>
    <base>ACEXML_XMLReader</base>
    <member kind="function" virtualness="pure">
      <type>virtual ACEXML_XMLReader *</type>
      <name>getParent</name>
      <anchor>a0</anchor>
      <arglist>(void) const=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>setParent</name>
      <anchor>a1</anchor>
      <arglist>(ACEXML_XMLReader *parent)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_XMLFilterImpl</name>
    <filename>classACEXML__XMLFilterImpl.html</filename>
    <base>ACEXML_XMLFilter</base>
    <base>ACEXML_ContentHandler</base>
    <base>ACEXML_DTDHandler</base>
    <base>ACEXML_EntityResolver</base>
    <base>ACEXML_ErrorHandler</base>
    <member kind="function">
      <type></type>
      <name>ACEXML_XMLFilterImpl</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACEXML_XMLFilterImpl</name>
      <anchor>a1</anchor>
      <arglist>(ACEXML_XMLReader *parent)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~ACEXML_XMLFilterImpl</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getFeature</name>
      <anchor>a3</anchor>
      <arglist>(const ACEXML_Char *name ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXNotRecognizedException</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>getProperty</name>
      <anchor>a4</anchor>
      <arglist>(const ACEXML_Char *name ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXNotRecognizedException</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>parse</name>
      <anchor>a5</anchor>
      <arglist>(ACEXML_InputSource *input ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>parse</name>
      <anchor>a6</anchor>
      <arglist>(const ACEXML_Char *systemId ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setFeature</name>
      <anchor>a7</anchor>
      <arglist>(const ACEXML_Char *name, int boolean_value ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXNotRecognizedException</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setProperty</name>
      <anchor>a8</anchor>
      <arglist>(const ACEXML_Char *name, void *value ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXNotRecognizedException</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACEXML_XMLReader *</type>
      <name>getParent</name>
      <anchor>a9</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setParent</name>
      <anchor>a10</anchor>
      <arglist>(ACEXML_XMLReader *parent)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACEXML_DTDHandler *</type>
      <name>getDTDHandler</name>
      <anchor>a11</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACEXML_ContentHandler *</type>
      <name>getContentHandler</name>
      <anchor>a12</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACEXML_EntityResolver *</type>
      <name>getEntityResolver</name>
      <anchor>a13</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACEXML_ErrorHandler *</type>
      <name>getErrorHandler</name>
      <anchor>a14</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setDTDHandler</name>
      <anchor>a15</anchor>
      <arglist>(ACEXML_DTDHandler *handler)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setContentHandler</name>
      <anchor>a16</anchor>
      <arglist>(ACEXML_ContentHandler *handler)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setEntityResolver</name>
      <anchor>a17</anchor>
      <arglist>(ACEXML_EntityResolver *handler)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setErrorHandler</name>
      <anchor>a18</anchor>
      <arglist>(ACEXML_ErrorHandler *handler)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>characters</name>
      <anchor>a19</anchor>
      <arglist>(const ACEXML_Char *ch, int start, int length ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>endDocument</name>
      <anchor>a20</anchor>
      <arglist>(ACEXML_ENV_SINGLE_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>endElement</name>
      <anchor>a21</anchor>
      <arglist>(const ACEXML_Char *namespaceURI, const ACEXML_Char *localName, const ACEXML_Char *qName ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>endPrefixMapping</name>
      <anchor>a22</anchor>
      <arglist>(const ACEXML_Char *prefix ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>ignorableWhitespace</name>
      <anchor>a23</anchor>
      <arglist>(const ACEXML_Char *ch, int start, int length ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>processingInstruction</name>
      <anchor>a24</anchor>
      <arglist>(const ACEXML_Char *target, const ACEXML_Char *data ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setDocumentLocator</name>
      <anchor>a25</anchor>
      <arglist>(ACEXML_Locator *locator)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>skippedEntity</name>
      <anchor>a26</anchor>
      <arglist>(const ACEXML_Char *name ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>startDocument</name>
      <anchor>a27</anchor>
      <arglist>(ACEXML_ENV_SINGLE_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>startElement</name>
      <anchor>a28</anchor>
      <arglist>(const ACEXML_Char *namespaceURI, const ACEXML_Char *localName, const ACEXML_Char *qName, ACEXML_Attributes *atts ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>startPrefixMapping</name>
      <anchor>a29</anchor>
      <arglist>(const ACEXML_Char *prefix, const ACEXML_Char *uri ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>notationDecl</name>
      <anchor>a30</anchor>
      <arglist>(const ACEXML_Char *name, const ACEXML_Char *publicId, const ACEXML_Char *systemId ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>unparsedEntityDecl</name>
      <anchor>a31</anchor>
      <arglist>(const ACEXML_Char *name, const ACEXML_Char *publicId, const ACEXML_Char *systemId, const ACEXML_Char *notationName ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACEXML_InputSource *</type>
      <name>resolveEntity</name>
      <anchor>a32</anchor>
      <arglist>(const ACEXML_Char *publicId, const ACEXML_Char *systemId ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>error</name>
      <anchor>a33</anchor>
      <arglist>(ACEXML_SAXParseException &amp;exception ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>fatalError</name>
      <anchor>a34</anchor>
      <arglist>(ACEXML_SAXParseException &amp;exception ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>warning</name>
      <anchor>a35</anchor>
      <arglist>(ACEXML_SAXParseException &amp;exception ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))</arglist>
    </member>
    <member kind="variable">
      <type>virtual int</type>
      <name>ACEXML_SAXNotSupportedException</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>virtual void *</type>
      <name>ACEXML_SAXNotSupportedException</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>virtual void</type>
      <name>ACEXML_SAXNotSupportedException</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>setupParser</name>
      <anchor>b0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_XMLReader *</type>
      <name>parent_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_Locator *</type>
      <name>locator_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_EntityResolver *</type>
      <name>entityResolver_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_DTDHandler *</type>
      <name>dtdHandler_</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_ContentHandler *</type>
      <name>contentHandler_</name>
      <anchor>o4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACEXML_ErrorHandler *</type>
      <name>errorHandler_</name>
      <anchor>o5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>ACEXML_XMLReader</name>
    <filename>classACEXML__XMLReader.html</filename>
    <member kind="function" virtualness="pure">
      <type>virtual ACEXML_ContentHandler *</type>
      <name>getContentHandler</name>
      <anchor>a0</anchor>
      <arglist>(void) const=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual ACEXML_DTDHandler *</type>
      <name>getDTDHandler</name>
      <anchor>a1</anchor>
      <arglist>(void) const=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual ACEXML_EntityResolver *</type>
      <name>getEntityResolver</name>
      <anchor>a2</anchor>
      <arglist>(void) const=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual ACEXML_ErrorHandler *</type>
      <name>getErrorHandler</name>
      <anchor>a3</anchor>
      <arglist>(void) const=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>getFeature</name>
      <anchor>a4</anchor>
      <arglist>(const ACEXML_Char *name ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXNotRecognizedException</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void *</type>
      <name>getProperty</name>
      <anchor>a5</anchor>
      <arglist>(const ACEXML_Char *name ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXNotRecognizedException</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>parse</name>
      <anchor>a6</anchor>
      <arglist>(ACEXML_InputSource *input ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>parse</name>
      <anchor>a7</anchor>
      <arglist>(const ACEXML_Char *systemId ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXException))=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>setContentHandler</name>
      <anchor>a8</anchor>
      <arglist>(ACEXML_ContentHandler *handler)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>setDTDHandler</name>
      <anchor>a9</anchor>
      <arglist>(ACEXML_DTDHandler *handler)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>setEntityResolver</name>
      <anchor>a10</anchor>
      <arglist>(ACEXML_EntityResolver *resolver)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>setErrorHandler</name>
      <anchor>a11</anchor>
      <arglist>(ACEXML_ErrorHandler *handler)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setFeature</name>
      <anchor>a12</anchor>
      <arglist>(const ACEXML_Char *name, int boolean_value ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXNotRecognizedException</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>setProperty</name>
      <anchor>a13</anchor>
      <arglist>(const ACEXML_Char *name, void *value ACEXML_ENV_ARG_DECL) ACE_THROW_SPEC((ACEXML_SAXNotRecognizedException</arglist>
    </member>
    <member kind="variable">
      <type>virtual int</type>
      <name>ACEXML_SAXNotSupportedException</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>virtual void *</type>
      <name>ACEXML_SAXNotSupportedException</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>virtual void</type>
      <name>ACEXML_SAXNotSupportedException</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="page">
    <name>acexml_bugs</name>
    <title>ACEXML Known Bugs</title>
    <filename>acexml_bugs</filename>
  </compound>
  <compound kind="page">
    <name>acexml_guides</name>
    <title>ACEXML Programming Guidelines</title>
    <filename>acexml_guides</filename>
  </compound>
  <compound kind="page">
    <name>acexml_todo</name>
    <title>ACEXML TO-DO List</title>
    <filename>acexml_todo</filename>
  </compound>
  <compound kind="group">
    <name>acexml_parser_features</name>
    <title>Configurable Special Features of ACEXML Parser</title>
    <filename>group__acexml__parser__features.html</filename>
    <member kind="variable" protection="public" static="yes">
      <type>const ACEXML_Char</type>
      <name>simple_parsing_feature_</name>
      <anchor>a0</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable" protection="public" static="yes">
      <type>const ACEXML_Char</type>
      <name>namespaces_feature_</name>
      <anchor>a1</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable" protection="public" static="yes">
      <type>const ACEXML_Char</type>
      <name>namespace_prefixes_feature_</name>
      <anchor>a2</anchor>
      <arglist>[]</arglist>
    </member>
  </compound>
</tagfile>
