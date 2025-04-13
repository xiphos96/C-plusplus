<?xml version='1.0' encoding='ISO-8859-1' standalone='yes'?>
<tagfile>
  <compound kind="file">
    <name>advanced_resource.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>advanced__resource_8cpp.html</filename>
    <member kind="typedef">
      <type>ACE_Malloc&lt; ACE_LOCAL_MEMORY_POOL, ACE_Null_Mutex &gt;</type>
      <name>NULL_LOCK_MALLOC</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Allocator_Adapter&lt; NULL_LOCK_MALLOC &gt;</type>
      <name>NULL_LOCK_ALLOCATOR</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Malloc&lt; ACE_LOCAL_MEMORY_POOL, TAO_SYNCH_MUTEX &gt;</type>
      <name>LOCKED_MALLOC</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Allocator_Adapter&lt; LOCKED_MALLOC &gt;</type>
      <name>LOCKED_ALLOCATOR</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_Strategies_advanced_resource</name>
      <anchor>a5</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACE_STATIC_SVC_DEFINE</name>
      <anchor>a6</anchor>
      <arglist>(TAO_Advanced_Resource_Factory, ACE_LIB_TEXT(&quot;Advanced_Resource_Factory&quot;), ACE_SVC_OBJ_T,&amp;ACE_SVC_NAME(TAO_Advanced_Resource_Factory), ACE_Service_Type::DELETE_THIS|ACE_Service_Type::DELETE_OBJ, 0) ACE_FACTORY_DEFINE(TAO_Strategies</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_Strategies_advanced_resource</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>advanced_resource.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>advanced__resource_8h.html</filename>
    <class kind="class">TAO_Advanced_Resource_Factory</class>
    <class kind="class">TAO_Resource_Factory_Changer</class>
    <member kind="function">
      <type></type>
      <name>ACE_STATIC_SVC_DECLARE_EXPORT</name>
      <anchor>a1</anchor>
      <arglist>(TAO_Strategies, TAO_Advanced_Resource_Factory) ACE_FACTORY_DECLARE(TAO_Strategies</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>TAO_Advanced_Resource_Factory TAO_Resource_Factory_Changer</type>
      <name>TAO_changer</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>advanced_resource.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>advanced__resource_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>DIOP_Acceptor.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>DIOP__Acceptor_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_tao_DIOP_Acceptor</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_tao_DIOP_Acceptor</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>DIOP_Acceptor.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>DIOP__Acceptor_8h.html</filename>
    <class kind="class">TAO_DIOP_Acceptor</class>
  </compound>
  <compound kind="file">
    <name>DIOP_Acceptor.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>DIOP__Acceptor_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>DIOP_Connection_Handler.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>DIOP__Connection__Handler_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_tao_DIOP_Connect</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_tao_DIOP_Connect</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>DIOP_Connection_Handler.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>DIOP__Connection__Handler_8h.html</filename>
    <class kind="class">TAO_DIOP_Connection_Handler</class>
    <class kind="class">TAO_DIOP_Properties</class>
  </compound>
  <compound kind="file">
    <name>DIOP_Connection_Handler.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>DIOP__Connection__Handler_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>DIOP_Connector.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>DIOP__Connector_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_DIOP_DIOP_Connector</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_DIOP_DIOP_Connector</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>DIOP_Connector.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>DIOP__Connector_8h.html</filename>
    <class kind="class">TAO_DIOP_Connector</class>
  </compound>
  <compound kind="file">
    <name>DIOP_Endpoint.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>DIOP__Endpoint_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_tao_DIOP_Endpoint</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_tao_DIOP_Endpoint</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>DIOP_Endpoint.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>DIOP__Endpoint_8h.html</filename>
    <class kind="class">TAO_DIOP_Endpoint</class>
  </compound>
  <compound kind="file">
    <name>DIOP_Endpoint.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>DIOP__Endpoint_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>DIOP_Factory.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>DIOP__Factory_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_TAO_Strategies_DIOP_Factory</name>
      <anchor>a2</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACE_STATIC_SVC_DEFINE</name>
      <anchor>a3</anchor>
      <arglist>(TAO_DIOP_Protocol_Factory, ACE_TEXT(&quot;DIOP_Factory&quot;), ACE_SVC_OBJ_T,&amp;ACE_SVC_NAME(TAO_DIOP_Protocol_Factory), ACE_Service_Type::DELETE_THIS|ACE_Service_Type::DELETE_OBJ, 0) ACE_FACTORY_DEFINE(TAO_Strategies</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_TAO_Strategies_DIOP_Factory</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char</type>
      <name>prefix_</name>
      <anchor>a1</anchor>
      <arglist>[]</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>DIOP_Factory.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>DIOP__Factory_8h.html</filename>
    <class kind="class">TAO_DIOP_Protocol_Factory</class>
    <member kind="function">
      <type></type>
      <name>ACE_STATIC_SVC_DECLARE</name>
      <anchor>a0</anchor>
      <arglist>(TAO_DIOP_Protocol_Factory) ACE_FACTORY_DECLARE(TAO_Strategies</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>DIOP_Profile.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>DIOP__Profile_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_DIOP_DIOP_Profile</name>
      <anchor>a2</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_DIOP_DIOP_Profile</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char</type>
      <name>prefix_</name>
      <anchor>a1</anchor>
      <arglist>[]</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>DIOP_Profile.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>DIOP__Profile_8h.html</filename>
    <class kind="class">TAO_DIOP_Profile</class>
  </compound>
  <compound kind="file">
    <name>DIOP_Profile.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>DIOP__Profile_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>DIOP_Transport.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>DIOP__Transport_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_tao_DIOP_Transport</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_tao_DIOP_Transport</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>DIOP_Transport.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>DIOP__Transport_8h.html</filename>
    <class kind="class">TAO_DIOP_Transport</class>
    <member kind="typedef">
      <type>ACE_Svc_Handler&lt; ACE_SOCK_STREAM, ACE_NULL_SYNCH &gt;</type>
      <name>TAO_DIOP_SVC_HANDLER</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>DIOP_Transport.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>DIOP__Transport_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>FIFO_Connection_Purging_Strategy.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>FIFO__Connection__Purging__Strategy_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_tao_FIFO_Connection_Purging_Strategy</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_tao_FIFO_Connection_Purging_Strategy</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>FIFO_Connection_Purging_Strategy.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>FIFO__Connection__Purging__Strategy_8h.html</filename>
    <class kind="class">TAO_FIFO_Connection_Purging_Strategy</class>
  </compound>
  <compound kind="file">
    <name>LF_Strategy_Null.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>LF__Strategy__Null_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_tao_LF_Strategy_Null</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_tao_LF_Strategy_Null</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>LF_Strategy_Null.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>LF__Strategy__Null_8h.html</filename>
    <class kind="class">TAO_LF_Strategy_Null</class>
  </compound>
  <compound kind="file">
    <name>LF_Strategy_Null.inl</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>LF__Strategy__Null_8inl.html</filename>
  </compound>
  <compound kind="file">
    <name>LFU_Connection_Purging_Strategy.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>LFU__Connection__Purging__Strategy_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_tao_LFU_Connection_Purging_Strategy</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_tao_LFU_Connection_Purging_Strategy</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>LFU_Connection_Purging_Strategy.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>LFU__Connection__Purging__Strategy_8h.html</filename>
    <class kind="class">TAO_LFU_Connection_Purging_Strategy</class>
  </compound>
  <compound kind="file">
    <name>NULL_Connection_Purging_Strategy.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>NULL__Connection__Purging__Strategy_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_tao_NULL_Connection_Purging_Strategy</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_tao_NULL_Connection_Purging_Strategy</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>NULL_Connection_Purging_Strategy.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>NULL__Connection__Purging__Strategy_8h.html</filename>
    <class kind="class">TAO_NULL_Connection_Purging_Strategy</class>
  </compound>
  <compound kind="file">
    <name>SHMIOP_Acceptor.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>SHMIOP__Acceptor_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_Strategies_SHMIOP_Acceptor</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_Strategies_SHMIOP_Acceptor</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>SHMIOP_Acceptor.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>SHMIOP__Acceptor_8h.html</filename>
    <class kind="class">TAO_SHMIOP_Acceptor</class>
  </compound>
  <compound kind="file">
    <name>SHMIOP_Acceptor.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>SHMIOP__Acceptor_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>SHMIOP_Connection_Handler.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>SHMIOP__Connection__Handler_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_Strategies_SHMIOP_Connection_Handler</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_Strategies_SHMIOP_Connection_Handler</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>SHMIOP_Connection_Handler.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>SHMIOP__Connection__Handler_8h.html</filename>
    <class kind="class">TAO_SHMIOP_Connection_Handler</class>
  </compound>
  <compound kind="file">
    <name>SHMIOP_Connection_Handler.inl</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>SHMIOP__Connection__Handler_8inl.html</filename>
  </compound>
  <compound kind="file">
    <name>SHMIOP_Connector.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>SHMIOP__Connector_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_Strategies_SHMIOP_Connector</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_Strategies_SHMIOP_Connector</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>SHMIOP_Connector.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>SHMIOP__Connector_8h.html</filename>
    <class kind="class">TAO_SHMIOP_Connector</class>
  </compound>
  <compound kind="file">
    <name>SHMIOP_Endpoint.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>SHMIOP__Endpoint_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_Strategies_SHMIOP_Endpoint</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_Strategies_SHMIOP_Endpoint</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>SHMIOP_Endpoint.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>SHMIOP__Endpoint_8h.html</filename>
    <class kind="class">TAO_SHMIOP_Endpoint</class>
  </compound>
  <compound kind="file">
    <name>SHMIOP_Endpoint.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>SHMIOP__Endpoint_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>SHMIOP_Factory.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>SHMIOP__Factory_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_Strategies_SHMIOP_Factory</name>
      <anchor>a2</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACE_STATIC_SVC_DEFINE</name>
      <anchor>a3</anchor>
      <arglist>(TAO_SHMIOP_Protocol_Factory, ACE_TEXT(&quot;SHMIOP_Factory&quot;), ACE_SVC_OBJ_T,&amp;ACE_SVC_NAME(TAO_SHMIOP_Protocol_Factory), ACE_Service_Type::DELETE_THIS|ACE_Service_Type::DELETE_OBJ, 0) ACE_FACTORY_DEFINE(TAO_Strategies</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_Strategies_SHMIOP_Factory</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char</type>
      <name>prefix_</name>
      <anchor>a1</anchor>
      <arglist>[]</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>SHMIOP_Factory.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>SHMIOP__Factory_8h.html</filename>
    <class kind="class">TAO_SHMIOP_Protocol_Factory</class>
    <member kind="function">
      <type></type>
      <name>ACE_STATIC_SVC_DECLARE</name>
      <anchor>a0</anchor>
      <arglist>(TAO_SHMIOP_Protocol_Factory) ACE_FACTORY_DECLARE(TAO_Strategies</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>SHMIOP_Profile.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>SHMIOP__Profile_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_Strategies_SHMIOP_Profile</name>
      <anchor>a2</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_Strategies_SHMIOP_Profile</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char</type>
      <name>prefix_</name>
      <anchor>a1</anchor>
      <arglist>[]</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>SHMIOP_Profile.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>SHMIOP__Profile_8h.html</filename>
    <class kind="class">TAO_SHMIOP_Profile</class>
  </compound>
  <compound kind="file">
    <name>SHMIOP_Profile.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>SHMIOP__Profile_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>SHMIOP_Transport.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>SHMIOP__Transport_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_Strategies_SHMIOP_Transport</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_Strategies_SHMIOP_Transport</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>SHMIOP_Transport.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>SHMIOP__Transport_8h.html</filename>
    <class kind="class">TAO_SHMIOP_Transport</class>
    <member kind="typedef">
      <type>ACE_Svc_Handler&lt; ACE_MEM_STREAM, ACE_NULL_SYNCH &gt;</type>
      <name>TAO_SHMIOP_SVC_HANDLER</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>SHMIOP_Transport.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>SHMIOP__Transport_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>strategies_export.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>strategies__export_8h.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>TAO_STRATEGIES_HAS_DLL</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TAO_Strategies_Export</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TAO_STRATEGIES_SINGLETON_DECLARATION</name>
      <anchor>a2</anchor>
      <arglist>(T)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TAO_STRATEGIES_SINGLETON_DECLARE</name>
      <anchor>a3</anchor>
      <arglist>(SINGLETON_TYPE, CLASS, LOCK)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>UIOP_Acceptor.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>UIOP__Acceptor_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_Strategies_UIOP_Acceptor</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_Strategies_UIOP_Acceptor</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>UIOP_Acceptor.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>UIOP__Acceptor_8h.html</filename>
    <class kind="class">TAO_UIOP_Acceptor</class>
  </compound>
  <compound kind="file">
    <name>UIOP_Connection_Handler.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>UIOP__Connection__Handler_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_Strategies_UIOP_Connection_Handler</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_Strategies_UIOP_Connection_Handler</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>UIOP_Connection_Handler.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>UIOP__Connection__Handler_8h.html</filename>
    <class kind="class">TAO_UIOP_Connection_Handler</class>
    <class kind="class">TAO_UIOP_Properties</class>
  </compound>
  <compound kind="file">
    <name>UIOP_Connection_Handler.inl</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>UIOP__Connection__Handler_8inl.html</filename>
  </compound>
  <compound kind="file">
    <name>UIOP_Connector.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>UIOP__Connector_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_Strategies_UIOP_Connector</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_Strategies_UIOP_Connector</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>UIOP_Connector.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>UIOP__Connector_8h.html</filename>
    <class kind="class">TAO_UIOP_Connector</class>
  </compound>
  <compound kind="file">
    <name>UIOP_Endpoint.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>UIOP__Endpoint_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_Strategies_UIOP_Endpoint</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_Strategies_UIOP_Endpoint</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>UIOP_Endpoint.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>UIOP__Endpoint_8h.html</filename>
    <class kind="class">TAO_UIOP_Endpoint</class>
  </compound>
  <compound kind="file">
    <name>UIOP_Endpoint.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>UIOP__Endpoint_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>uiop_endpoints.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>uiop__endpoints_8cpp.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>__TAO_UNBOUNDED_SEQUENCE_TAO_UIOPENDPOINTSEQUENCE_CS_</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_TAO_UIOPENDPOINTSEQUENCE_CS_</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::TypeCode</type>
      <name>_tc_TAO_tc_TAO_UIOP_Endpoint_Info</name>
      <anchor>a6</anchor>
      <arglist>(CORBA::tk_struct, sizeof(_oc_TAO_UIOP_Endpoint_Info),(char *)&amp;_oc_TAO_UIOP_Endpoint_Info, 0, sizeof(TAO_UIOP_Endpoint_Info))</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::TypeCode</type>
      <name>_tc_TAO_tc_TAO_UIOPEndpointSequence</name>
      <anchor>a7</anchor>
      <arglist>(CORBA::tk_alias, sizeof(_oc_TAO_UIOPEndpointSequence),(char *)&amp;_oc_TAO_UIOPEndpointSequence, 0, sizeof(TAO_UIOPEndpointSequence))</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Boolean</type>
      <name>operator&lt;&lt;</name>
      <anchor>a8</anchor>
      <arglist>(TAO_OutputCDR &amp;strm, const TAO_UIOPEndpointSequence &amp;_tao_sequence)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Boolean</type>
      <name>operator&gt;&gt;</name>
      <anchor>a9</anchor>
      <arglist>(TAO_InputCDR &amp;strm, TAO_UIOPEndpointSequence &amp;_tao_sequence)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const CORBA::Long</type>
      <name>_oc_TAO_UIOP_Endpoint_Info</name>
      <anchor>a2</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable">
      <type>CORBA::TypeCode_ptr</type>
      <name>_tc_TAO_UIOP_Endpoint_Info</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const CORBA::Long</type>
      <name>_oc_TAO_UIOPEndpointSequence</name>
      <anchor>a4</anchor>
      <arglist>[]</arglist>
    </member>
    <member kind="variable">
      <type>CORBA::TypeCode_ptr</type>
      <name>_tc_TAO_UIOPEndpointSequence</name>
      <anchor>a5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>uiop_endpoints.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>uiop__endpoints_8h.html</filename>
    <class kind="class">_TAO_Unbounded_Sequence_TAO_UIOPEndpointSequence</class>
    <class kind="struct">TAO_UIOP_Endpoint_Info</class>
    <class kind="class">TAO_UIOPEndpointSequence</class>
    <class kind="class">TAO_UIOPEndpointSequence_var</class>
    <member kind="define">
      <type>#define</type>
      <name>TAO_EXPORT_MACRO</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>__TAO_UNBOUNDED_SEQUENCE_TAO_UIOPENDPOINTSEQUENCE_CH_</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_TAO_UIOPENDPOINTSEQUENCE_CH_</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_TAO_UIOPENDPOINTSEQUENCE___VAR_CH_</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>TAO_Strategies_Export CORBA::Boolean</type>
      <name>operator&lt;&lt;</name>
      <anchor>a6</anchor>
      <arglist>(TAO_OutputCDR &amp;, const TAO_UIOP_Endpoint_Info &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_Strategies_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;</name>
      <anchor>a7</anchor>
      <arglist>(TAO_InputCDR &amp;, TAO_UIOP_Endpoint_Info &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_Strategies_Export CORBA::Boolean</type>
      <name>operator&lt;&lt;</name>
      <anchor>a8</anchor>
      <arglist>(TAO_OutputCDR &amp;, const TAO_UIOPEndpointSequence &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_Strategies_Export CORBA::Boolean</type>
      <name>operator&gt;&gt;</name>
      <anchor>a9</anchor>
      <arglist>(TAO_InputCDR &amp;, TAO_UIOPEndpointSequence &amp;)</arglist>
    </member>
    <member kind="variable">
      <type>TAO_Strategies_Export CORBA::TypeCode_ptr</type>
      <name>_tc_TAO_UIOP_Endpoint_Info</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>TAO_Strategies_Export CORBA::TypeCode_ptr</type>
      <name>_tc_TAO_UIOPEndpointSequence</name>
      <anchor>a5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>uiop_endpoints.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>uiop__endpoints_8i.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>__TAO_UNBOUNDED_SEQUENCE_TAO_UIOPENDPOINTSEQUENCE_CI_</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>_TAO_UIOPENDPOINTSEQUENCE_CI_</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type>CORBA::Boolean TAO_Strategies_Export</type>
      <name>operator&gt;&gt;</name>
      <anchor>a2</anchor>
      <arglist>(TAO_InputCDR &amp;, TAO_UIOPEndpointSequence &amp;)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>uiop_endpoints.pidl</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>uiop__endpoints_8pidl.html</filename>
    <class kind="struct">TAO_UIOP_Endpoint_Info</class>
    <member kind="typedef">
      <type>sequence&lt; TAO_UIOP_Endpoint_Info &gt;</type>
      <name>TAO_UIOPEndpointSequence</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>UIOP_Factory.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>UIOP__Factory_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_Strategies_UIOP_Factory</name>
      <anchor>a2</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACE_STATIC_SVC_DEFINE</name>
      <anchor>a3</anchor>
      <arglist>(TAO_UIOP_Protocol_Factory, ACE_TEXT(&quot;UIOP_Factory&quot;), ACE_SVC_OBJ_T,&amp;ACE_SVC_NAME(TAO_UIOP_Protocol_Factory), ACE_Service_Type::DELETE_THIS|ACE_Service_Type::DELETE_OBJ, 0) ACE_FACTORY_DEFINE(TAO_Strategies</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_Strategies_UIOP_Factory</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char</type>
      <name>prefix_</name>
      <anchor>a1</anchor>
      <arglist>[]</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>UIOP_Factory.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>UIOP__Factory_8h.html</filename>
    <class kind="class">TAO_UIOP_Protocol_Factory</class>
    <member kind="function">
      <type></type>
      <name>ACE_STATIC_SVC_DECLARE</name>
      <anchor>a0</anchor>
      <arglist>(TAO_UIOP_Protocol_Factory) ACE_FACTORY_DECLARE(TAO_Strategies</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>UIOP_Lite_Factory.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>UIOP__Lite__Factory_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_Strategies_UIOP_Lite_Factory</name>
      <anchor>a2</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACE_STATIC_SVC_DEFINE</name>
      <anchor>a3</anchor>
      <arglist>(TAO_UIOP_Lite_Protocol_Factory, ACE_TEXT(&quot;UIOP_Lite_Factory&quot;), ACE_SVC_OBJ_T,&amp;ACE_SVC_NAME(TAO_UIOP_Lite_Protocol_Factory), ACE_Service_Type::DELETE_THIS|ACE_Service_Type::DELETE_OBJ, 0) ACE_FACTORY_DEFINE(TAO_Strategies</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_Strategies_UIOP_Lite_Factory</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char</type>
      <name>prefix_</name>
      <anchor>a1</anchor>
      <arglist>[]</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>UIOP_Lite_Factory.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>UIOP__Lite__Factory_8h.html</filename>
    <class kind="class">TAO_UIOP_Lite_Protocol_Factory</class>
    <member kind="function">
      <type></type>
      <name>ACE_STATIC_SVC_DECLARE</name>
      <anchor>a0</anchor>
      <arglist>(TAO_UIOP_Lite_Protocol_Factory) ACE_FACTORY_DECLARE(TAO</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>UIOP_Profile.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>UIOP__Profile_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_Strategies_UIOP_Profile</name>
      <anchor>a2</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_Strategies_UIOP_Profile</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char</type>
      <name>prefix_</name>
      <anchor>a1</anchor>
      <arglist>[]</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>UIOP_Profile.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>UIOP__Profile_8h.html</filename>
    <class kind="class">TAO_UIOP_Profile</class>
  </compound>
  <compound kind="file">
    <name>UIOP_Profile.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>UIOP__Profile_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>UIOP_Transport.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>UIOP__Transport_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_Strategies_UIOP_Transport</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_Strategies_UIOP_Transport</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>UIOP_Transport.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>UIOP__Transport_8h.html</filename>
    <class kind="class">TAO_UIOP_Transport</class>
    <member kind="typedef">
      <type>ACE_Svc_Handler&lt; ACE_LSOCK_STREAM, ACE_NULL_SYNCH &gt;</type>
      <name>TAO_UIOP_SVC_HANDLER</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>UIOP_Transport.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/tao/Strategies/</path>
    <filename>UIOP__Transport_8i.html</filename>
  </compound>
  <compound kind="class">
    <name>_TAO_Unbounded_Sequence_TAO_UIOPEndpointSequence</name>
    <filename>class__TAO__Unbounded__Sequence__TAO__UIOPEndpointSequence.html</filename>
    <base>TAO_Unbounded_Base_Sequence</base>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Sequence_TAO_UIOPEndpointSequence</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Sequence_TAO_UIOPEndpointSequence</name>
      <anchor>a1</anchor>
      <arglist>(CORBA::ULong maximum)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Sequence_TAO_UIOPEndpointSequence</name>
      <anchor>a2</anchor>
      <arglist>(CORBA::ULong maximum, CORBA::ULong length, TAO_UIOP_Endpoint_Info *data, CORBA::Boolean release=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>_TAO_Unbounded_Sequence_TAO_UIOPEndpointSequence</name>
      <anchor>a3</anchor>
      <arglist>(const _TAO_Unbounded_Sequence_TAO_UIOPEndpointSequence &amp;rhs)</arglist>
    </member>
    <member kind="function">
      <type>_TAO_Unbounded_Sequence_TAO_UIOPEndpointSequence &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(const _TAO_Unbounded_Sequence_TAO_UIOPEndpointSequence &amp;rhs)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~_TAO_Unbounded_Sequence_TAO_UIOPEndpointSequence</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_UIOP_Endpoint_Info &amp;</type>
      <name>operator[]</name>
      <anchor>a6</anchor>
      <arglist>(CORBA::ULong i)</arglist>
    </member>
    <member kind="function">
      <type>const TAO_UIOP_Endpoint_Info &amp;</type>
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
      <type>TAO_UIOP_Endpoint_Info *</type>
      <name>get_buffer</name>
      <anchor>a10</anchor>
      <arglist>(CORBA::Boolean orphan=0)</arglist>
    </member>
    <member kind="function">
      <type>const TAO_UIOP_Endpoint_Info *</type>
      <name>get_buffer</name>
      <anchor>a11</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>replace</name>
      <anchor>a12</anchor>
      <arglist>(CORBA::ULong max, CORBA::ULong length, TAO_UIOP_Endpoint_Info *data, CORBA::Boolean release)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>TAO_UIOP_Endpoint_Info *</type>
      <name>allocbuf</name>
      <anchor>d0</anchor>
      <arglist>(CORBA::ULong size)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>void</type>
      <name>freebuf</name>
      <anchor>d1</anchor>
      <arglist>(TAO_UIOP_Endpoint_Info *buffer)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_Advanced_Resource_Factory</name>
    <filename>classTAO__Advanced__Resource__Factory.html</filename>
    <base>TAO_Default_Resource_Factory</base>
    <member kind="enumvalue">
      <name>TAO_ALLOCATOR_NULL_LOCK</name>
      <anchor>s12s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_ALLOCATOR_THREAD_LOCK</name>
      <anchor>s12s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_REACTOR_SELECT_MT</name>
      <anchor>s13s2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_REACTOR_SELECT_ST</name>
      <anchor>s13s3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_REACTOR_FL</name>
      <anchor>s13s4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_REACTOR_TK</name>
      <anchor>s13s5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_REACTOR_WFMO</name>
      <anchor>s13s6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_REACTOR_MSGWFMO</name>
      <anchor>s13s7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_REACTOR_TP</name>
      <anchor>s13s8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_THREAD_QUEUE_NOT_SET</name>
      <anchor>s14s9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_THREAD_QUEUE_FIFO</name>
      <anchor>s14s10</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_THREAD_QUEUE_LIFO</name>
      <anchor>s14s11</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_Advanced_Resource_Factory</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_Advanced_Resource_Factory</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>init</name>
      <anchor>a2</anchor>
      <arglist>(int argc, ACE_TCHAR *argv[])</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_Connection_Purging_Strategy *</type>
      <name>create_purging_strategy</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_LF_Strategy *</type>
      <name>create_lf_strategy</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>init_protocol_factories</name>
      <anchor>z0_0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACE_Allocator *</type>
      <name>input_cdr_dblock_allocator</name>
      <anchor>z0_1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACE_Allocator *</type>
      <name>input_cdr_buffer_allocator</name>
      <anchor>z0_2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACE_Allocator *</type>
      <name>input_cdr_msgblock_allocator</name>
      <anchor>z0_3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>input_cdr_allocator_type_locked</name>
      <anchor>z0_4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_ProtocolFactorySet *</type>
      <name>get_protocol_factories</name>
      <anchor>z0_5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual ACE_Reactor_Impl *</type>
      <name>allocate_reactor_impl</name>
      <anchor>b0</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" protection="public">
      <type>void</type>
      <name>report_option_value_error</name>
      <anchor>b1</anchor>
      <arglist>(const ACE_TCHAR *option_name, const ACE_TCHAR *option_value)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>void</type>
      <name>report_unsupported_error</name>
      <anchor>b2</anchor>
      <arglist>(const ACE_TCHAR *option_name)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual int</type>
      <name>load_default_protocols</name>
      <anchor>b3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_ProtocolFactorySet</type>
      <name>protocol_factories_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>int</type>
      <name>reactor_registry_type_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>int</type>
      <name>reactor_type_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>int</type>
      <name>threadqueue_type_</name>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>int</type>
      <name>cdr_allocator_type_</name>
      <anchor>n4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_DIOP_Acceptor</name>
    <filename>classTAO__DIOP__Acceptor.html</filename>
    <base>TAO_Acceptor</base>
    <member kind="function">
      <type></type>
      <name>TAO_DIOP_Acceptor</name>
      <anchor>a0</anchor>
      <arglist>(CORBA::Boolean flag=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_DIOP_Acceptor</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const ACE_INET_Addr &amp;</type>
      <name>address</name>
      <anchor>a2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const ACE_INET_Addr *</type>
      <name>endpoints</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>hostname</name>
      <anchor>a4</anchor>
      <arglist>(TAO_ORB_Core *orb_core, ACE_INET_Addr &amp;addr, char *&amp;host, const char *specified_hostname=0)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>dotted_decimal_address</name>
      <anchor>a5</anchor>
      <arglist>(ACE_INET_Addr &amp;addr, char *&amp;host)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>open</name>
      <anchor>z1_0</anchor>
      <arglist>(TAO_ORB_Core *orb_core, ACE_Reactor *reactor, int version_major, int version_minor, const char *address, const char *options=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>open_default</name>
      <anchor>z1_1</anchor>
      <arglist>(TAO_ORB_Core *orb_core, ACE_Reactor *reactor, int version_major, int version_minor, const char *options=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>close</name>
      <anchor>z1_2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>create_profile</name>
      <anchor>z1_3</anchor>
      <arglist>(const TAO_ObjectKey &amp;object_key, TAO_MProfile &amp;mprofile, CORBA::Short priority)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>is_collocated</name>
      <anchor>z1_4</anchor>
      <arglist>(const TAO_Endpoint *endpoint)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::ULong</type>
      <name>endpoint_count</name>
      <anchor>z1_5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>object_key</name>
      <anchor>z1_6</anchor>
      <arglist>(IOP::TaggedProfile &amp;profile, TAO_ObjectKey &amp;key)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual int</type>
      <name>open_i</name>
      <anchor>b0</anchor>
      <arglist>(const ACE_INET_Addr &amp;addr, ACE_Reactor *reactor)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>probe_interfaces</name>
      <anchor>b1</anchor>
      <arglist>(TAO_ORB_Core *orb_core)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual int</type>
      <name>parse_options</name>
      <anchor>b2</anchor>
      <arglist>(const char *options)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>init_tcp_properties</name>
      <anchor>b3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>create_new_profile</name>
      <anchor>b4</anchor>
      <arglist>(const TAO_ObjectKey &amp;object_key, TAO_MProfile &amp;mprofile, CORBA::Short priority)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>create_shared_profile</name>
      <anchor>b5</anchor>
      <arglist>(const TAO_ObjectKey &amp;object_key, TAO_MProfile &amp;mprofile, CORBA::Short priority)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_INET_Addr *</type>
      <name>addrs_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>char **</type>
      <name>hosts_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>size_t</type>
      <name>endpoint_count_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_GIOP_Message_Version</type>
      <name>version_</name>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_ORB_Core *</type>
      <name>orb_core_</name>
      <anchor>n4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_DIOP_Properties</type>
      <name>tcp_properties_</name>
      <anchor>n5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::Boolean</type>
      <name>lite_flag_</name>
      <anchor>n6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_DIOP_Connection_Handler *</type>
      <name>connection_handler_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_DIOP_Connection_Handler</name>
    <filename>classTAO__DIOP__Connection__Handler.html</filename>
    <base>ACE_Svc_Handler&lt; ACE_SOCK_STREAM, ACE_NULL_SYNCH &gt;</base>
    <base>TAO_Connection_Handler</base>
    <member kind="function">
      <type></type>
      <name>TAO_DIOP_Connection_Handler</name>
      <anchor>a0</anchor>
      <arglist>(ACE_Thread_Manager *t=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_DIOP_Connection_Handler</name>
      <anchor>a1</anchor>
      <arglist>(TAO_ORB_Core *orb_core, CORBA::Boolean flag, void *arg)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_DIOP_Connection_Handler</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>open</name>
      <anchor>a3</anchor>
      <arglist>(void *)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>open_server</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>activate</name>
      <anchor>a5</anchor>
      <arglist>(long flags=THR_NEW_LWP, int n_threads=1, int force_active=0, long priority=ACE_DEFAULT_THREAD_PRIORITY, int grp_id=-1, ACE_Task_Base *task=0, ACE_hthread_t thread_handles[]=0, void *stack[]=0, size_t stack_size[]=0, ACE_thread_t thread_names[]=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>svc</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>add_transport_to_cache</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>resume_handler</name>
      <anchor>z2_0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>close_connection</name>
      <anchor>z2_1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_input</name>
      <anchor>z2_2</anchor>
      <arglist>(ACE_HANDLE)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_output</name>
      <anchor>z2_3</anchor>
      <arglist>(ACE_HANDLE)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_close</name>
      <anchor>z2_4</anchor>
      <arglist>(ACE_HANDLE, ACE_Reactor_Mask)</arglist>
    </member>
    <member kind="function">
      <type>ACE_HANDLE</type>
      <name>get_handle</name>
      <anchor>z3_0</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const ACE_INET_Addr &amp;</type>
      <name>addr</name>
      <anchor>z3_1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>addr</name>
      <anchor>z3_2</anchor>
      <arglist>(const ACE_INET_Addr &amp;addr)</arglist>
    </member>
    <member kind="function">
      <type>const ACE_INET_Addr &amp;</type>
      <name>local_addr</name>
      <anchor>z3_3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>local_addr</name>
      <anchor>z3_4</anchor>
      <arglist>(const ACE_INET_Addr &amp;addr)</arglist>
    </member>
    <member kind="function">
      <type>const ACE_INET_Addr &amp;</type>
      <name>server_addr</name>
      <anchor>z3_5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>server_addr</name>
      <anchor>z3_6</anchor>
      <arglist>(const ACE_INET_Addr &amp;addr)</arglist>
    </member>
    <member kind="function">
      <type>const ACE_SOCK_Dgram &amp;</type>
      <name>dgram</name>
      <anchor>z3_7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual int</type>
      <name>release_os_resources</name>
      <anchor>z4_0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_SOCK_Dgram</type>
      <name>udp_socket_</name>
      <anchor>z5_0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_INET_Addr</type>
      <name>addr_</name>
      <anchor>z5_1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_INET_Addr</type>
      <name>local_addr_</name>
      <anchor>z5_2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_DIOP_Properties *</type>
      <name>tcp_properties_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_DIOP_Connector</name>
    <filename>classTAO__DIOP__Connector.html</filename>
    <base>TAO_Connector</base>
    <member kind="function">
      <type></type>
      <name>TAO_DIOP_Connector</name>
      <anchor>a0</anchor>
      <arglist>(CORBA::Boolean flag=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_DIOP_Connector</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>open</name>
      <anchor>z6_0</anchor>
      <arglist>(TAO_ORB_Core *orb_core)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>close</name>
      <anchor>z6_1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_Profile *</type>
      <name>create_profile</name>
      <anchor>z6_2</anchor>
      <arglist>(TAO_InputCDR &amp;cdr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>check_prefix</name>
      <anchor>z6_3</anchor>
      <arglist>(const char *endpoint)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual char</type>
      <name>object_key_delimiter</name>
      <anchor>z6_4</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>init_tcp_properties</name>
      <anchor>b0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>set_validate_endpoint</name>
      <anchor>z7_0</anchor>
      <arglist>(TAO_Endpoint *ep)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>make_connection</name>
      <anchor>z7_1</anchor>
      <arglist>(TAO_GIOP_Invocation *invocation, TAO_Transport_Descriptor_Interface *desc, ACE_Time_Value *timeout=0)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual TAO_Profile *</type>
      <name>make_profile</name>
      <anchor>z7_2</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_DIOP_Properties</type>
      <name>tcp_properties_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::Boolean</type>
      <name>lite_flag_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef" protection="protected">
      <type>ACE_Hash_Map_Iterator_Ex&lt; ACE_INET_Addr, TAO_DIOP_Connection_Handler *, ACE_Hash&lt; ACE_INET_Addr &gt;, ACE_Equal_To&lt; ACE_INET_Addr &gt;, ACE_Null_Mutex &gt;</type>
      <name>SvcHandlerIterator</name>
      <anchor>u0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="protected">
      <type>TAO_DIOP_Endpoint *</type>
      <name>remote_endpoint</name>
      <anchor>c0</anchor>
      <arglist>(TAO_Endpoint *ep)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_Hash_Map_Manager_Ex&lt; ACE_INET_Addr, TAO_DIOP_Connection_Handler *, ACE_Hash&lt; ACE_INET_Addr &gt;, ACE_Equal_To&lt; ACE_INET_Addr &gt;, ACE_Null_Mutex &gt;</type>
      <name>svc_handler_table_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_DIOP_Endpoint</name>
    <filename>classTAO__DIOP__Endpoint.html</filename>
    <base>TAO_Endpoint</base>
    <member kind="function">
      <type></type>
      <name>TAO_DIOP_Endpoint</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_DIOP_Endpoint</name>
      <anchor>a1</anchor>
      <arglist>(const char *host, CORBA::UShort port, const ACE_INET_Addr &amp;addr)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_DIOP_Endpoint</name>
      <anchor>a2</anchor>
      <arglist>(const ACE_INET_Addr &amp;addr, int use_dotted_decimal_addresses)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_DIOP_Endpoint</name>
      <anchor>a3</anchor>
      <arglist>(const char *host, CORBA::UShort port, CORBA::Short priority)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_DIOP_Endpoint</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const ACE_INET_Addr &amp;</type>
      <name>object_addr</name>
      <anchor>a5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>host</name>
      <anchor>a6</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>host</name>
      <anchor>a7</anchor>
      <arglist>(const char *h)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::UShort</type>
      <name>port</name>
      <anchor>a8</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>CORBA::UShort</type>
      <name>port</name>
      <anchor>a9</anchor>
      <arglist>(CORBA::UShort p)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_Endpoint *</type>
      <name>next</name>
      <anchor>z8_0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>addr_to_string</name>
      <anchor>z8_1</anchor>
      <arglist>(char *buffer, size_t length)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>reset_hint</name>
      <anchor>z8_2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_Endpoint *</type>
      <name>duplicate</name>
      <anchor>z8_3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Boolean</type>
      <name>is_equivalent</name>
      <anchor>z8_4</anchor>
      <arglist>(const TAO_Endpoint *other_endpoint)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::ULong</type>
      <name>hash</name>
      <anchor>z8_5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>int</type>
      <name>set</name>
      <anchor>c0</anchor>
      <arglist>(const ACE_INET_Addr &amp;addr, int use_dotted_decimal_addresses)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>CORBA::String_var</type>
      <name>host_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>CORBA::UShort</type>
      <name>port_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_INET_Addr</type>
      <name>object_addr_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>object_addr_set_</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_DIOP_Endpoint *</type>
      <name>next_</name>
      <anchor>o4</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>TAO_DIOP_Profile</name>
      <anchor>l0</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>TAO_SSLIOP_Profile</name>
      <anchor>l1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_DIOP_Profile</name>
    <filename>classTAO__DIOP__Profile.html</filename>
    <base>TAO_Profile</base>
    <member kind="function" virtualness="virtual">
      <type>virtual char</type>
      <name>object_key_delimiter</name>
      <anchor>a0</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_DIOP_Profile</name>
      <anchor>a1</anchor>
      <arglist>(const ACE_INET_Addr &amp;addr, const TAO_ObjectKey &amp;object_key, const TAO_GIOP_Message_Version &amp;version, TAO_ORB_Core *orb_core)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_DIOP_Profile</name>
      <anchor>a2</anchor>
      <arglist>(const char *host, CORBA::UShort port, const TAO_ObjectKey &amp;object_key, const ACE_INET_Addr &amp;addr, const TAO_GIOP_Message_Version &amp;version, TAO_ORB_Core *orb_core)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_DIOP_Profile</name>
      <anchor>a3</anchor>
      <arglist>(TAO_ORB_Core *orb_core)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_DIOP_Profile</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>parse_string</name>
      <anchor>a5</anchor>
      <arglist>(const char *string ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual char *</type>
      <name>to_string</name>
      <anchor>a6</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>decode</name>
      <anchor>a7</anchor>
      <arglist>(TAO_InputCDR &amp;cdr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>encode</name>
      <anchor>a8</anchor>
      <arglist>(TAO_OutputCDR &amp;stream) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>encode_endpoints</name>
      <anchor>a9</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const TAO_ObjectKey &amp;</type>
      <name>object_key</name>
      <anchor>a10</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_ObjectKey *</type>
      <name>_key</name>
      <anchor>a11</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_Endpoint *</type>
      <name>endpoint</name>
      <anchor>a12</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual size_t</type>
      <name>endpoint_count</name>
      <anchor>a13</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>add_endpoint</name>
      <anchor>a14</anchor>
      <arglist>(TAO_DIOP_Endpoint *endp)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>is_equivalent</name>
      <anchor>a15</anchor>
      <arglist>(const TAO_Profile *other_profile)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::ULong</type>
      <name>hash</name>
      <anchor>a16</anchor>
      <arglist>(CORBA::ULong max ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual IOP::TaggedProfile &amp;</type>
      <name>create_tagged_profile</name>
      <anchor>a17</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>prefix</name>
      <anchor>d0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char</type>
      <name>object_key_delimiter_</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_DIOP_Endpoint</type>
      <name>endpoint_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>size_t</type>
      <name>count_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>create_profile_body</name>
      <anchor>c0</anchor>
      <arglist>(TAO_OutputCDR &amp;cdr) const</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>int</type>
      <name>decode_endpoints</name>
      <anchor>c1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_ObjectKey</type>
      <name>object_key_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>IOP::TaggedProfile</type>
      <name>tagged_profile_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_DIOP_Properties</name>
    <filename>classTAO__DIOP__Properties.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>send_buffer_size</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>recv_buffer_size</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>no_delay</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_DIOP_Protocol_Factory</name>
    <filename>classTAO__DIOP__Protocol__Factory.html</filename>
    <base>TAO_Protocol_Factory</base>
    <member kind="function">
      <type></type>
      <name>TAO_DIOP_Protocol_Factory</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_DIOP_Protocol_Factory</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>init</name>
      <anchor>a2</anchor>
      <arglist>(int argc, ACE_TCHAR *argv[])</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>match_prefix</name>
      <anchor>a3</anchor>
      <arglist>(const ACE_CString &amp;prefix)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>prefix</name>
      <anchor>a4</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual char</type>
      <name>options_delimiter</name>
      <anchor>a5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_Acceptor *</type>
      <name>make_acceptor</name>
      <anchor>z9_0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_Connector *</type>
      <name>make_connector</name>
      <anchor>z9_1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>requires_explicit_endpoint</name>
      <anchor>z9_2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>major_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>minor_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_DIOP_Transport</name>
    <filename>classTAO__DIOP__Transport.html</filename>
    <base>TAO_Transport</base>
    <member kind="function">
      <type></type>
      <name>TAO_DIOP_Transport</name>
      <anchor>a0</anchor>
      <arglist>(TAO_DIOP_Connection_Handler *handler, TAO_ORB_Core *orb_core, CORBA::Boolean flag)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_DIOP_Transport</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_input_i</name>
      <anchor>a2</anchor>
      <arglist>(TAO_Resume_Handle &amp;rh, ACE_Time_Value *max_wait_time=0, int block=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>send_request</name>
      <anchor>a3</anchor>
      <arglist>(TAO_Stub *stub, TAO_ORB_Core *orb_core, TAO_OutputCDR &amp;stream, int message_semantics, ACE_Time_Value *max_wait_time)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>send_message</name>
      <anchor>a4</anchor>
      <arglist>(TAO_OutputCDR &amp;stream, TAO_Stub *stub=0, int message_semantics=TAO_Transport::TAO_TWOWAY_REQUEST, ACE_Time_Value *max_time_wait=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>messaging_init</name>
      <anchor>a5</anchor>
      <arglist>(CORBA::Octet major, CORBA::Octet minor)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual ACE_Event_Handler *</type>
      <name>event_handler_i</name>
      <anchor>z10_0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual TAO_Connection_Handler *</type>
      <name>connection_handler_i</name>
      <anchor>z10_1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual TAO_Connection_Handler *</type>
      <name>invalidate_event_handler_i</name>
      <anchor>z10_2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual TAO_Pluggable_Messaging *</type>
      <name>messaging_object</name>
      <anchor>z10_3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual ssize_t</type>
      <name>send_i</name>
      <anchor>z10_4</anchor>
      <arglist>(iovec *iov, int iovcnt, size_t &amp;bytes_transferred, const ACE_Time_Value *max_wait_time)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual ssize_t</type>
      <name>recv_i</name>
      <anchor>z10_5</anchor>
      <arglist>(char *buf, size_t len, const ACE_Time_Value *s=0)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual int</type>
      <name>register_handler_i</name>
      <anchor>z10_6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_DIOP_Connection_Handler *</type>
      <name>connection_handler_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_Pluggable_Messaging *</type>
      <name>messaging_object_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_FIFO_Connection_Purging_Strategy</name>
    <filename>classTAO__FIFO__Connection__Purging__Strategy.html</filename>
    <base>TAO_Connection_Purging_Strategy</base>
    <member kind="function">
      <type></type>
      <name>TAO_FIFO_Connection_Purging_Strategy</name>
      <anchor>a0</anchor>
      <arglist>(int cache_maximum)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_FIFO_Connection_Purging_Strategy</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>update_item</name>
      <anchor>a2</anchor>
      <arglist>(TAO_Transport *transport)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>unsigned long</type>
      <name>order_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_LF_Strategy_Null</name>
    <filename>classTAO__LF__Strategy__Null.html</filename>
    <base>TAO_LF_Strategy</base>
    <member kind="function">
      <type></type>
      <name>TAO_LF_Strategy_Null</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_LF_Strategy_Null</name>
      <anchor>z11_0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_upcall_thread</name>
      <anchor>z11_1</anchor>
      <arglist>(TAO_Leader_Follower &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>set_event_loop_thread</name>
      <anchor>z11_2</anchor>
      <arglist>(ACE_Time_Value *max_wait_time, TAO_Leader_Follower &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>reset_event_loop_thread</name>
      <anchor>z11_3</anchor>
      <arglist>(int call_reset, TAO_Leader_Follower &amp;)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_LFU_Connection_Purging_Strategy</name>
    <filename>classTAO__LFU__Connection__Purging__Strategy.html</filename>
    <base>TAO_Connection_Purging_Strategy</base>
    <member kind="function">
      <type></type>
      <name>TAO_LFU_Connection_Purging_Strategy</name>
      <anchor>a0</anchor>
      <arglist>(int cache_maximum)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_LFU_Connection_Purging_Strategy</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>update_item</name>
      <anchor>a2</anchor>
      <arglist>(TAO_Transport *transport)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_NULL_Connection_Purging_Strategy</name>
    <filename>classTAO__NULL__Connection__Purging__Strategy.html</filename>
    <base>TAO_Connection_Purging_Strategy</base>
    <member kind="function">
      <type></type>
      <name>TAO_NULL_Connection_Purging_Strategy</name>
      <anchor>a0</anchor>
      <arglist>(int cache_maximum)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_NULL_Connection_Purging_Strategy</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>update_item</name>
      <anchor>a2</anchor>
      <arglist>(TAO_Transport *transport)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>cache_maximum</name>
      <anchor>a3</anchor>
      <arglist>(void) const</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_Resource_Factory_Changer</name>
    <filename>classTAO__Resource__Factory__Changer.html</filename>
    <member kind="function">
      <type></type>
      <name>TAO_Resource_Factory_Changer</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_SHMIOP_Acceptor</name>
    <filename>classTAO__SHMIOP__Acceptor.html</filename>
    <base>TAO_Acceptor</base>
    <member kind="typedef">
      <type>ACE_Strategy_Acceptor&lt; TAO_SHMIOP_Connection_Handler, ACE_MEM_ACCEPTOR &gt;</type>
      <name>TAO_SHMIOP_BASE_ACCEPTOR</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TAO_Creation_Strategy&lt; TAO_SHMIOP_Connection_Handler &gt;</type>
      <name>TAO_SHMIOP_CREATION_STRATEGY</name>
      <anchor>s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TAO_Concurrency_Strategy&lt; TAO_SHMIOP_Connection_Handler &gt;</type>
      <name>TAO_SHMIOP_CONCURRENCY_STRATEGY</name>
      <anchor>s2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TAO_Accept_Strategy&lt; TAO_SHMIOP_Connection_Handler, ACE_MEM_ACCEPTOR &gt;</type>
      <name>TAO_SHMIOP_ACCEPT_STRATEGY</name>
      <anchor>s3</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_SHMIOP_Acceptor</name>
      <anchor>a0</anchor>
      <arglist>(CORBA::Boolean flag=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_SHMIOP_Acceptor</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>set_mmap_options</name>
      <anchor>a2</anchor>
      <arglist>(const ACE_TCHAR *prefix, off_t size)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>open</name>
      <anchor>z12_0</anchor>
      <arglist>(TAO_ORB_Core *orb_core, ACE_Reactor *reactor, int version_major, int version_minor, const char *port, const char *options=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>open_default</name>
      <anchor>z12_1</anchor>
      <arglist>(TAO_ORB_Core *orb_core, ACE_Reactor *reactor, int version_major, int version_minor, const char *options=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>close</name>
      <anchor>z12_2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>create_profile</name>
      <anchor>z12_3</anchor>
      <arglist>(const TAO_ObjectKey &amp;object_key, TAO_MProfile &amp;mprofile, CORBA::Short priority)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>is_collocated</name>
      <anchor>z12_4</anchor>
      <arglist>(const TAO_Endpoint *endpoint)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::ULong</type>
      <name>endpoint_count</name>
      <anchor>z12_5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>object_key</name>
      <anchor>z12_6</anchor>
      <arglist>(IOP::TaggedProfile &amp;profile, TAO_ObjectKey &amp;key)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_CString</type>
      <name>host_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_MEM_Addr</type>
      <name>address_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_GIOP_Message_Version</type>
      <name>version_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_ORB_Core *</type>
      <name>orb_core_</name>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="protected">
      <type>int</type>
      <name>open_i</name>
      <anchor>c0</anchor>
      <arglist>(TAO_ORB_Core *orb_core, ACE_Reactor *reactor)</arglist>
    </member>
    <member kind="function" protection="protected" virtualness="virtual">
      <type>virtual int</type>
      <name>parse_options</name>
      <anchor>c1</anchor>
      <arglist>(const char *options)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>int</type>
      <name>create_new_profile</name>
      <anchor>c2</anchor>
      <arglist>(const TAO_ObjectKey &amp;object_key, TAO_MProfile &amp;mprofile, CORBA::Short priority)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>int</type>
      <name>create_shared_profile</name>
      <anchor>c3</anchor>
      <arglist>(const TAO_ObjectKey &amp;object_key, TAO_MProfile &amp;mprofile, CORBA::Short priority)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_SHMIOP_BASE_ACCEPTOR</type>
      <name>base_acceptor_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_SHMIOP_CREATION_STRATEGY *</type>
      <name>creation_strategy_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_SHMIOP_CONCURRENCY_STRATEGY *</type>
      <name>concurrency_strategy_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_SHMIOP_ACCEPT_STRATEGY *</type>
      <name>accept_strategy_</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>const ACE_TCHAR *</type>
      <name>mmap_file_prefix_</name>
      <anchor>o4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>off_t</type>
      <name>mmap_size_</name>
      <anchor>o5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>CORBA::Boolean</type>
      <name>lite_flag_</name>
      <anchor>o6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_SHMIOP_Connection_Handler</name>
    <filename>classTAO__SHMIOP__Connection__Handler.html</filename>
    <base>ACE_Svc_Handler&lt; ACE_MEM_STREAM, ACE_NULL_SYNCH &gt;</base>
    <base>TAO_Connection_Handler</base>
    <member kind="function">
      <type></type>
      <name>TAO_SHMIOP_Connection_Handler</name>
      <anchor>a0</anchor>
      <arglist>(ACE_Thread_Manager *t=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_SHMIOP_Connection_Handler</name>
      <anchor>a1</anchor>
      <arglist>(TAO_ORB_Core *orb_core, CORBA::Boolean flag, void *arg)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_SHMIOP_Connection_Handler</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>open</name>
      <anchor>a3</anchor>
      <arglist>(void *)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>activate</name>
      <anchor>a4</anchor>
      <arglist>(long flags=THR_NEW_LWP, int n_threads=1, int force_active=0, long priority=ACE_DEFAULT_THREAD_PRIORITY, int grp_id=-1, ACE_Task_Base *task=0, ACE_hthread_t thread_handles[]=0, void *stack[]=0, size_t stack_size[]=0, ACE_thread_t thread_names[]=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>svc</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>add_transport_to_cache</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>resume_handler</name>
      <anchor>z13_0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>close_connection</name>
      <anchor>z13_1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_input</name>
      <anchor>z13_2</anchor>
      <arglist>(ACE_HANDLE)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_output</name>
      <anchor>z13_3</anchor>
      <arglist>(ACE_HANDLE)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_close</name>
      <anchor>z13_4</anchor>
      <arglist>(ACE_HANDLE, ACE_Reactor_Mask)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual int</type>
      <name>release_os_resources</name>
      <anchor>z14_0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>resume_flag_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_SHMIOP_Connector</name>
    <filename>classTAO__SHMIOP__Connector.html</filename>
    <base>TAO_Connector</base>
    <member kind="typedef">
      <type>TAO_Connect_Concurrency_Strategy&lt; TAO_SHMIOP_Connection_Handler &gt;</type>
      <name>TAO_SHMIOP_CONNECT_CONCURRENCY_STRATEGY</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TAO_Connect_Creation_Strategy&lt; TAO_SHMIOP_Connection_Handler &gt;</type>
      <name>TAO_SHMIOP_CONNECT_CREATION_STRATEGY</name>
      <anchor>s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Connect_Strategy&lt; TAO_SHMIOP_Connection_Handler, ACE_MEM_CONNECTOR &gt;</type>
      <name>TAO_SHMIOP_CONNECT_STRATEGY</name>
      <anchor>s2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Strategy_Connector&lt; TAO_SHMIOP_Connection_Handler, ACE_MEM_CONNECTOR &gt;</type>
      <name>TAO_SHMIOP_BASE_CONNECTOR</name>
      <anchor>s3</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_SHMIOP_Connector</name>
      <anchor>a0</anchor>
      <arglist>(CORBA::Boolean flag=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_SHMIOP_Connector</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>open</name>
      <anchor>z15_0</anchor>
      <arglist>(TAO_ORB_Core *orb_core)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>close</name>
      <anchor>z15_1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_Profile *</type>
      <name>create_profile</name>
      <anchor>z15_2</anchor>
      <arglist>(TAO_InputCDR &amp;cdr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>check_prefix</name>
      <anchor>z15_3</anchor>
      <arglist>(const char *endpoint)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual char</type>
      <name>object_key_delimiter</name>
      <anchor>z15_4</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>set_validate_endpoint</name>
      <anchor>z16_0</anchor>
      <arglist>(TAO_Endpoint *endpoint)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>make_connection</name>
      <anchor>z16_1</anchor>
      <arglist>(TAO_GIOP_Invocation *invocation, TAO_Transport_Descriptor_Interface *desc, ACE_Time_Value *timeout=0)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual TAO_Profile *</type>
      <name>make_profile</name>
      <anchor>z16_2</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>TAO_SHMIOP_Endpoint *</type>
      <name>remote_endpoint</name>
      <anchor>c0</anchor>
      <arglist>(TAO_Endpoint *ep)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_MEM_Addr</type>
      <name>address_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_SHMIOP_CONNECT_STRATEGY</type>
      <name>connect_strategy_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_SHMIOP_BASE_CONNECTOR</type>
      <name>base_connector_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>CORBA::Boolean</type>
      <name>lite_flag_</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_SHMIOP_Endpoint</name>
    <filename>classTAO__SHMIOP__Endpoint.html</filename>
    <base>TAO_Endpoint</base>
    <member kind="function">
      <type></type>
      <name>TAO_SHMIOP_Endpoint</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_SHMIOP_Endpoint</name>
      <anchor>a1</anchor>
      <arglist>(const char *host, CORBA::UShort port, const ACE_INET_Addr &amp;addr)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_SHMIOP_Endpoint</name>
      <anchor>a2</anchor>
      <arglist>(const ACE_MEM_Addr &amp;addr, int use_dotted_decimal_addresses)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_SHMIOP_Endpoint</name>
      <anchor>a3</anchor>
      <arglist>(const ACE_INET_Addr &amp;addr, int use_dotted_decimal_addresses)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_SHMIOP_Endpoint</name>
      <anchor>a4</anchor>
      <arglist>(const char *host, CORBA::UShort port, CORBA::Short priority)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_SHMIOP_Endpoint</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const ACE_INET_Addr &amp;</type>
      <name>object_addr</name>
      <anchor>a6</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>host</name>
      <anchor>a7</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>host</name>
      <anchor>a8</anchor>
      <arglist>(const char *h)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::UShort</type>
      <name>port</name>
      <anchor>a9</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>CORBA::UShort</type>
      <name>port</name>
      <anchor>a10</anchor>
      <arglist>(CORBA::UShort p)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_Endpoint *</type>
      <name>next</name>
      <anchor>z17_0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>addr_to_string</name>
      <anchor>z17_1</anchor>
      <arglist>(char *buffer, size_t length)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>reset_hint</name>
      <anchor>z17_2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_Endpoint *</type>
      <name>duplicate</name>
      <anchor>z17_3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Boolean</type>
      <name>is_equivalent</name>
      <anchor>z17_4</anchor>
      <arglist>(const TAO_Endpoint *other_endpoint)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::ULong</type>
      <name>hash</name>
      <anchor>z17_5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>int</type>
      <name>set</name>
      <anchor>c0</anchor>
      <arglist>(const ACE_INET_Addr &amp;addr, int use_dotted_decimal_addresses)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>CORBA::String_var</type>
      <name>host_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>CORBA::UShort</type>
      <name>port_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_INET_Addr</type>
      <name>object_addr_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>object_addr_set_</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_SHMIOP_Endpoint *</type>
      <name>next_</name>
      <anchor>o4</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>TAO_SHMIOP_Profile</name>
      <anchor>l0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_SHMIOP_Profile</name>
    <filename>classTAO__SHMIOP__Profile.html</filename>
    <base>TAO_Profile</base>
    <member kind="function" virtualness="virtual">
      <type>virtual char</type>
      <name>object_key_delimiter</name>
      <anchor>a0</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_SHMIOP_Profile</name>
      <anchor>a1</anchor>
      <arglist>(const ACE_MEM_Addr &amp;addr, const TAO_ObjectKey &amp;object_key, const TAO_GIOP_Message_Version &amp;version, TAO_ORB_Core *orb_core)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_SHMIOP_Profile</name>
      <anchor>a2</anchor>
      <arglist>(const char *host, CORBA::UShort port, const TAO_ObjectKey &amp;object_key, const ACE_INET_Addr &amp;addr, const TAO_GIOP_Message_Version &amp;version, TAO_ORB_Core *orb_core)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_SHMIOP_Profile</name>
      <anchor>a3</anchor>
      <arglist>(TAO_ORB_Core *orb_core)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_SHMIOP_Profile</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>parse_string</name>
      <anchor>a5</anchor>
      <arglist>(const char *string ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>char *</type>
      <name>to_string</name>
      <anchor>a6</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>decode</name>
      <anchor>a7</anchor>
      <arglist>(TAO_InputCDR &amp;cdr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>encode</name>
      <anchor>a8</anchor>
      <arglist>(TAO_OutputCDR &amp;stream) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>encode_endpoints</name>
      <anchor>a9</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const TAO_ObjectKey &amp;</type>
      <name>object_key</name>
      <anchor>a10</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>TAO_ObjectKey *</type>
      <name>_key</name>
      <anchor>a11</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_Endpoint *</type>
      <name>endpoint</name>
      <anchor>a12</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual size_t</type>
      <name>endpoint_count</name>
      <anchor>a13</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>add_endpoint</name>
      <anchor>a14</anchor>
      <arglist>(TAO_SHMIOP_Endpoint *endp)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Boolean</type>
      <name>is_equivalent</name>
      <anchor>a15</anchor>
      <arglist>(const TAO_Profile *other_profile)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::ULong</type>
      <name>hash</name>
      <anchor>a16</anchor>
      <arglist>(CORBA::ULong max ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>IOP::TaggedProfile &amp;</type>
      <name>create_tagged_profile</name>
      <anchor>a17</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>prefix</name>
      <anchor>d0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char</type>
      <name>object_key_delimiter_</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>create_profile_body</name>
      <anchor>c0</anchor>
      <arglist>(TAO_OutputCDR &amp;cdr) const</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>int</type>
      <name>decode_endpoints</name>
      <anchor>c1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_SHMIOP_Endpoint</type>
      <name>endpoint_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>size_t</type>
      <name>count_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_ObjectKey</type>
      <name>object_key_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>IOP::TaggedProfile</type>
      <name>tagged_profile_</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_SHMIOP_Protocol_Factory</name>
    <filename>classTAO__SHMIOP__Protocol__Factory.html</filename>
    <base>TAO_Protocol_Factory</base>
    <member kind="function">
      <type></type>
      <name>TAO_SHMIOP_Protocol_Factory</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_SHMIOP_Protocol_Factory</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>init</name>
      <anchor>a2</anchor>
      <arglist>(int argc, ACE_TCHAR *argv[])</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>match_prefix</name>
      <anchor>a3</anchor>
      <arglist>(const ACE_CString &amp;prefix)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>prefix</name>
      <anchor>a4</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual char</type>
      <name>options_delimiter</name>
      <anchor>a5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>mmap_file_prefix</name>
      <anchor>a6</anchor>
      <arglist>(const ACE_TCHAR *prefix)</arglist>
    </member>
    <member kind="function">
      <type>const ACE_TCHAR *</type>
      <name>mmap_file_prefix</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_Acceptor *</type>
      <name>make_acceptor</name>
      <anchor>z18_0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_Connector *</type>
      <name>make_connector</name>
      <anchor>z18_1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>requires_explicit_endpoint</name>
      <anchor>z18_2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>major_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>minor_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_TCHAR *</type>
      <name>mmap_prefix_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>off_t</type>
      <name>min_bytes_</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_SHMIOP_Transport</name>
    <filename>classTAO__SHMIOP__Transport.html</filename>
    <base>TAO_Transport</base>
    <member kind="function">
      <type></type>
      <name>TAO_SHMIOP_Transport</name>
      <anchor>a0</anchor>
      <arglist>(TAO_SHMIOP_Connection_Handler *handler, TAO_ORB_Core *orb_core, CORBA::Boolean flag)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_SHMIOP_Transport</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>send_request</name>
      <anchor>a2</anchor>
      <arglist>(TAO_Stub *stub, TAO_ORB_Core *orb_core, TAO_OutputCDR &amp;stream, int message_semantics, ACE_Time_Value *max_wait_time)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>send_message</name>
      <anchor>a3</anchor>
      <arglist>(TAO_OutputCDR &amp;stream, TAO_Stub *stub=0, int message_semantics=TAO_Transport::TAO_TWOWAY_REQUEST, ACE_Time_Value *max_time_wait=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>messaging_init</name>
      <anchor>a4</anchor>
      <arglist>(CORBA::Octet major, CORBA::Octet minor)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual ACE_Event_Handler *</type>
      <name>event_handler_i</name>
      <anchor>z19_0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual TAO_Connection_Handler *</type>
      <name>connection_handler_i</name>
      <anchor>z19_1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual TAO_Connection_Handler *</type>
      <name>invalidate_event_handler_i</name>
      <anchor>z19_2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual TAO_Pluggable_Messaging *</type>
      <name>messaging_object</name>
      <anchor>z19_3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual ssize_t</type>
      <name>send_i</name>
      <anchor>z19_4</anchor>
      <arglist>(iovec *iov, int iovcnt, size_t &amp;bytes_transferred, const ACE_Time_Value *timeout=0)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual ssize_t</type>
      <name>recv_i</name>
      <anchor>z19_5</anchor>
      <arglist>(char *buf, size_t len, const ACE_Time_Value *s=0)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual int</type>
      <name>consolidate_message</name>
      <anchor>z19_6</anchor>
      <arglist>(ACE_Message_Block &amp;incoming, ssize_t missing_data, TAO_Resume_Handle &amp;rh, ACE_Time_Value *max_wait_time)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual int</type>
      <name>register_handler_i</name>
      <anchor>z19_7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_SHMIOP_Connection_Handler *</type>
      <name>connection_handler_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_Pluggable_Messaging *</type>
      <name>messaging_object_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_UIOP_Acceptor</name>
    <filename>classTAO__UIOP__Acceptor.html</filename>
    <base>TAO_Acceptor</base>
    <member kind="typedef">
      <type>ACE_Strategy_Acceptor&lt; TAO_UIOP_Connection_Handler, ACE_LSOCK_ACCEPTOR &gt;</type>
      <name>TAO_UIOP_BASE_ACCEPTOR</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TAO_Creation_Strategy&lt; TAO_UIOP_Connection_Handler &gt;</type>
      <name>TAO_UIOP_CREATION_STRATEGY</name>
      <anchor>s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TAO_Concurrency_Strategy&lt; TAO_UIOP_Connection_Handler &gt;</type>
      <name>TAO_UIOP_CONCURRENCY_STRATEGY</name>
      <anchor>s2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TAO_Accept_Strategy&lt; TAO_UIOP_Connection_Handler, ACE_LSOCK_ACCEPTOR &gt;</type>
      <name>TAO_UIOP_ACCEPT_STRATEGY</name>
      <anchor>s3</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_UIOP_Acceptor</name>
      <anchor>a0</anchor>
      <arglist>(CORBA::Boolean flag=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_UIOP_Acceptor</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>open</name>
      <anchor>z20_0</anchor>
      <arglist>(TAO_ORB_Core *orb_core, ACE_Reactor *reactor, int version_major, int version_minor, const char *address, const char *options=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>open_default</name>
      <anchor>z20_1</anchor>
      <arglist>(TAO_ORB_Core *orb_core, ACE_Reactor *reactor, int version_major, int version_minor, const char *options=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>close</name>
      <anchor>z20_2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>create_profile</name>
      <anchor>z20_3</anchor>
      <arglist>(const TAO_ObjectKey &amp;object_key, TAO_MProfile &amp;mprofile, CORBA::Short priority)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>is_collocated</name>
      <anchor>z20_4</anchor>
      <arglist>(const TAO_Endpoint *endpoint)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::ULong</type>
      <name>endpoint_count</name>
      <anchor>z20_5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>object_key</name>
      <anchor>z20_6</anchor>
      <arglist>(IOP::TaggedProfile &amp;profile, TAO_ObjectKey &amp;key)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>int</type>
      <name>open_i</name>
      <anchor>c0</anchor>
      <arglist>(const char *rendezvous, ACE_Reactor *reactor)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>rendezvous_point</name>
      <anchor>c1</anchor>
      <arglist>(ACE_UNIX_Addr &amp;, const char *rendezvous)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>int</type>
      <name>parse_options</name>
      <anchor>c2</anchor>
      <arglist>(const char *options)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>int</type>
      <name>init_uiop_properties</name>
      <anchor>c3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>int</type>
      <name>create_new_profile</name>
      <anchor>c4</anchor>
      <arglist>(const TAO_ObjectKey &amp;object_key, TAO_MProfile &amp;mprofile, CORBA::Short priority)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>int</type>
      <name>create_shared_profile</name>
      <anchor>c5</anchor>
      <arglist>(const TAO_ObjectKey &amp;object_key, TAO_MProfile &amp;mprofile, CORBA::Short priority)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_UIOP_BASE_ACCEPTOR</type>
      <name>base_acceptor_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_UIOP_CREATION_STRATEGY *</type>
      <name>creation_strategy_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_UIOP_CONCURRENCY_STRATEGY *</type>
      <name>concurrency_strategy_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_UIOP_ACCEPT_STRATEGY *</type>
      <name>accept_strategy_</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_GIOP_Message_Version</type>
      <name>version_</name>
      <anchor>o4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_ORB_Core *</type>
      <name>orb_core_</name>
      <anchor>o5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>unlink_on_close_</name>
      <anchor>o6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>CORBA::Boolean</type>
      <name>lite_flag_</name>
      <anchor>o7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_UIOP_Properties</type>
      <name>uiop_properties_</name>
      <anchor>o8</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_UIOP_Connection_Handler</name>
    <filename>classTAO__UIOP__Connection__Handler.html</filename>
    <base>ACE_Svc_Handler&lt; ACE_LSOCK_STREAM, ACE_NULL_SYNCH &gt;</base>
    <base>TAO_Connection_Handler</base>
    <member kind="function">
      <type></type>
      <name>TAO_UIOP_Connection_Handler</name>
      <anchor>a0</anchor>
      <arglist>(ACE_Thread_Manager *t=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_UIOP_Connection_Handler</name>
      <anchor>a1</anchor>
      <arglist>(TAO_ORB_Core *orb_core, CORBA::Boolean flag, void *arg)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_UIOP_Connection_Handler</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>open</name>
      <anchor>a3</anchor>
      <arglist>(void *)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>activate</name>
      <anchor>a4</anchor>
      <arglist>(long flags=THR_NEW_LWP, int n_threads=1, int force_active=0, long priority=ACE_DEFAULT_THREAD_PRIORITY, int grp_id=-1, ACE_Task_Base *task=0, ACE_hthread_t thread_handles[]=0, void *stack[]=0, size_t stack_size[]=0, ACE_thread_t thread_names[]=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>svc</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>add_transport_to_cache</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>resume_handler</name>
      <anchor>z21_0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>close_connection</name>
      <anchor>z21_1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_input</name>
      <anchor>z21_2</anchor>
      <arglist>(ACE_HANDLE)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_output</name>
      <anchor>z21_3</anchor>
      <arglist>(ACE_HANDLE)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_close</name>
      <anchor>z21_4</anchor>
      <arglist>(ACE_HANDLE, ACE_Reactor_Mask)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual int</type>
      <name>release_os_resources</name>
      <anchor>z22_0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_UIOP_Properties *</type>
      <name>uiop_properties_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_UIOP_Connector</name>
    <filename>classTAO__UIOP__Connector.html</filename>
    <base>TAO_Connector</base>
    <member kind="typedef">
      <type>TAO_Connect_Concurrency_Strategy&lt; TAO_UIOP_Connection_Handler &gt;</type>
      <name>TAO_UIOP_CONNECT_CONCURRENCY_STRATEGY</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TAO_Connect_Creation_Strategy&lt; TAO_UIOP_Connection_Handler &gt;</type>
      <name>TAO_UIOP_CONNECT_CREATION_STRATEGY</name>
      <anchor>s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Connect_Strategy&lt; TAO_UIOP_Connection_Handler, ACE_LSOCK_CONNECTOR &gt;</type>
      <name>TAO_UIOP_CONNECT_STRATEGY</name>
      <anchor>s2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Strategy_Connector&lt; TAO_UIOP_Connection_Handler, ACE_LSOCK_CONNECTOR &gt;</type>
      <name>TAO_UIOP_BASE_CONNECTOR</name>
      <anchor>s3</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_UIOP_Connector</name>
      <anchor>a0</anchor>
      <arglist>(CORBA::Boolean flag=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_UIOP_Connector</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>open</name>
      <anchor>z23_0</anchor>
      <arglist>(TAO_ORB_Core *orb_core)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>close</name>
      <anchor>z23_1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_Profile *</type>
      <name>create_profile</name>
      <anchor>z23_2</anchor>
      <arglist>(TAO_InputCDR &amp;cdr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>check_prefix</name>
      <anchor>z23_3</anchor>
      <arglist>(const char *endpoint)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual char</type>
      <name>object_key_delimiter</name>
      <anchor>z23_4</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>set_validate_endpoint</name>
      <anchor>z24_0</anchor>
      <arglist>(TAO_Endpoint *endpoint)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>make_connection</name>
      <anchor>z24_1</anchor>
      <arglist>(TAO_GIOP_Invocation *invocation, TAO_Transport_Descriptor_Interface *desc, ACE_Time_Value *timeout=0)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual TAO_Profile *</type>
      <name>make_profile</name>
      <anchor>z24_2</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>init_uiop_properties</name>
      <anchor>z24_3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>TAO_UIOP_Endpoint *</type>
      <name>remote_endpoint</name>
      <anchor>c0</anchor>
      <arglist>(TAO_Endpoint *ep)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_UIOP_CONNECT_STRATEGY</type>
      <name>connect_strategy_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_UIOP_BASE_CONNECTOR</type>
      <name>base_connector_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>CORBA::Boolean</type>
      <name>lite_flag_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_UIOP_Properties</type>
      <name>uiop_properties_</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_UIOP_Endpoint</name>
    <filename>classTAO__UIOP__Endpoint.html</filename>
    <base>TAO_Endpoint</base>
    <member kind="function">
      <type></type>
      <name>TAO_UIOP_Endpoint</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_UIOP_Endpoint</name>
      <anchor>a1</anchor>
      <arglist>(const ACE_UNIX_Addr &amp;addr)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_UIOP_Endpoint</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const ACE_UNIX_Addr &amp;</type>
      <name>object_addr</name>
      <anchor>a3</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>rendezvous_point</name>
      <anchor>a4</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_Endpoint *</type>
      <name>next</name>
      <anchor>z25_0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>addr_to_string</name>
      <anchor>z25_1</anchor>
      <arglist>(char *buffer, size_t length)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>reset_hint</name>
      <anchor>z25_2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_Endpoint *</type>
      <name>duplicate</name>
      <anchor>z25_3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Boolean</type>
      <name>is_equivalent</name>
      <anchor>z25_4</anchor>
      <arglist>(const TAO_Endpoint *other_endpoint)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::ULong</type>
      <name>hash</name>
      <anchor>z25_5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UNIX_Addr</type>
      <name>object_addr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_UIOP_Endpoint *</type>
      <name>next_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend class</type>
      <name>TAO_UIOP_Profile</name>
      <anchor>l0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>TAO_UIOP_Endpoint_Info</name>
    <filename>structTAO__UIOP__Endpoint__Info.html</filename>
    <member kind="typedef">
      <type>TAO_UIOP_Endpoint_Info_var</type>
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
      <type>TAO_String_Manager</type>
      <name>rendezvous_point</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>CORBA::Short</type>
      <name>priority</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>string</type>
      <name>rendezvous_point</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>short</type>
      <name>priority</name>
      <anchor>m3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_UIOP_Lite_Protocol_Factory</name>
    <filename>classTAO__UIOP__Lite__Protocol__Factory.html</filename>
    <base>TAO_Protocol_Factory</base>
    <member kind="function">
      <type></type>
      <name>TAO_UIOP_Lite_Protocol_Factory</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_UIOP_Lite_Protocol_Factory</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>init</name>
      <anchor>a2</anchor>
      <arglist>(int argc, ACE_TCHAR *argv[])</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>match_prefix</name>
      <anchor>a3</anchor>
      <arglist>(const ACE_CString &amp;prefix)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>prefix</name>
      <anchor>a4</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual char</type>
      <name>options_delimiter</name>
      <anchor>a5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_Acceptor *</type>
      <name>make_acceptor</name>
      <anchor>z27_0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_Connector *</type>
      <name>make_connector</name>
      <anchor>z27_1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>requires_explicit_endpoint</name>
      <anchor>z27_2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>major_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>minor_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_UIOP_Profile</name>
    <filename>classTAO__UIOP__Profile.html</filename>
    <base>TAO_Profile</base>
    <member kind="function" virtualness="virtual">
      <type>virtual char</type>
      <name>object_key_delimiter</name>
      <anchor>a0</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_UIOP_Profile</name>
      <anchor>a1</anchor>
      <arglist>(const ACE_UNIX_Addr &amp;addr, const TAO_ObjectKey &amp;object_key, const TAO_GIOP_Message_Version &amp;version, TAO_ORB_Core *orb_core)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_UIOP_Profile</name>
      <anchor>a2</anchor>
      <arglist>(const char *rendezvous_point, const TAO_ObjectKey &amp;object_key, const ACE_UNIX_Addr &amp;addr, const TAO_GIOP_Message_Version &amp;version, TAO_ORB_Core *orb_core)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_UIOP_Profile</name>
      <anchor>a3</anchor>
      <arglist>(TAO_ORB_Core *orb_core)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_UIOP_Profile</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>parse_string</name>
      <anchor>a5</anchor>
      <arglist>(const char *string ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual char *</type>
      <name>to_string</name>
      <anchor>a6</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>decode</name>
      <anchor>a7</anchor>
      <arglist>(TAO_InputCDR &amp;cdr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>encode</name>
      <anchor>a8</anchor>
      <arglist>(TAO_OutputCDR &amp;stream) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>encode_endpoints</name>
      <anchor>a9</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const TAO_ObjectKey &amp;</type>
      <name>object_key</name>
      <anchor>a10</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_ObjectKey *</type>
      <name>_key</name>
      <anchor>a11</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_Endpoint *</type>
      <name>endpoint</name>
      <anchor>a12</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual size_t</type>
      <name>endpoint_count</name>
      <anchor>a13</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>add_endpoint</name>
      <anchor>a14</anchor>
      <arglist>(TAO_UIOP_Endpoint *endp)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>is_equivalent</name>
      <anchor>a15</anchor>
      <arglist>(const TAO_Profile *other_profile)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::ULong</type>
      <name>hash</name>
      <anchor>a16</anchor>
      <arglist>(CORBA::ULong max ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual IOP::TaggedProfile &amp;</type>
      <name>create_tagged_profile</name>
      <anchor>a17</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>prefix</name>
      <anchor>d0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char</type>
      <name>object_key_delimiter_</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>create_profile_body</name>
      <anchor>c0</anchor>
      <arglist>(TAO_OutputCDR &amp;cdr) const</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>int</type>
      <name>decode_endpoints</name>
      <anchor>c1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_UIOP_Endpoint</type>
      <name>endpoint_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>size_t</type>
      <name>count_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_ObjectKey</type>
      <name>object_key_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>IOP::TaggedProfile</type>
      <name>tagged_profile_</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_UIOP_Properties</name>
    <filename>classTAO__UIOP__Properties.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>send_buffer_size</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>recv_buffer_size</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_UIOP_Protocol_Factory</name>
    <filename>classTAO__UIOP__Protocol__Factory.html</filename>
    <base>TAO_Protocol_Factory</base>
    <member kind="function">
      <type></type>
      <name>TAO_UIOP_Protocol_Factory</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_UIOP_Protocol_Factory</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>init</name>
      <anchor>a2</anchor>
      <arglist>(int argc, ACE_TCHAR *argv[])</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>match_prefix</name>
      <anchor>a3</anchor>
      <arglist>(const ACE_CString &amp;prefix)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>prefix</name>
      <anchor>a4</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual char</type>
      <name>options_delimiter</name>
      <anchor>a5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_Acceptor *</type>
      <name>make_acceptor</name>
      <anchor>z26_0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_Connector *</type>
      <name>make_connector</name>
      <anchor>z26_1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>requires_explicit_endpoint</name>
      <anchor>z26_2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>major_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>minor_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_UIOP_Transport</name>
    <filename>classTAO__UIOP__Transport.html</filename>
    <base>TAO_Transport</base>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>send_request</name>
      <anchor>z28_0</anchor>
      <arglist>(TAO_Stub *stub, TAO_ORB_Core *orb_core, TAO_OutputCDR &amp;stream, int message_semantics, ACE_Time_Value *max_wait_time)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>send_message</name>
      <anchor>z28_1</anchor>
      <arglist>(TAO_OutputCDR &amp;stream, TAO_Stub *stub=0, int message_semantics=TAO_Transport::TAO_TWOWAY_REQUEST, ACE_Time_Value *max_time_wait=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>messaging_init</name>
      <anchor>z28_2</anchor>
      <arglist>(CORBA::Octet major, CORBA::Octet minor)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual ACE_Event_Handler *</type>
      <name>event_handler_i</name>
      <anchor>z28_3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual TAO_Connection_Handler *</type>
      <name>connection_handler_i</name>
      <anchor>z28_4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual TAO_Connection_Handler *</type>
      <name>invalidate_event_handler_i</name>
      <anchor>z28_5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual TAO_Pluggable_Messaging *</type>
      <name>messaging_object</name>
      <anchor>z28_6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual ssize_t</type>
      <name>send_i</name>
      <anchor>z28_7</anchor>
      <arglist>(iovec *iov, int iovcnt, size_t &amp;bytes_transferred, const ACE_Time_Value *timeout=0)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual ssize_t</type>
      <name>recv_i</name>
      <anchor>z28_8</anchor>
      <arglist>(char *buf, size_t len, const ACE_Time_Value *s=0)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual int</type>
      <name>register_handler_i</name>
      <anchor>z28_9</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_UIOP_Transport</name>
      <anchor>a0</anchor>
      <arglist>(TAO_UIOP_Connection_Handler *handler, TAO_ORB_Core *orb_core, CORBA::Boolean flag)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_UIOP_Transport</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_UIOP_Connection_Handler *</type>
      <name>connection_handler_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_Pluggable_Messaging *</type>
      <name>messaging_object_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_UIOPEndpointSequence</name>
    <filename>classTAO__UIOPEndpointSequence.html</filename>
    <base>_TAO_Unbounded_Sequence_TAO_UIOPEndpointSequence</base>
    <member kind="typedef">
      <type>TAO_UIOPEndpointSequence_var</type>
      <name>_var_type</name>
      <anchor>s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_UIOPEndpointSequence</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_UIOPEndpointSequence</name>
      <anchor>a1</anchor>
      <arglist>(CORBA::ULong max)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_UIOPEndpointSequence</name>
      <anchor>a2</anchor>
      <arglist>(CORBA::ULong max, CORBA::ULong length, TAO_UIOP_Endpoint_Info *buffer, CORBA::Boolean release=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_UIOPEndpointSequence</name>
      <anchor>a3</anchor>
      <arglist>(const TAO_UIOPEndpointSequence &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_UIOPEndpointSequence</name>
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
    <name>TAO_UIOPEndpointSequence_var</name>
    <filename>classTAO__UIOPEndpointSequence__var.html</filename>
    <member kind="function">
      <type></type>
      <name>TAO_UIOPEndpointSequence_var</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_UIOPEndpointSequence_var</name>
      <anchor>a1</anchor>
      <arglist>(TAO_UIOPEndpointSequence *)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_UIOPEndpointSequence_var</name>
      <anchor>a2</anchor>
      <arglist>(const TAO_UIOPEndpointSequence_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_UIOPEndpointSequence_var</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_UIOPEndpointSequence_var &amp;</type>
      <name>operator=</name>
      <anchor>a4</anchor>
      <arglist>(TAO_UIOPEndpointSequence *)</arglist>
    </member>
    <member kind="function">
      <type>TAO_UIOPEndpointSequence_var &amp;</type>
      <name>operator=</name>
      <anchor>a5</anchor>
      <arglist>(const TAO_UIOPEndpointSequence_var &amp;)</arglist>
    </member>
    <member kind="function">
      <type>TAO_UIOPEndpointSequence *</type>
      <name>operator-&gt;</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const TAO_UIOPEndpointSequence *</type>
      <name>operator-&gt;</name>
      <anchor>a7</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator const TAO_UIOPEndpointSequence &amp;</name>
      <anchor>a8</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator TAO_UIOPEndpointSequence &amp;</name>
      <anchor>a9</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator TAO_UIOPEndpointSequence &amp;</name>
      <anchor>a10</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>operator TAO_UIOPEndpointSequence *&amp;</name>
      <anchor>a11</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>TAO_UIOP_Endpoint_Info &amp;</type>
      <name>operator[]</name>
      <anchor>a12</anchor>
      <arglist>(CORBA::ULong index)</arglist>
    </member>
    <member kind="function">
      <type>const TAO_UIOPEndpointSequence &amp;</type>
      <name>in</name>
      <anchor>a13</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>TAO_UIOPEndpointSequence &amp;</type>
      <name>inout</name>
      <anchor>a14</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_UIOPEndpointSequence *&amp;</type>
      <name>out</name>
      <anchor>a15</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_UIOPEndpointSequence *</type>
      <name>_retn</name>
      <anchor>a16</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_UIOPEndpointSequence *</type>
      <name>ptr</name>
      <anchor>a17</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_UIOPEndpointSequence *</type>
      <name>ptr_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
</tagfile>
