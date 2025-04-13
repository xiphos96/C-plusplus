<?xml version='1.0' encoding='ISO-8859-1' standalone='yes'?>
<tagfile>
  <compound kind="file">
    <name>AV_Core.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>AV__Core_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>AV_Core.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>AV__Core_8h.html</filename>
    <class kind="class">TAO_AV_Core</class>
    <member kind="typedef">
      <type>ACE_Unbounded_Set&lt; TAO_FlowSpec_Entry *&gt;</type>
      <name>TAO_AV_FlowSpecSet</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Unbounded_Set_Iterator&lt; TAO_FlowSpec_Entry *&gt;</type>
      <name>TAO_AV_FlowSpecSetItor</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Unbounded_Set&lt; TAO_AV_Transport_Item *&gt;</type>
      <name>TAO_AV_TransportFactorySet</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Unbounded_Set_Iterator&lt; TAO_AV_Transport_Item *&gt;</type>
      <name>TAO_AV_TransportFactorySetItor</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Unbounded_Set&lt; TAO_AV_Flow_Protocol_Item *&gt;</type>
      <name>TAO_AV_Flow_ProtocolFactorySet</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Unbounded_Set_Iterator&lt; TAO_AV_Flow_Protocol_Item *&gt;</type>
      <name>TAO_AV_Flow_ProtocolFactorySetItor</name>
      <anchor>a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Singleton&lt; TAO_AV_Core, ACE_Null_Mutex &gt;</type>
      <name>TAO_AV_CORE</name>
      <anchor>a6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>AV_export.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>AV__export_8h.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>TAO_AV_HAS_DLL</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TAO_AV_Export</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TAO_AV_SINGLETON_DECLARATION</name>
      <anchor>a2</anchor>
      <arglist>(T)</arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TAO_AV_SINGLETON_DECLARE</name>
      <anchor>a3</anchor>
      <arglist>(SINGLETON_TYPE, CLASS, LOCK)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>AVStreams.idl</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/</path>
    <filename>AVStreams_8idl.html</filename>
    <namespace>AVStreams</namespace>
    <class kind="interface">AVStreams::Basic_StreamCtrl</class>
    <class kind="struct">AVStreams::flowStatus</class>
    <class kind="interface">AVStreams::MCastConfigIf</class>
    <class kind="interface">AVStreams::MediaControl</class>
    <class kind="interface">AVStreams::MMDevice</class>
    <class kind="interface">AVStreams::Negotiator</class>
    <class kind="struct">AVStreams::QoS</class>
    <class kind="struct">AVStreams::SFPStatus</class>
    <class kind="interface">AVStreams::StreamCtrl</class>
    <class kind="interface">AVStreams::StreamEndPoint_A</class>
    <class kind="interface">AVStreams::StreamEndPoint_B</class>
    <class kind="interface">AVStreams::VDev</class>
  </compound>
  <compound kind="file">
    <name>AVStreams_i.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>AVStreams__i_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_AV_AVStreams_i</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>operator&lt;</name>
      <anchor>a2</anchor>
      <arglist>(const MMDevice_Map_Hash_Key &amp;left, const MMDevice_Map_Hash_Key &amp;right)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_AV_AVStreams_i</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>AVStreams_i.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>AVStreams__i_8h.html</filename>
    <class kind="class">AV_Null_MediaCtrl</class>
    <class kind="class">TAO_AV_QoS</class>
    <class kind="class">TAO_Base_StreamEndPoint</class>
    <class kind="class">TAO_FlowConnection</class>
    <class kind="class">TAO_FlowConsumer</class>
    <class kind="class">TAO_FlowEndPoint</class>
    <class kind="class">TAO_FlowProducer</class>
    <class kind="struct">TAO_MCastConfigIf::Peer_Info</class>
    <class kind="class">TAO_MCastConfigIf</class>
    <class kind="class">TAO_MediaControl</class>
    <class kind="class">TAO_MMDevice</class>
    <class kind="struct">TAO_StreamCtrl::MMDevice_Map_Entry</class>
    <class kind="class">MMDevice_Map_Hash_Key</class>
    <class kind="class">TAO_Basic_StreamCtrl</class>
    <class kind="class">TAO_Negotiator</class>
    <class kind="class">TAO_StreamCtrl</class>
    <class kind="class">TAO_StreamEndPoint</class>
    <class kind="class">TAO_StreamEndPoint_A</class>
    <class kind="class">TAO_StreamEndPoint_B</class>
    <class kind="class">TAO_VDev</class>
    <member kind="define">
      <type>#define</type>
      <name>FLOWSPEC_MAX</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TAO_Client_StreamEndPoint</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TAO_Server_StreamEndPoint</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Hash_Map_Manager&lt; ACE_CString, AVStreams::FlowEndPoint_var, ACE_Null_Mutex &gt;</type>
      <name>FlowEndPoint_Map</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Hash_Map_Entry&lt; ACE_CString, AVStreams::FlowEndPoint_var &gt;</type>
      <name>FlowEndPoint_Map_Entry</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Hash_Map_Iterator&lt; ACE_CString, AVStreams::FlowEndPoint_var, ACE_Null_Mutex &gt;</type>
      <name>FlowEndPoint_Map_Iterator</name>
      <anchor>a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Hash_Map_Manager&lt; ACE_CString, TAO_AV_Flow_Handler *, ACE_Null_Mutex &gt;</type>
      <name>Flow_Handler_Map</name>
      <anchor>a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Hash_Map_Entry&lt; ACE_CString, TAO_AV_Flow_Handler *&gt;</type>
      <name>Flow_Handler_Map_Entry</name>
      <anchor>a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Hash_Map_Iterator&lt; ACE_CString, TAO_AV_Flow_Handler *, ACE_Null_Mutex &gt;</type>
      <name>Flow_Handler_Map_Iterator</name>
      <anchor>a8</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>AVStreams_i.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>AVStreams__i_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>default_resource.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>default__resource_8cpp.html</filename>
    <member kind="function">
      <type></type>
      <name>ACE_STATIC_SVC_DEFINE</name>
      <anchor>a0</anchor>
      <arglist>(TAO_AV_Default_Resource_Factory, ACE_TEXT(&quot;AV_Default_Resource_Factory&quot;), ACE_SVC_OBJ_T,&amp;ACE_SVC_NAME(TAO_AV_Default_Resource_Factory), ACE_Service_Type::DELETE_THIS|ACE_Service_Type::DELETE_OBJ, 0) ACE_FACTORY_DEFINE(TAO_AV</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>default_resource.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>default__resource_8h.html</filename>
    <class kind="class">TAO_AV_Default_Resource_Factory</class>
    <member kind="function">
      <type></type>
      <name>ACE_STATIC_SVC_DECLARE_EXPORT</name>
      <anchor>a0</anchor>
      <arglist>(TAO_AV, TAO_AV_Default_Resource_Factory) ACE_FACTORY_DECLARE(TAO_AV</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Endpoint_Strategy.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>Endpoint__Strategy_8cpp.html</filename>
    <member kind="function" static="yes">
      <type>const char *</type>
      <name>get_rcsid_AV_Endpoint_Strategy</name>
      <anchor>a1</anchor>
      <arglist>(const char *)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>rcsid_AV_Endpoint_Strategy</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Endpoint_Strategy.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>Endpoint__Strategy_8h.html</filename>
    <class kind="class">TAO_AV_Endpoint_Process_Strategy</class>
    <class kind="class">TAO_AV_Endpoint_Process_Strategy_A</class>
    <class kind="class">TAO_AV_Endpoint_Process_Strategy_B</class>
    <class kind="class">TAO_AV_Endpoint_Strategy</class>
  </compound>
  <compound kind="file">
    <name>Endpoint_Strategy_T.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>Endpoint__Strategy__T_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>Endpoint_Strategy_T.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>Endpoint__Strategy__T_8h.html</filename>
    <class kind="class">TAO_AV_Child_Process</class>
    <class kind="class">TAO_AV_Child_Process_A</class>
    <class kind="class">TAO_AV_Child_Process_B</class>
    <class kind="class">TAO_AV_Endpoint_Reactive_Strategy</class>
    <class kind="class">TAO_AV_Endpoint_Reactive_Strategy_A</class>
    <class kind="class">TAO_AV_Endpoint_Reactive_Strategy_B</class>
  </compound>
  <compound kind="file">
    <name>Fill_ACE_QoS.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>Fill__ACE__QoS_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>Fill_ACE_QoS.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>Fill__ACE__QoS_8h.html</filename>
  </compound>
  <compound kind="file">
    <name>Flows_T.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>Flows__T_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>Flows_T.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>Flows__T_8h.html</filename>
    <class kind="class">TAO_FDev</class>
  </compound>
  <compound kind="file">
    <name>FlowSpec_Entry.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>FlowSpec__Entry_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>FlowSpec_Entry.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>FlowSpec__Entry_8h.html</filename>
    <class kind="class">TAO_FlowSpec_Entry</class>
    <class kind="class">TAO_Forward_FlowSpec_Entry</class>
    <class kind="class">TAO_Reverse_FlowSpec_Entry</class>
    <class kind="class">TAO_Tokenizer</class>
  </compound>
  <compound kind="file">
    <name>FlowSpec_Entry.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>FlowSpec__Entry_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>global.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>global_8h.html</filename>
    <member kind="define">
      <type>#define</type>
      <name>PROTOTYPES</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>PROTO_LIST</name>
      <anchor>a1</anchor>
      <arglist>(list)</arglist>
    </member>
    <member kind="typedef">
      <type>unsigned char *</type>
      <name>POINTER</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>unsigned short int</type>
      <name>UINT2</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>unsigned long int</type>
      <name>UINT4</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>MCast.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>MCast_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>MCast.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>MCast_8h.html</filename>
    <class kind="class">TAO_AV_UDP_MCast_Flow_Handler</class>
    <class kind="class">TAO_AV_UDP_MCast_Transport</class>
  </compound>
  <compound kind="file">
    <name>MCast.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>MCast_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>md5.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>md5_8h.html</filename>
    <class kind="struct">MD5_CTX</class>
    <member kind="function">
      <type>void</type>
      <name>MD5Init</name>
      <anchor>a0</anchor>
      <arglist>(MD5_CTX *context)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>MD5Update</name>
      <anchor>a1</anchor>
      <arglist>(MD5_CTX *context, unsigned char *input, unsigned int inputLen)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>MD5Final</name>
      <anchor>a2</anchor>
      <arglist>(unsigned char digest[16], MD5_CTX *context)</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>media-timer.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>media-timer_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>media-timer.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>media-timer_8h.html</filename>
    <class kind="class">MediaTimer</class>
  </compound>
  <compound kind="file">
    <name>media_timer.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>media__timer_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>media_timer.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>media__timer_8h.html</filename>
    <class kind="class">MediaTimer</class>
  </compound>
  <compound kind="file">
    <name>Nil.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>Nil_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>Nil.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>Nil_8h.html</filename>
  </compound>
  <compound kind="file">
    <name>ntp-time.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>ntp-time_8h.html</filename>
    <member kind="function">
      <type>ACE_INLINE u_int</type>
      <name>usec2ntp</name>
      <anchor>a1</anchor>
      <arglist>(u_int usec)</arglist>
    </member>
    <member kind="function">
      <type>ACE_INLINE TAO_AV_RTCP::ntp64</type>
      <name>ntp64time</name>
      <anchor>a2</anchor>
      <arglist>(timeval tv)</arglist>
    </member>
    <member kind="function">
      <type>ACE_INLINE ACE_UINT32</type>
      <name>ntptime</name>
      <anchor>a3</anchor>
      <arglist>(timeval t)</arglist>
    </member>
    <member kind="function">
      <type>ACE_INLINE ACE_UINT32</type>
      <name>ntptime</name>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>ACE_INLINE timeval</type>
      <name>unixtime</name>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable">
      <type>const ACE_UINT32</type>
      <name>GETTIMEOFDAY_TO_NTP_OFFSET</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Null_MediaCtrl.idl</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/</path>
    <filename>Null__MediaCtrl_8idl.html</filename>
    <class kind="interface">Null_MediaCtrl</class>
  </compound>
  <compound kind="file">
    <name>Policy.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>Policy_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>Policy.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>Policy_8h.html</filename>
    <class kind="class">TAO_AV_Callback</class>
    <class kind="struct">TAO_AV_frame_info</class>
    <class kind="class">TAO_AV_Payload_Type_Policy</class>
    <class kind="class">TAO_AV_Policy</class>
    <class kind="struct">TAO_AV_RTCP_Sdes</class>
    <class kind="class">TAO_AV_RTCP_Sdes_Policy</class>
    <class kind="class">TAO_AV_SFP_Credit_Policy</class>
    <class kind="class">TAO_AV_SSRC_Policy</class>
    <member kind="define">
      <type>#define</type>
      <name>TAO_AV_SSRC_POLICY</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TAO_AV_PAYLOAD_TYPE_POLICY</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TAO_AV_TIMEOUT_POLICY</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TAO_AV_RTCP_SDES_POLICY</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TAO_AV_SFP_CREDIT_POLICY</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>TAO_Unbounded_Sequence&lt; TAO_AV_Policy *&gt;</type>
      <name>TAO_AV_PolicyList</name>
      <anchor>a5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Policy.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>Policy_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>Protocol_Factory.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>Protocol__Factory_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>Protocol_Factory.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>Protocol__Factory_8h.html</filename>
    <class kind="class">TAO_AV_Flow_Protocol_Factory</class>
    <class kind="class">TAO_AV_Protocol_Object</class>
  </compound>
  <compound kind="file">
    <name>QoS_UDP.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>QoS__UDP_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>QoS_UDP.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>QoS__UDP_8h.html</filename>
  </compound>
  <compound kind="file">
    <name>QoS_UDP.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>QoS__UDP_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>Resource_Factory.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>Resource__Factory_8h.html</filename>
    <class kind="class">TAO_AV_Resource_Factory</class>
    <member kind="define">
      <type>#define</type>
      <name>TAO_AV_DEFAULT_RESOURCE_FCATORY_H</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>RTCP.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>RTCP_8cpp.html</filename>
    <member kind="function">
      <type>ACE_INT32</type>
      <name>random32</name>
      <anchor>a1</anchor>
      <arglist>(int)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACE_FACTORY_DEFINE</name>
      <anchor>a2</anchor>
      <arglist>(TAO_AV, TAO_AV_RTCP_Flow_Factory) ACE_STATIC_SVC_DEFINE(TAO_AV_RTCP_Flow_Factory</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACE_TEXT</name>
      <anchor>a3</anchor>
      <arglist>(&quot;RTCP_Flow_Factory&quot;)</arglist>
    </member>
    <member kind="function">
      <type>&amp;</type>
      <name>ACE_SVC_NAME</name>
      <anchor>a4</anchor>
      <arglist>(TAO_AV_RTCP_Flow_Factory)</arglist>
    </member>
    <member kind="variable">
      <type></type>
      <name>ACE_SVC_OBJ_T</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>RTCP.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>RTCP_8h.html</filename>
    <class kind="struct">TAO_AV_RTCP::md5_string</class>
    <class kind="struct">TAO_AV_RTCP::ntp64</class>
    <class kind="struct">TAO_AV_RTCP::rtcphdr</class>
    <class kind="class">TAO_AV_RTCP</class>
    <class kind="class">TAO_AV_RTCP_Callback</class>
    <class kind="class">TAO_AV_RTCP_Flow_Factory</class>
    <class kind="class">TAO_AV_RTCP_Object</class>
    <member kind="function">
      <type></type>
      <name>ACE_STATIC_SVC_DECLARE</name>
      <anchor>a0</anchor>
      <arglist>(TAO_AV_RTCP_Flow_Factory) ACE_FACTORY_DECLARE(TAO_AV</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>RTCP_Channel.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>RTCP__Channel_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>RTCP_Channel.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>RTCP__Channel_8h.html</filename>
    <class kind="class">RTCP_Channel_In</class>
    <class kind="class">RTCP_Channel_Out</class>
  </compound>
  <compound kind="file">
    <name>RTCP_Packet.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>RTCP__Packet_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>RTCP_Packet.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>RTCP__Packet_8h.html</filename>
    <class kind="class">RTCP_SDES_Packet</class>
    <class kind="class">RTCP_SR_Packet</class>
    <class kind="struct">sdesChunk_s</class>
    <class kind="struct">RR_Block</class>
    <class kind="class">RTCP_BYE_Packet</class>
    <class kind="struct">RTCP_Common_Header</class>
    <class kind="class">RTCP_Packet</class>
    <class kind="class">RTCP_RR_Packet</class>
    <class kind="struct">sdesItem_s</class>
    <member kind="typedef">
      <type>sdesItem_s</type>
      <name>sdesItem_t</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>sdesChunk_s</type>
      <name>sdesChunk_t</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>RTP.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>RTP_8cpp.html</filename>
    <member kind="function">
      <type></type>
      <name>ACE_FACTORY_DEFINE</name>
      <anchor>a1</anchor>
      <arglist>(TAO_AV, TAO_AV_RTP_Flow_Factory) ACE_STATIC_SVC_DEFINE(TAO_AV_RTP_Flow_Factory</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACE_TEXT</name>
      <anchor>a2</anchor>
      <arglist>(&quot;RTP_Flow_Factory&quot;)</arglist>
    </member>
    <member kind="function">
      <type>&amp;</type>
      <name>ACE_SVC_NAME</name>
      <anchor>a3</anchor>
      <arglist>(TAO_AV_RTP_Flow_Factory)</arglist>
    </member>
    <member kind="variable">
      <type></type>
      <name>ACE_SVC_OBJ_T</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>RTP.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>RTP_8h.html</filename>
    <class kind="class">RTP_Packet</class>
    <class kind="struct">TAO_AV_RTP::bvchdr</class>
    <class kind="struct">TAO_AV_RTP::cellbhdr</class>
    <class kind="struct">TAO_AV_RTP::nvhdr</class>
    <class kind="struct">TAO_AV_RTP::jpeghdr</class>
    <class kind="struct">TAO_AV_RTP::rtphdr</class>
    <class kind="class">TAO_AV_RTP</class>
    <class kind="class">TAO_AV_RTP_Flow_Factory</class>
    <class kind="class">TAO_AV_RTP_Object</class>
    <member kind="define">
      <type>#define</type>
      <name>RTP_PT_BVC</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_PT_RGB8</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_PT_HDCC</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_PT_CELLB</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_PT_JPEG</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_PT_CUSEEME</name>
      <anchor>a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_PT_NV</name>
      <anchor>a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_PT_PICW</name>
      <anchor>a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_PT_CPV</name>
      <anchor>a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_PT_H261</name>
      <anchor>a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_PT_MPEG</name>
      <anchor>a10</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_PT_MP2T</name>
      <anchor>a11</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_PT_H261_COMPAT</name>
      <anchor>a12</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_PT_PCMU</name>
      <anchor>a13</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_PT_CELP</name>
      <anchor>a14</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_PT_G721</name>
      <anchor>a15</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_PT_GSM</name>
      <anchor>a16</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_PT_DVI</name>
      <anchor>a17</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_PT_LPC</name>
      <anchor>a18</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_PT_PCMA</name>
      <anchor>a19</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_PT_G722</name>
      <anchor>a20</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_PT_L16_STEREO</name>
      <anchor>a21</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_PT_L16_MONO</name>
      <anchor>a22</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_PT_L16_OTHER</name>
      <anchor>a23</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_EPOCH_OFFSET</name>
      <anchor>a24</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_VERSION</name>
      <anchor>a25</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_M</name>
      <anchor>a26</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_P</name>
      <anchor>a27</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_X</name>
      <anchor>a28</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTCP_PT_SR</name>
      <anchor>a29</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTCP_PT_RR</name>
      <anchor>a30</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTCP_PT_SDES</name>
      <anchor>a31</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTCP_SDES_END</name>
      <anchor>a32</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTCP_SDES_CNAME</name>
      <anchor>a33</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTCP_SDES_NAME</name>
      <anchor>a34</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTCP_SDES_EMAIL</name>
      <anchor>a35</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTCP_SDES_PHONE</name>
      <anchor>a36</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTCP_SDES_LOC</name>
      <anchor>a37</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTCP_SDES_TOOL</name>
      <anchor>a38</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTCP_SDES_NOTE</name>
      <anchor>a39</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTCP_SDES_PRIV</name>
      <anchor>a40</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTCP_PT_BYE</name>
      <anchor>a41</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTCP_PT_APP</name>
      <anchor>a42</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTCP_SDES_MIN</name>
      <anchor>a43</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_SEQ_MOD</name>
      <anchor>a44</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTCP_SESSION_BW_FRACTION</name>
      <anchor>a45</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTCP_MIN_RPT_TIME</name>
      <anchor>a46</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTCP_SENDER_BW_FRACTION</name>
      <anchor>a47</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTCP_RECEIVER_BW_FRACTION</name>
      <anchor>a48</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTCP_SIZE_GAIN</name>
      <anchor>a49</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>RTP_MTU</name>
      <anchor>a50</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>MAXHDR</name>
      <anchor>a51</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACE_STATIC_SVC_DECLARE</name>
      <anchor>a52</anchor>
      <arglist>(TAO_AV_RTP_Flow_Factory) ACE_FACTORY_DECLARE(TAO_AV</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>sfp.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>sfp_8cpp.html</filename>
    <member kind="function">
      <type>int</type>
      <name>operator&lt;</name>
      <anchor>a1</anchor>
      <arglist>(const TAO_SFP_Fragment_Node &amp;left, const TAO_SFP_Fragment_Node &amp;right)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACE_FACTORY_DEFINE</name>
      <anchor>a2</anchor>
      <arglist>(TAO_AV, TAO_AV_SFP_Factory) ACE_STATIC_SVC_DEFINE(TAO_AV_SFP_Factory</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACE_TEXT</name>
      <anchor>a3</anchor>
      <arglist>(&quot;SFP_Factory&quot;)</arglist>
    </member>
    <member kind="function">
      <type>&amp;</type>
      <name>ACE_SVC_NAME</name>
      <anchor>a4</anchor>
      <arglist>(TAO_AV_SFP_Factory)</arglist>
    </member>
    <member kind="variable">
      <type></type>
      <name>ACE_SVC_OBJ_T</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>sfp.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>sfp_8h.html</filename>
    <class kind="class">TAO_AV_SFP_Factory</class>
    <class kind="class">TAO_SFP_Base</class>
    <class kind="class">TAO_SFP_Consumer_Object</class>
    <class kind="class">TAO_SFP_Fragment_Node</class>
    <class kind="class">TAO_SFP_Fragment_Table_Entry</class>
    <class kind="class">TAO_SFP_Frame_State</class>
    <class kind="class">TAO_SFP_Object</class>
    <class kind="class">TAO_SFP_Producer_Object</class>
    <member kind="define">
      <type>#define</type>
      <name>TAO_SFP_MAGIC_NUMBER_LEN</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TAO_SFP_MESSAGE_TYPE_OFFSET</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TAO_SFP_WRITEV_MAX</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="define">
      <type>#define</type>
      <name>TAO_SFP_MAX_PACKET_SIZE</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Ordered_MultiSet_Iterator&lt; TAO_SFP_Fragment_Node &gt;</type>
      <name>FRAGMENT_SET_ITERATOR</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Hash_Map_Manager&lt; CORBA::ULong, TAO_SFP_Fragment_Table_Entry *, ACE_Null_Mutex &gt;</type>
      <name>TAO_SFP_Fragment_Table</name>
      <anchor>a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Hash_Map_Manager&lt; CORBA::ULong, TAO_SFP_Fragment_Table *, ACE_Null_Mutex &gt;</type>
      <name>TAO_SFP_Fragment_Table_Map</name>
      <anchor>a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Singleton&lt; TAO_SFP_Base, TAO_SYNCH_MUTEX &gt;</type>
      <name>TAO_SFP_BASE</name>
      <anchor>a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACE_STATIC_SVC_DECLARE</name>
      <anchor>a8</anchor>
      <arglist>(TAO_AV_SFP_Flow_Factory) ACE_FACTORY_DECLARE(TAO_AV</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>sfp.idl</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/</path>
    <filename>sfp_8idl.html</filename>
    <namespace>flowProtocol</namespace>
  </compound>
  <compound kind="file">
    <name>TCP.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>TCP_8cpp.html</filename>
    <member kind="function">
      <type></type>
      <name>ACE_STATIC_SVC_DEFINE</name>
      <anchor>a0</anchor>
      <arglist>(TAO_AV_TCP_Flow_Factory, ACE_TEXT(&quot;TCP_Flow_Factory&quot;), ACE_SVC_OBJ_T,&amp;ACE_SVC_NAME(TAO_AV_TCP_Flow_Factory), ACE_Service_Type::DELETE_THIS|ACE_Service_Type::DELETE_OBJ, 0) ACE_FACTORY_DEFINE(TAO_AV</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_TCP_Flow_Factory</type>
      <name>ACE_STATIC_SVC_DEFINE</name>
      <anchor>a1</anchor>
      <arglist>(TAO_AV_TCP_Factory, ACE_TEXT(&quot;TCP_Factory&quot;), ACE_SVC_OBJ_T,&amp;ACE_SVC_NAME(TAO_AV_TCP_Factory), ACE_Service_Type::DELETE_THIS|ACE_Service_Type::DELETE_OBJ, 0) ACE_FACTORY_DEFINE(TAO_AV</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>TCP.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>TCP_8h.html</filename>
    <class kind="class">TAO_AV_TCP_Acceptor</class>
    <class kind="class">TAO_AV_TCP_Base_Acceptor</class>
    <class kind="class">TAO_AV_TCP_Base_Connector</class>
    <class kind="class">TAO_AV_TCP_Connector</class>
    <class kind="class">TAO_AV_TCP_Factory</class>
    <class kind="class">TAO_AV_TCP_Flow_Factory</class>
    <class kind="class">TAO_AV_TCP_Flow_Handler</class>
    <class kind="class">TAO_AV_TCP_Object</class>
    <class kind="class">TAO_AV_TCP_Transport</class>
    <member kind="function">
      <type></type>
      <name>ACE_STATIC_SVC_DECLARE</name>
      <anchor>a0</anchor>
      <arglist>(TAO_AV_TCP_Flow_Factory) ACE_FACTORY_DECLARE(TAO_AV</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Transport.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>Transport_8cpp.html</filename>
  </compound>
  <compound kind="file">
    <name>Transport.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>Transport_8h.html</filename>
    <class kind="class">TAO_AV_Acceptor</class>
    <class kind="class">TAO_AV_Acceptor_Registry</class>
    <class kind="class">TAO_AV_Connector</class>
    <class kind="class">TAO_AV_Connector_Registry</class>
    <class kind="class">TAO_AV_Flow_Handler</class>
    <class kind="class">TAO_AV_Flow_Protocol_Item</class>
    <class kind="class">TAO_AV_Transport</class>
    <class kind="class">TAO_AV_Transport_Factory</class>
    <class kind="class">TAO_AV_Transport_Item</class>
    <member kind="typedef">
      <type>ACE_Unbounded_Set&lt; TAO_AV_Connector *&gt;</type>
      <name>TAO_AV_ConnectorSet</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Unbounded_Set_Iterator&lt; TAO_AV_Connector *&gt;</type>
      <name>TAO_AV_ConnectorSetItor</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Unbounded_Set&lt; TAO_AV_Acceptor *&gt;</type>
      <name>TAO_AV_AcceptorSet</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>ACE_Unbounded_Set_Iterator&lt; TAO_AV_Acceptor *&gt;</type>
      <name>TAO_AV_AcceptorSetItor</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>Transport.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>Transport_8i.html</filename>
  </compound>
  <compound kind="file">
    <name>UDP.cpp</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>UDP_8cpp.html</filename>
    <member kind="function">
      <type></type>
      <name>ACE_FACTORY_DEFINE</name>
      <anchor>a1</anchor>
      <arglist>(TAO_AV, TAO_AV_UDP_Flow_Factory) ACE_STATIC_SVC_DEFINE(TAO_AV_UDP_Flow_Factory</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>ACE_TEXT</name>
      <anchor>a2</anchor>
      <arglist>(&quot;UDP_Flow_Factory&quot;)</arglist>
    </member>
    <member kind="function">
      <type>&amp;</type>
      <name>ACE_SVC_NAME</name>
      <anchor>a3</anchor>
      <arglist>(TAO_AV_UDP_Flow_Factory)</arglist>
    </member>
    <member kind="function">
      <type>&amp;ACE_Service_Type::DELETE_THIS</type>
      <name>ACE_TEXT</name>
      <anchor>a4</anchor>
      <arglist>(&quot;UDP_Factory&quot;)</arglist>
    </member>
    <member kind="variable">
      <type></type>
      <name>ACE_SVC_OBJ_T</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>UDP.h</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>UDP_8h.html</filename>
    <class kind="class">TAO_AV_UDP_Acceptor</class>
    <class kind="class">TAO_AV_UDP_Connection_Setup</class>
    <class kind="class">TAO_AV_UDP_Connector</class>
    <class kind="class">TAO_AV_UDP_Factory</class>
    <class kind="class">TAO_AV_UDP_Flow_Factory</class>
    <class kind="class">TAO_AV_UDP_Flow_Handler</class>
    <class kind="class">TAO_AV_UDP_Object</class>
    <class kind="class">TAO_AV_UDP_Transport</class>
    <member kind="function">
      <type></type>
      <name>ACE_STATIC_SVC_DECLARE</name>
      <anchor>a0</anchor>
      <arglist>(TAO_AV_UDP_Flow_Factory) ACE_FACTORY_DECLARE(TAO_AV</arglist>
    </member>
  </compound>
  <compound kind="file">
    <name>UDP.i</name>
    <path>/tmp/ACE_wrappers_stage-5397/ACE_wrappers/TAO/orbsvcs/orbsvcs/AV/</path>
    <filename>UDP_8i.html</filename>
  </compound>
  <compound kind="class">
    <name>AV_Null_MediaCtrl</name>
    <filename>classAV__Null__MediaCtrl.html</filename>
    <member kind="function">
      <type></type>
      <name>AV_Null_MediaCtrl</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>MD5_CTX</name>
    <filename>structMD5__CTX.html</filename>
    <member kind="variable">
      <type>UINT4</type>
      <name>state</name>
      <anchor>m0</anchor>
      <arglist>[4]</arglist>
    </member>
    <member kind="variable">
      <type>UINT4</type>
      <name>count</name>
      <anchor>m1</anchor>
      <arglist>[2]</arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>buffer</name>
      <anchor>m2</anchor>
      <arglist>[64]</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MediaTimer</name>
    <filename>classMediaTimer.html</filename>
    <member kind="function">
      <type></type>
      <name>MediaTimer</name>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~MediaTimer</name>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACE_UINT32</type>
      <name>media_ts</name>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACE_UINT32</type>
      <name>ref_ts</name>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>ACE_UINT32</type>
      <name>offset</name>
      <anchor>a4</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>MediaTimer</name>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~MediaTimer</name>
      <anchor>a6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACE_UINT32</type>
      <name>media_ts</name>
      <anchor>a7</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACE_UINT32</type>
      <name>ref_ts</name>
      <anchor>a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>ACE_UINT32</type>
      <name>offset</name>
      <anchor>a9</anchor>
      <arglist>() const</arglist>
    </member>
    <member kind="function" static="yes">
      <type>MediaTimer *</type>
      <name>instance</name>
      <anchor>d0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" static="yes">
      <type>MediaTimer *</type>
      <name>instance</name>
      <anchor>d1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_UINT32</type>
      <name>offset_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected" static="yes">
      <type>MediaTimer *</type>
      <name>instance_</name>
      <anchor>r0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected" static="yes">
      <type>MediaTimer *</type>
      <name>instance_</name>
      <anchor>r1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>MMDevice_Map_Hash_Key</name>
    <filename>classMMDevice__Map__Hash__Key.html</filename>
    <member kind="function">
      <type></type>
      <name>MMDevice_Map_Hash_Key</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>MMDevice_Map_Hash_Key</name>
      <anchor>a1</anchor>
      <arglist>(AVStreams::MMDevice_ptr mmdevice)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>MMDevice_Map_Hash_Key</name>
      <anchor>a2</anchor>
      <arglist>(const MMDevice_Map_Hash_Key &amp;)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~MMDevice_Map_Hash_Key</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>operator==</name>
      <anchor>a4</anchor>
      <arglist>(const MMDevice_Map_Hash_Key &amp;hash_key) const</arglist>
    </member>
    <member kind="function">
      <type>u_long</type>
      <name>hash</name>
      <anchor>a5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const int</type>
      <name>hash_maximum_</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::MMDevice_ptr</type>
      <name>mmdevice_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend int</type>
      <name>operator&lt;</name>
      <anchor>l0</anchor>
      <arglist>(const MMDevice_Map_Hash_Key &amp;left, const MMDevice_Map_Hash_Key &amp;right)</arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>Null_MediaCtrl</name>
    <filename>interfaceNull__MediaCtrl.html</filename>
  </compound>
  <compound kind="struct">
    <name>RR_Block</name>
    <filename>structRR__Block.html</filename>
    <member kind="variable">
      <type>ACE_UINT32</type>
      <name>ssrc_</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>fraction_</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>lost_</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ACE_UINT32</type>
      <name>last_seq_</name>
      <anchor>m3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ACE_UINT32</type>
      <name>jitter_</name>
      <anchor>m4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ACE_UINT32</type>
      <name>lsr_</name>
      <anchor>m5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ACE_UINT32</type>
      <name>dlsr_</name>
      <anchor>m6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>RR_Block *</type>
      <name>next_</name>
      <anchor>m7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RTCP_BYE_Packet</name>
    <filename>classRTCP__BYE__Packet.html</filename>
    <base>RTCP_Packet</base>
    <member kind="function">
      <type></type>
      <name>RTCP_BYE_Packet</name>
      <anchor>a0</anchor>
      <arglist>(ACE_UINT32 *srcList, unsigned char length, const char *text=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RTCP_BYE_Packet</name>
      <anchor>a1</anchor>
      <arglist>(char *buffer, int *len)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~RTCP_BYE_Packet</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>packet_size</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>ssrc_list</name>
      <anchor>a4</anchor>
      <arglist>(ACE_UINT32 **ssrc_list, unsigned char &amp;length)</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>reason</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>dump</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>build_packet</name>
      <anchor>c0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT32 *</type>
      <name>ssrc_list_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>unsigned char</type>
      <name>ssrc_list_length_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>char</type>
      <name>reason_</name>
      <anchor>o2</anchor>
      <arglist>[256]</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>unsigned char</type>
      <name>reason_length_</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RTCP_Channel_In</name>
    <filename>classRTCP__Channel__In.html</filename>
    <member kind="function">
      <type></type>
      <name>RTCP_Channel_In</name>
      <anchor>a0</anchor>
      <arglist>(ACE_UINT32 ssrc, const ACE_Addr *addr)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~RTCP_Channel_In</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>recv_rtp_packet</name>
      <anchor>a2</anchor>
      <arglist>(ACE_Message_Block *mb, const ACE_Addr *peer_addr)</arglist>
    </member>
    <member kind="function">
      <type>RR_Block *</type>
      <name>getRRBlock</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>ACE_UINT32</type>
      <name>dlsr</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>ACE_UINT32</type>
      <name>lsr</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>updateStatistics</name>
      <anchor>a6</anchor>
      <arglist>(RTCP_SR_Packet *sr)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>updateStatistics</name>
      <anchor>a7</anchor>
      <arglist>(RTCP_RR_Packet *rr)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>sender</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>active</name>
      <anchor>a9</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>RTCP_Channel_In</name>
      <anchor>c0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type></type>
      <name>RTCP_Channel_In</name>
      <anchor>c1</anchor>
      <arglist>(const RTCP_Channel_In &amp;ch)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>updateStatistics</name>
      <anchor>c2</anchor>
      <arglist>(RTP_Packet *pkt)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>init_seq</name>
      <anchor>c3</anchor>
      <arglist>(ACE_UINT16 seq)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>int</type>
      <name>update_seq</name>
      <anchor>c4</anchor>
      <arglist>(ACE_UINT16 seq)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT32</type>
      <name>remote_ssrc_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_CString</type>
      <name>cname_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT16</type>
      <name>max_seq_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT32</type>
      <name>cycles_</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT32</type>
      <name>base_seq_</name>
      <anchor>o4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT32</type>
      <name>bad_seq_</name>
      <anchor>o5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT32</type>
      <name>probation_</name>
      <anchor>o6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT32</type>
      <name>received_</name>
      <anchor>o7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT32</type>
      <name>expected_prior_</name>
      <anchor>o8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT32</type>
      <name>received_prior_</name>
      <anchor>o9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT32</type>
      <name>transit_</name>
      <anchor>o10</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>double</type>
      <name>jitter_</name>
      <anchor>o11</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>char</type>
      <name>first_data_packet_</name>
      <anchor>o12</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT32</type>
      <name>init_time_stamp_</name>
      <anchor>o13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_Time_Value</type>
      <name>init_local_time_</name>
      <anchor>o14</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_Addr *</type>
      <name>peer_address_</name>
      <anchor>o15</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT32</type>
      <name>ntp_ts_msw_</name>
      <anchor>o16</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT32</type>
      <name>ntp_ts_lsw_</name>
      <anchor>o17</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT32</type>
      <name>rtp_ts_</name>
      <anchor>o18</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT32</type>
      <name>last_sr_time_</name>
      <anchor>o19</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>active_</name>
      <anchor>o20</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>no_data_counter_</name>
      <anchor>o21</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>char</type>
      <name>data_since_last_report_</name>
      <anchor>o22</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>int</type>
      <name>payload_type_</name>
      <anchor>o23</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RTCP_Channel_Out</name>
    <filename>classRTCP__Channel__Out.html</filename>
    <member kind="function">
      <type></type>
      <name>RTCP_Channel_Out</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~RTCP_Channel_Out</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>updateStatistics</name>
      <anchor>a2</anchor>
      <arglist>(RTP_Packet *pkt)</arglist>
    </member>
    <member kind="function">
      <type>ACE_UINT32</type>
      <name>timestamp</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>ACE_UINT32</type>
      <name>packets_sent</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>ACE_UINT32</type>
      <name>octets_sent</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>cname</name>
      <anchor>a6</anchor>
      <arglist>(const char *cname)</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>cname</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>char</type>
      <name>active</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_CString</type>
      <name>cname_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>char</type>
      <name>active_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>unsigned int</type>
      <name>seq_num_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>unsigned int</type>
      <name>timestamp_</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>unsigned int</type>
      <name>timestamp_offset_</name>
      <anchor>o4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>unsigned int</type>
      <name>packets_sent_</name>
      <anchor>o5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>unsigned int</type>
      <name>octets_sent_</name>
      <anchor>o6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>RTCP_Common_Header</name>
    <filename>structRTCP__Common__Header.html</filename>
    <member kind="variable">
      <type>unsigned int</type>
      <name>ver_</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>pad_</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>count_</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned int</type>
      <name>pt_</name>
      <anchor>m3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ACE_UINT16</type>
      <name>length_</name>
      <anchor>m4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RTCP_Packet</name>
    <filename>classRTCP__Packet.html</filename>
    <member kind="function">
      <type></type>
      <name>RTCP_Packet</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RTCP_Packet</name>
      <anchor>a1</anchor>
      <arglist>(char *buffer)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual</type>
      <name>~RTCP_Packet</name>
      <anchor>a2</anchor>
      <arglist>()=0</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>get_packet_data</name>
      <anchor>a3</anchor>
      <arglist>(char **buffer, ACE_UINT16 &amp;length)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual unsigned int</type>
      <name>packet_size</name>
      <anchor>a4</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>is_valid</name>
      <anchor>a5</anchor>
      <arglist>(char is_first)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="pure">
      <type>virtual void</type>
      <name>build_packet</name>
      <anchor>b0</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>RTCP_Common_Header</type>
      <name>chd_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>char *</type>
      <name>packet_data_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RTCP_RR_Packet</name>
    <filename>classRTCP__RR__Packet.html</filename>
    <base>RTCP_Packet</base>
    <member kind="function">
      <type></type>
      <name>RTCP_RR_Packet</name>
      <anchor>a0</anchor>
      <arglist>(char *buffer, int *len)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RTCP_RR_Packet</name>
      <anchor>a1</anchor>
      <arglist>(ACE_UINT32 ssrc, RR_Block *blocks)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~RTCP_RR_Packet</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>packet_size</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>ACE_INT32</type>
      <name>ssrc</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>dump</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>build_packet</name>
      <anchor>c0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT32</type>
      <name>ssrc_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>RR_Block *</type>
      <name>rr_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RTCP_SDES_Packet</name>
    <filename>classRTCP__SDES__Packet.html</filename>
    <base>RTCP_Packet</base>
    <member kind="function">
      <type></type>
      <name>RTCP_SDES_Packet</name>
      <anchor>a0</anchor>
      <arglist>(char *buffer, int *len)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RTCP_SDES_Packet</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~RTCP_SDES_Packet</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>add_item</name>
      <anchor>a3</anchor>
      <arglist>(ACE_UINT32 ssrc, unsigned char type, unsigned char length, const char *data)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>add_priv_item</name>
      <anchor>a4</anchor>
      <arglist>(ACE_UINT32 ssrc, unsigned char nameLength, const char *name, unsigned char dataLength, const char *data)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>packet_size</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>dump</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>ACE_UINT32</type>
      <name>ssrc</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>build_packet</name>
      <anchor>c0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>add_chunk</name>
      <anchor>c1</anchor>
      <arglist>(ACE_UINT32 ssrc)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>unsigned long</type>
      <name>num_chunks_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>sdesChunk_t *</type>
      <name>chunk_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RTCP_SR_Packet</name>
    <filename>classRTCP__SR__Packet.html</filename>
    <base>RTCP_Packet</base>
    <member kind="function">
      <type></type>
      <name>RTCP_SR_Packet</name>
      <anchor>a0</anchor>
      <arglist>(char *buffer, int *len)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RTCP_SR_Packet</name>
      <anchor>a1</anchor>
      <arglist>(ACE_UINT32 ssrcVal, ACE_UINT32 ntpMSByte, ACE_UINT32 ntpLSByte, ACE_UINT32 timestamp, ACE_UINT32 pktsSent, ACE_UINT32 octetsSent, RR_Block *rrBlocks)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~RTCP_SR_Packet</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>packet_size</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>ACE_UINT32</type>
      <name>ssrc</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>ACE_UINT32</type>
      <name>ntp_ts_msw</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>ACE_UINT32</type>
      <name>ntp_ts_lsw</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>dump</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="protected">
      <type>void</type>
      <name>build_packet</name>
      <anchor>c0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT32</type>
      <name>ssrc_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT32</type>
      <name>ntp_ts_msw_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT32</type>
      <name>ntp_ts_lsw_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT32</type>
      <name>rtp_ts_</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT32</type>
      <name>psent_</name>
      <anchor>o4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT32</type>
      <name>osent_</name>
      <anchor>o5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>RR_Block *</type>
      <name>rr_</name>
      <anchor>o6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>RTP_Packet</name>
    <filename>classRTP__Packet.html</filename>
    <member kind="function">
      <type></type>
      <name>RTP_Packet</name>
      <anchor>a0</anchor>
      <arglist>(char *buffer, int length)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>RTP_Packet</name>
      <anchor>a1</anchor>
      <arglist>(unsigned char padding, unsigned char marker, unsigned char payloadType, ACE_UINT32 sequenceNumber, ACE_UINT32 timeStamp, ACE_UINT32 syncSource, unsigned char contribSourcCount, ACE_UINT32 contribSourceList[], char *data, ACE_UINT16 dataSize)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~RTP_Packet</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>ACE_UINT16</type>
      <name>packet_size</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>ACE_UINT16</type>
      <name>payload_size</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>get_frame_info</name>
      <anchor>a5</anchor>
      <arglist>(TAO_AV_frame_info *frame_info)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>is_valid</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>ver</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>pad</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>ext</name>
      <anchor>a9</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>ext_bytes</name>
      <anchor>a10</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>cc</name>
      <anchor>a11</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>mrk</name>
      <anchor>a12</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>unsigned int</type>
      <name>pt</name>
      <anchor>a13</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>ACE_UINT16</type>
      <name>sn</name>
      <anchor>a14</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>ACE_UINT32</type>
      <name>ts</name>
      <anchor>a15</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>ACE_UINT32</type>
      <name>ssrc</name>
      <anchor>a16</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>get_csrc_list</name>
      <anchor>a17</anchor>
      <arglist>(ACE_UINT32 **csrc_list, ACE_UINT16 &amp;length)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>get_payload</name>
      <anchor>a18</anchor>
      <arglist>(char **payload, ACE_UINT16 &amp;size)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>get_packet_data</name>
      <anchor>a19</anchor>
      <arglist>(char **packet, ACE_UINT16 &amp;size)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>char</type>
      <name>packet_</name>
      <anchor>o0</anchor>
      <arglist>[RTP_MTU]</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT32</type>
      <name>host_byte_order_csrc_list_</name>
      <anchor>o1</anchor>
      <arglist>[15]</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>char</type>
      <name>host_byte_order_payload_</name>
      <anchor>o2</anchor>
      <arglist>[RTP_MTU]</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>unsigned int</type>
      <name>extension_bytes_</name>
      <anchor>o3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT16</type>
      <name>packet_size_</name>
      <anchor>o4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT16</type>
      <name>payload_size_</name>
      <anchor>o5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>sdesChunk_s</name>
    <filename>structsdesChunk__s.html</filename>
    <member kind="variable">
      <type>sdesChunk_t *</type>
      <name>next_</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ACE_UINT32</type>
      <name>ssrc_</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>sdesItem_t *</type>
      <name>item_</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>sdesItem_s</name>
    <filename>structsdesItem__s.html</filename>
    <member kind="variable">
      <type>sdesItem_t *</type>
      <name>next_</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>type_</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>sdesItem_s::@0</type>
      <name>info_</name>
      <anchor>m10</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>sdesItem_s::@0::@1</type>
      <name>standard_</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>length_</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>char *</type>
      <name>data_</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>sdesItem_s::@0::@2</type>
      <name>priv_</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>name_length_</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>data_length_</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>char *</type>
      <name>name_</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>char *</type>
      <name>data_</name>
      <anchor>m3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Acceptor</name>
    <filename>classTAO__AV__Acceptor.html</filename>
    <member kind="function">
      <type></type>
      <name>TAO_AV_Acceptor</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_Acceptor</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>open</name>
      <anchor>a2</anchor>
      <arglist>(TAO_Base_StreamEndPoint *endpoint, TAO_AV_Core *av_core, TAO_FlowSpec_Entry *entry, TAO_AV_Flow_Protocol_Factory *factory, TAO_AV_Core::Flow_Component flow_comp)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>open_default</name>
      <anchor>a3</anchor>
      <arglist>(TAO_Base_StreamEndPoint *endpoint, TAO_AV_Core *av_core, TAO_FlowSpec_Entry *entry, TAO_AV_Flow_Protocol_Factory *factory, TAO_AV_Core::Flow_Component flow_comp)=0</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>flowname</name>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>close</name>
      <anchor>a5</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_CString</type>
      <name>flowname_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Core *</type>
      <name>av_core_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_Addr *</type>
      <name>address_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Acceptor_Registry</name>
    <filename>classTAO__AV__Acceptor__Registry.html</filename>
    <member kind="function">
      <type></type>
      <name>TAO_AV_Acceptor_Registry</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_AV_Acceptor_Registry</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>open</name>
      <anchor>a2</anchor>
      <arglist>(TAO_Base_StreamEndPoint *endpoint, TAO_AV_Core *av_core, TAO_AV_FlowSpecSet &amp;flow_spec_set)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>close</name>
      <anchor>a3</anchor>
      <arglist>(TAO_AV_Acceptor *acceptor)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>close_all</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_AcceptorSetItor</type>
      <name>begin</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_AcceptorSetItor</type>
      <name>end</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>open_default</name>
      <anchor>b0</anchor>
      <arglist>(TAO_Base_StreamEndPoint *endpoint, TAO_AV_Core *av_core, TAO_FlowSpec_Entry *entry)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_AcceptorSet</type>
      <name>acceptors_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Base_Connector</name>
    <filename>classTAO__AV__Base__Connector.html</filename>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Callback</name>
    <filename>classTAO__AV__Callback.html</filename>
    <member kind="function">
      <type></type>
      <name>TAO_AV_Callback</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_Callback</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>open</name>
      <anchor>a2</anchor>
      <arglist>(TAO_AV_Protocol_Object *object, TAO_AV_Flow_Handler *handler)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_start</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_stop</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_timeout</name>
      <anchor>a5</anchor>
      <arglist>(void *arg)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>schedule_timer</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>receive_frame</name>
      <anchor>a7</anchor>
      <arglist>(ACE_Message_Block *frame, TAO_AV_frame_info *frame_info=0, const ACE_Addr &amp;address=ACE_Addr::sap_any)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>receive_control_frame</name>
      <anchor>a8</anchor>
      <arglist>(ACE_Message_Block *frame, const ACE_Addr &amp;address=ACE_Addr::sap_any)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_destroy</name>
      <anchor>a9</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>get_timeout</name>
      <anchor>a10</anchor>
      <arglist>(ACE_Time_Value *&amp;tv, void *&amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_Protocol_Object *</type>
      <name>protocol_object</name>
      <anchor>a11</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_AV_PolicyList</type>
      <name>get_policies</name>
      <anchor>a12</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Protocol_Object *</type>
      <name>protocol_object_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Flow_Handler *</type>
      <name>handler_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Child_Process</name>
    <filename>classTAO__AV__Child__Process.html</filename>
    <templarg>T_StreamEndpoint</templarg>
    <templarg>T_VDev</templarg>
    <templarg>T_MediaCtrl</templarg>
    <member kind="function">
      <type></type>
      <name>TAO_AV_Child_Process</name>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_Child_Process</name>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>init</name>
      <anchor>a2</anchor>
      <arglist>(int argc, char **argv, CORBA::ORB_ptr orb, PortableServer::POA_ptr poa)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>run</name>
      <anchor>a3</anchor>
      <arglist>(ACE_Time_Value *tv=0)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>activate_objects</name>
      <anchor>b0</anchor>
      <arglist>(int argc, char **argv ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>char *</type>
      <name>activate_with_poa</name>
      <anchor>b1</anchor>
      <arglist>(PortableServer::Servant servant ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>unbind_names</name>
      <anchor>b2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>bind_to_naming_service</name>
      <anchor>b3</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>register_vdev</name>
      <anchor>b4</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>register_stream_endpoint</name>
      <anchor>b5</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>release_semaphore</name>
      <anchor>b6</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual int</type>
      <name>make_vdev</name>
      <anchor>b7</anchor>
      <arglist>(T_VDev *&amp;vdev)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual int</type>
      <name>make_stream_endpoint</name>
      <anchor>b8</anchor>
      <arglist>(T_StreamEndpoint *&amp;stream_endpoint)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual int</type>
      <name>make_mediactrl</name>
      <anchor>b9</anchor>
      <arglist>(T_MediaCtrl *&amp;media_ctrl)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CosNaming::NamingContext_var</type>
      <name>naming_context_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CosNaming::Name</type>
      <name>vdev_name_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CosNaming::Name</type>
      <name>stream_endpoint_name_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>T_StreamEndpoint *</type>
      <name>stream_endpoint_</name>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>T_VDev *</type>
      <name>vdev_</name>
      <anchor>n4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::Object_var</type>
      <name>vdev_obj_</name>
      <anchor>n5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>T_MediaCtrl *</type>
      <name>media_ctrl_</name>
      <anchor>n6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::Object_var</type>
      <name>media_ctrl_obj_</name>
      <anchor>n7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>pid_t</type>
      <name>pid_</name>
      <anchor>n8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>char</type>
      <name>host_</name>
      <anchor>n9</anchor>
      <arglist>[MAXHOSTNAMELEN]</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::ORB_ptr</type>
      <name>orb_</name>
      <anchor>n10</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>PortableServer::POA_ptr</type>
      <name>poa_</name>
      <anchor>n11</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Child_Process_A</name>
    <filename>classTAO__AV__Child__Process__A.html</filename>
    <templarg>T_StreamEndpoint</templarg>
    <templarg>T_VDev</templarg>
    <templarg>T_MediaCtrl</templarg>
    <base>TAO_AV_Child_Process</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_Child_Process_A</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_Child_Process_A</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Child_Process_B</name>
    <filename>classTAO__AV__Child__Process__B.html</filename>
    <templarg>T_StreamEndpoint</templarg>
    <templarg>T_VDev</templarg>
    <templarg>T_MediaCtrl</templarg>
    <base>TAO_AV_Child_Process</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_Child_Process_B</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_Child_Process_B</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Connector</name>
    <filename>classTAO__AV__Connector.html</filename>
    <member kind="function">
      <type></type>
      <name>TAO_AV_Connector</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_Connector</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>flowname</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>open</name>
      <anchor>a3</anchor>
      <arglist>(TAO_Base_StreamEndPoint *endpoint, TAO_AV_Core *av_core, TAO_AV_Flow_Protocol_Factory *factory)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>connect</name>
      <anchor>a4</anchor>
      <arglist>(TAO_FlowSpec_Entry *entry, TAO_AV_Transport *&amp;transport, TAO_AV_Core::Flow_Component flow_component)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>close</name>
      <anchor>a5</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_CString</type>
      <name>flowname_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Connector_Registry</name>
    <filename>classTAO__AV__Connector__Registry.html</filename>
    <member kind="function">
      <type></type>
      <name>TAO_AV_Connector_Registry</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_AV_Connector_Registry</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>open</name>
      <anchor>a2</anchor>
      <arglist>(TAO_Base_StreamEndPoint *endpoint, TAO_AV_Core *av_core, TAO_AV_FlowSpecSet &amp;flow_spec_set)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>close</name>
      <anchor>a3</anchor>
      <arglist>(TAO_AV_Connector *connector)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>close_all</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_ConnectorSetItor</type>
      <name>begin</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_ConnectorSetItor</type>
      <name>end</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_ConnectorSet</type>
      <name>connectors_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Core</name>
    <filename>classTAO__AV__Core.html</filename>
    <member kind="enumeration">
      <name>EndPoint</name>
      <anchor>s21</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_ENDPOINT_A</name>
      <anchor>s21s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_ENDPOINT_B</name>
      <anchor>s21s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>Protocol</name>
      <anchor>s22</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_NOPROTOCOL</name>
      <anchor>s22s2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_TCP</name>
      <anchor>s22s3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_UDP</name>
      <anchor>s22s4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_AAL5</name>
      <anchor>s22s5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_AAL3_4</name>
      <anchor>s22s6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_AAL1</name>
      <anchor>s22s7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_RTP_UDP</name>
      <anchor>s22s8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_RTP_AAL5</name>
      <anchor>s22s9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_IPX</name>
      <anchor>s22s10</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_SFP_UDP</name>
      <anchor>s22s11</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_UDP_MCAST</name>
      <anchor>s22s12</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_RTP_UDP_MCAST</name>
      <anchor>s22s13</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_SFP_UDP_MCAST</name>
      <anchor>s22s14</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_QOS_UDP</name>
      <anchor>s22s15</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_USERDEFINED_UDP</name>
      <anchor>s22s16</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_USERDEFINED_UDP_MCAST</name>
      <anchor>s22s17</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>Flow_Component</name>
      <anchor>s23</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_DATA</name>
      <anchor>s23s18</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_CONTROL</name>
      <anchor>s23s19</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_BOTH</name>
      <anchor>s23s20</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_AV_Core</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_AV_Core</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>init</name>
      <anchor>a2</anchor>
      <arglist>(CORBA::ORB_ptr orb, PortableServer::POA_ptr poa ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>run</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>stop_run</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>init_forward_flows</name>
      <anchor>a5</anchor>
      <arglist>(TAO_Base_StreamEndPoint *endpoint, TAO_AV_FlowSpecSet &amp;flow_spec_set, EndPoint direction, AVStreams::flowSpec &amp;flow_spec)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>init_reverse_flows</name>
      <anchor>a6</anchor>
      <arglist>(TAO_Base_StreamEndPoint *endpoint, TAO_AV_FlowSpecSet &amp;forward_flow_spec_set, TAO_AV_FlowSpecSet &amp;reverse_flow_spec_set, EndPoint direction)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>init_transport_factories</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>init_flow_protocol_factories</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>load_default_transport_factories</name>
      <anchor>a9</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>load_default_flow_protocol_factories</name>
      <anchor>a10</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_Acceptor *</type>
      <name>get_acceptor</name>
      <anchor>a11</anchor>
      <arglist>(const char *flowname)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_Connector *</type>
      <name>get_connector</name>
      <anchor>a12</anchor>
      <arglist>(const char *flowname)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>remove_acceptor</name>
      <anchor>a13</anchor>
      <arglist>(const char *flowname)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>remove_connector</name>
      <anchor>a14</anchor>
      <arglist>(const char *flowname)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_Connector_Registry *</type>
      <name>connector_registry</name>
      <anchor>a15</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_FlowSpec_Entry *</type>
      <name>get_flow_spec_entry</name>
      <anchor>a16</anchor>
      <arglist>(TAO_AV_FlowSpecSet &amp;flow_spec_set, const char *flowname)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_Acceptor_Registry *</type>
      <name>acceptor_registry</name>
      <anchor>a17</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_Flow_Protocol_Factory *</type>
      <name>get_flow_protocol_factory</name>
      <anchor>a18</anchor>
      <arglist>(const char *flow_protocol)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_Transport_Factory *</type>
      <name>get_transport_factory</name>
      <anchor>a19</anchor>
      <arglist>(const char *transport_protocol)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_Flow_ProtocolFactorySet *</type>
      <name>flow_protocol_factories</name>
      <anchor>a20</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_TransportFactorySet *</type>
      <name>transport_factories</name>
      <anchor>a21</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>reactor</name>
      <anchor>a22</anchor>
      <arglist>(ACE_Reactor *r)</arglist>
    </member>
    <member kind="function">
      <type>ACE_Reactor *</type>
      <name>reactor</name>
      <anchor>a23</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::ORB_ptr</type>
      <name>orb</name>
      <anchor>a24</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>orb</name>
      <anchor>a25</anchor>
      <arglist>(CORBA::ORB_ptr orb_)</arglist>
    </member>
    <member kind="function">
      <type>PortableServer::POA_ptr</type>
      <name>poa</name>
      <anchor>a26</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>poa</name>
      <anchor>a27</anchor>
      <arglist>(PortableServer::POA_ptr poa_)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>int</type>
      <name>deactivate_servant</name>
      <anchor>d0</anchor>
      <arglist>(PortableServer::Servant servant)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>char *</type>
      <name>get_flowname</name>
      <anchor>d1</anchor>
      <arglist>(const char *flow_spec_entry_str)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>ACE_CString</type>
      <name>get_control_flowname</name>
      <anchor>d2</anchor>
      <arglist>(const char *flowname)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Connector_Registry *</type>
      <name>connector_registry_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Acceptor_Registry *</type>
      <name>acceptor_registry_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_TransportFactorySet</type>
      <name>transport_factories_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Flow_ProtocolFactorySet</type>
      <name>flow_protocol_factories_</name>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_Reactor *</type>
      <name>reactor_</name>
      <anchor>n4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::ORB_var</type>
      <name>orb_</name>
      <anchor>n5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>PortableServer::POA_var</type>
      <name>poa_</name>
      <anchor>n6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::Boolean</type>
      <name>stop_run_</name>
      <anchor>n7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Default_Resource_Factory</name>
    <filename>classTAO__AV__Default__Resource__Factory.html</filename>
    <base>TAO_AV_Resource_Factory</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_Default_Resource_Factory</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_Default_Resource_Factory</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>init</name>
      <anchor>a2</anchor>
      <arglist>(int argc, char *argv[])</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Endpoint_Process_Strategy</name>
    <filename>classTAO__AV__Endpoint__Process__Strategy.html</filename>
    <base>TAO_AV_Endpoint_Strategy</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_Endpoint_Process_Strategy</name>
      <anchor>a0</anchor>
      <arglist>(ACE_Process_Options *process_options)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_Endpoint_Process_Strategy</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>activate</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual int</type>
      <name>bind_to_naming_service</name>
      <anchor>b0</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="pure">
      <type>virtual int</type>
      <name>get_stream_endpoint</name>
      <anchor>b1</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL)=0</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual int</type>
      <name>get_vdev</name>
      <anchor>b2</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CosNaming::NamingContext_var</type>
      <name>naming_context_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_Process_Options *</type>
      <name>process_options_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>char</type>
      <name>host_</name>
      <anchor>n2</anchor>
      <arglist>[MAXHOSTNAMELEN]</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>pid_t</type>
      <name>pid_</name>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Endpoint_Process_Strategy_A</name>
    <filename>classTAO__AV__Endpoint__Process__Strategy__A.html</filename>
    <base>TAO_AV_Endpoint_Process_Strategy</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_Endpoint_Process_Strategy_A</name>
      <anchor>a0</anchor>
      <arglist>(ACE_Process_Options *process_options)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_Endpoint_Process_Strategy_A</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual int</type>
      <name>create_A</name>
      <anchor>b0</anchor>
      <arglist>(AVStreams::StreamEndPoint_A_ptr &amp;stream_endpoint, AVStreams::VDev_ptr &amp;vdev ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual int</type>
      <name>get_stream_endpoint</name>
      <anchor>b1</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Endpoint_Process_Strategy_B</name>
    <filename>classTAO__AV__Endpoint__Process__Strategy__B.html</filename>
    <base>TAO_AV_Endpoint_Process_Strategy</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_Endpoint_Process_Strategy_B</name>
      <anchor>a0</anchor>
      <arglist>(ACE_Process_Options *process_options)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_Endpoint_Process_Strategy_B</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual int</type>
      <name>create_B</name>
      <anchor>b0</anchor>
      <arglist>(AVStreams::StreamEndPoint_B_ptr &amp;stream_endpoint, AVStreams::VDev_ptr &amp;vdev ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual int</type>
      <name>get_stream_endpoint</name>
      <anchor>b1</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Endpoint_Reactive_Strategy</name>
    <filename>classTAO__AV__Endpoint__Reactive__Strategy.html</filename>
    <templarg>T_StreamEndpoint</templarg>
    <templarg>T_VDev</templarg>
    <templarg>T_MediaCtrl</templarg>
    <base>TAO_AV_Endpoint_Strategy</base>
    <member kind="function" protection="public">
      <type></type>
      <name>TAO_AV_Endpoint_Reactive_Strategy</name>
      <anchor>b0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_Endpoint_Reactive_Strategy</name>
      <anchor>b1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual int</type>
      <name>activate</name>
      <anchor>b2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="pure">
      <type>virtual int</type>
      <name>activate_stream_endpoint</name>
      <anchor>b3</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL)=0</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual int</type>
      <name>activate_vdev</name>
      <anchor>b4</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual int</type>
      <name>activate_mediactrl</name>
      <anchor>b5</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual int</type>
      <name>make_vdev</name>
      <anchor>b6</anchor>
      <arglist>(T_VDev *&amp;vdev)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual int</type>
      <name>make_stream_endpoint</name>
      <anchor>b7</anchor>
      <arglist>(T_StreamEndpoint *&amp;stream_endpoint)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual int</type>
      <name>make_mediactrl</name>
      <anchor>b8</anchor>
      <arglist>(T_MediaCtrl *&amp;media_ctrl)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>char *</type>
      <name>activate_with_poa</name>
      <anchor>b9</anchor>
      <arglist>(PortableServer::Servant servant ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::ORB_var</type>
      <name>orb_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>PortableServer::POA_var</type>
      <name>poa_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::Object_var</type>
      <name>media_ctrl_obj_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>T_StreamEndpoint *</type>
      <name>stream_endpoint_a_servant_</name>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>T_StreamEndpoint *</type>
      <name>stream_endpoint_b_servant_</name>
      <anchor>n4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>T_VDev *</type>
      <name>vdev_servant_</name>
      <anchor>n5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>T_MediaCtrl *</type>
      <name>media_ctrl_servant_</name>
      <anchor>n6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Endpoint_Reactive_Strategy_A</name>
    <filename>classTAO__AV__Endpoint__Reactive__Strategy__A.html</filename>
    <templarg>T_StreamEndpoint</templarg>
    <templarg>T_VDev</templarg>
    <templarg>T_MediaCtrl</templarg>
    <base>TAO_AV_Endpoint_Reactive_Strategy</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_Endpoint_Reactive_Strategy_A</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>init</name>
      <anchor>a1</anchor>
      <arglist>(CORBA::ORB_ptr orb, PortableServer::POA_ptr poa)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_Endpoint_Reactive_Strategy_A</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>activate_stream_endpoint</name>
      <anchor>a3</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>create_A</name>
      <anchor>a4</anchor>
      <arglist>(AVStreams::StreamEndPoint_A_ptr &amp;stream_endpoint, AVStreams::VDev_ptr &amp;vdev ACE_ENV_ARG_DECL)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Endpoint_Reactive_Strategy_B</name>
    <filename>classTAO__AV__Endpoint__Reactive__Strategy__B.html</filename>
    <templarg>T_StreamEndpoint</templarg>
    <templarg>T_Vdev</templarg>
    <templarg>T_MediaCtrl</templarg>
    <base>TAO_AV_Endpoint_Reactive_Strategy&lt; T_StreamEndpoint, T_Vdev, T_MediaCtrl &gt;</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_Endpoint_Reactive_Strategy_B</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_Endpoint_Reactive_Strategy_B</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>init</name>
      <anchor>a2</anchor>
      <arglist>(CORBA::ORB_ptr orb, PortableServer::POA_ptr poa)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>activate_stream_endpoint</name>
      <anchor>a3</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>create_B</name>
      <anchor>a4</anchor>
      <arglist>(AVStreams::StreamEndPoint_B_ptr &amp;stream_endpoint, AVStreams::VDev_ptr &amp;vdev ACE_ENV_ARG_DECL)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Endpoint_Strategy</name>
    <filename>classTAO__AV__Endpoint__Strategy.html</filename>
    <member kind="function">
      <type></type>
      <name>TAO_AV_Endpoint_Strategy</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_Endpoint_Strategy</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>create_A</name>
      <anchor>a2</anchor>
      <arglist>(AVStreams::StreamEndPoint_A_ptr &amp;stream_endpoint, AVStreams::VDev_ptr &amp;vdev ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>create_B</name>
      <anchor>a3</anchor>
      <arglist>(AVStreams::StreamEndPoint_B_ptr &amp;stream_endpoint, AVStreams::VDev_ptr &amp;vdev ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::StreamEndPoint_A_var</type>
      <name>stream_endpoint_a_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::StreamEndPoint_B_var</type>
      <name>stream_endpoint_b_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::VDev_var</type>
      <name>vdev_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Flow_Handler</name>
    <filename>classTAO__AV__Flow__Handler.html</filename>
    <member kind="function">
      <type></type>
      <name>TAO_AV_Flow_Handler</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_Flow_Handler</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>start</name>
      <anchor>a2</anchor>
      <arglist>(TAO_FlowSpec_Entry::Role role)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>stop</name>
      <anchor>a3</anchor>
      <arglist>(TAO_FlowSpec_Entry::Role role)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>schedule_timer</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>cancel_timer</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_Transport *</type>
      <name>transport</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_Protocol_Object *</type>
      <name>protocol_object</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>protocol_object</name>
      <anchor>a8</anchor>
      <arglist>(TAO_AV_Protocol_Object *protocol_object)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>callback</name>
      <anchor>a9</anchor>
      <arglist>(TAO_AV_Callback *callback)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_timeout</name>
      <anchor>a10</anchor>
      <arglist>(const ACE_Time_Value &amp;tv, const void *arg=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>set_remote_address</name>
      <anchor>a11</anchor>
      <arglist>(ACE_Addr *address)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual ACE_Event_Handler *</type>
      <name>event_handler</name>
      <anchor>a12</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>change_qos</name>
      <anchor>a13</anchor>
      <arglist>(AVStreams::QoS)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Transport *</type>
      <name>transport_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Callback *</type>
      <name>callback_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Protocol_Object *</type>
      <name>protocol_object_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>long</type>
      <name>timer_id_</name>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_Reactor *</type>
      <name>reactor_</name>
      <anchor>n4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>void *</type>
      <name>timeout_arg_</name>
      <anchor>n5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Flow_Protocol_Factory</name>
    <filename>classTAO__AV__Flow__Protocol__Factory.html</filename>
    <base>ACE_Service_Object</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_Flow_Protocol_Factory</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_Flow_Protocol_Factory</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>init</name>
      <anchor>a2</anchor>
      <arglist>(int argc, char *argv[])</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>match_protocol</name>
      <anchor>a3</anchor>
      <arglist>(const char *flow_string)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_AV_Protocol_Object *</type>
      <name>make_protocol_object</name>
      <anchor>a4</anchor>
      <arglist>(TAO_FlowSpec_Entry *entry, TAO_Base_StreamEndPoint *endpoint, TAO_AV_Flow_Handler *handler, TAO_AV_Transport *transport)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>control_flow_factory</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>ref_count</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Flow_Protocol_Item</name>
    <filename>classTAO__AV__Flow__Protocol__Item.html</filename>
    <member kind="function">
      <type></type>
      <name>TAO_AV_Flow_Protocol_Item</name>
      <anchor>a0</anchor>
      <arglist>(const ACE_CString &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>const ACE_CString &amp;</type>
      <name>name</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_Flow_Protocol_Factory *</type>
      <name>factory</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>factory</name>
      <anchor>a3</anchor>
      <arglist>(TAO_AV_Flow_Protocol_Factory *factory)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_CString</type>
      <name>name_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_AV_Flow_Protocol_Factory *</type>
      <name>factory_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>TAO_AV_frame_info</name>
    <filename>structTAO__AV__frame__info.html</filename>
    <member kind="variable">
      <type>CORBA::Boolean</type>
      <name>boundary_marker</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>CORBA::Octet</type>
      <name>format</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>CORBA::ULong</type>
      <name>timestamp</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>CORBA::ULong</type>
      <name>ssrc</name>
      <anchor>m3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>CORBA::ULong</type>
      <name>sequence_num</name>
      <anchor>m4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Payload_Type_Policy</name>
    <filename>classTAO__AV__Payload__Type__Policy.html</filename>
    <base>TAO_AV_Policy</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_Payload_Type_Policy</name>
      <anchor>a0</anchor>
      <arglist>(int payload_type=-1)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>value</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>value</name>
      <anchor>a2</anchor>
      <arglist>(int pt)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>int</type>
      <name>payload_type_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Policy</name>
    <filename>classTAO__AV__Policy.html</filename>
    <member kind="function">
      <type></type>
      <name>TAO_AV_Policy</name>
      <anchor>a0</anchor>
      <arglist>(CORBA::ULong type)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::ULong</type>
      <name>type</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::ULong</type>
      <name>type_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Protocol_Object</name>
    <filename>classTAO__AV__Protocol__Object.html</filename>
    <member kind="function">
      <type></type>
      <name>TAO_AV_Protocol_Object</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_AV_Protocol_Object</name>
      <anchor>a1</anchor>
      <arglist>(TAO_AV_Callback *callback, TAO_AV_Transport *transport)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_Protocol_Object</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>open</name>
      <anchor>a3</anchor>
      <arglist>(TAO_AV_Callback *callback, TAO_AV_Transport *transport)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>handle_input</name>
      <anchor>a4</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_control_input</name>
      <anchor>a5</anchor>
      <arglist>(ACE_Message_Block *control_frame, const ACE_Addr &amp;peer_address)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>set_policies</name>
      <anchor>a6</anchor>
      <arglist>(const TAO_AV_PolicyList &amp;policy_list)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_AV_PolicyList</type>
      <name>get_policies</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>start</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>stop</name>
      <anchor>a9</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>send_frame</name>
      <anchor>a10</anchor>
      <arglist>(ACE_Message_Block *frame, TAO_AV_frame_info *frame_info=0)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>send_frame</name>
      <anchor>a11</anchor>
      <arglist>(const iovec *iov, int iovcnt, TAO_AV_frame_info *frame_info=0)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>send_frame</name>
      <anchor>a12</anchor>
      <arglist>(const char *buf, size_t len)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>control_object</name>
      <anchor>a13</anchor>
      <arglist>(TAO_AV_Protocol_Object *object)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>destroy</name>
      <anchor>a14</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_Transport *</type>
      <name>transport</name>
      <anchor>a15</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Transport *</type>
      <name>transport_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_PolicyList</type>
      <name>policy_list_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Callback *</type>
      <name>callback_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_QoS</name>
    <filename>classTAO__AV__QoS.html</filename>
    <member kind="function">
      <type></type>
      <name>TAO_AV_QoS</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_AV_QoS</name>
      <anchor>a1</anchor>
      <arglist>(AVStreams::streamQoS &amp;stream_qos)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>set</name>
      <anchor>a2</anchor>
      <arglist>(AVStreams::streamQoS &amp;stream_qos)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>get_flow_qos</name>
      <anchor>a3</anchor>
      <arglist>(const char *flowname, AVStreams::QoS &amp;flow_qos)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>convert</name>
      <anchor>a4</anchor>
      <arglist>(AVStreams::streamQoS &amp;network_qos)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::streamQoS</type>
      <name>stream_qos_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_Hash_Map_Manager&lt; ACE_CString, AVStreams::QoS, ACE_Null_Mutex &gt;</type>
      <name>qos_map_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Resource_Factory</name>
    <filename>classTAO__AV__Resource__Factory.html</filename>
    <base>ACE_Service_Object</base>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>init</name>
      <anchor>a0</anchor>
      <arglist>(int argc, char *argv[])=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_RTCP</name>
    <filename>classTAO__AV__RTCP.html</filename>
    <member kind="function" static="yes">
      <type>void</type>
      <name>send_report</name>
      <anchor>d0</anchor>
      <arglist>(ACE_Message_Block *mb)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>ACE_UINT32</type>
      <name>alloc_srcid</name>
      <anchor>d1</anchor>
      <arglist>(ACE_UINT32 addr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>double</type>
      <name>rtcp_interval</name>
      <anchor>d2</anchor>
      <arglist>(int members, int senders, double rtcp_bw, int we_sent, int packet_size, int *avg_rtcp_size, int initial)</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>TAO_AV_RTCP::md5_string</name>
    <filename>structTAO__AV__RTCP_1_1md5__string.html</filename>
    <member kind="variable">
      <type>int</type>
      <name>type</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ACE_Time_Value</type>
      <name>tv</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>pid_t</type>
      <name>pid</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>pid_t</type>
      <name>pgid</name>
      <anchor>m3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>pid_t</type>
      <name>ppid</name>
      <anchor>m4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>uid_t</type>
      <name>uid</name>
      <anchor>m5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>gid_t</type>
      <name>gid</name>
      <anchor>m6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>TAO_AV_RTCP::ntp64</name>
    <filename>structTAO__AV__RTCP_1_1ntp64.html</filename>
    <member kind="variable">
      <type>ACE_UINT32</type>
      <name>upper</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ACE_UINT32</type>
      <name>lower</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>TAO_AV_RTCP::rtcphdr</name>
    <filename>structTAO__AV__RTCP_1_1rtcphdr.html</filename>
    <member kind="variable">
      <type>ACE_UINT16</type>
      <name>rh_flags</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ACE_UINT16</type>
      <name>rh_len</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ACE_UINT32</type>
      <name>rh_ssrc</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_RTCP_Callback</name>
    <filename>classTAO__AV__RTCP__Callback.html</filename>
    <base>TAO_AV_Callback</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_RTCP_Callback</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_RTCP_Callback</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_start</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_stop</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_timeout</name>
      <anchor>a4</anchor>
      <arglist>(void *arg)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>receive_frame</name>
      <anchor>a5</anchor>
      <arglist>(ACE_Message_Block *frame, TAO_AV_frame_info *frame_info=0, const ACE_Addr &amp;peer_address=ACE_Addr::sap_any)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>send_frame</name>
      <anchor>a6</anchor>
      <arglist>(ACE_Message_Block *frame)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>receive_control_frame</name>
      <anchor>a7</anchor>
      <arglist>(ACE_Message_Block *frame, const ACE_Addr &amp;peer_address=ACE_Addr::sap_any)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_destroy</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>get_timeout</name>
      <anchor>a9</anchor>
      <arglist>(ACE_Time_Value *&amp;tv, void *&amp;arg)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>send_report</name>
      <anchor>a10</anchor>
      <arglist>(int bye)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>schedule</name>
      <anchor>a11</anchor>
      <arglist>(int ms)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_RTP_State *</type>
      <name>state</name>
      <anchor>a12</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>ts_offset</name>
      <anchor>a13</anchor>
      <arglist>(ACE_UINT32 offset)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_Hash_Map_Manager&lt; ACE_UINT32, RTCP_Channel_In *, ACE_Null_Mutex &gt;</type>
      <name>inputs_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>RTCP_Channel_Out</type>
      <name>output_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>int</type>
      <name>timeout_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>int</type>
      <name>timestamp_offset_</name>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>int</type>
      <name>sdes_count_</name>
      <anchor>n4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>int</type>
      <name>is_initial_timeout_</name>
      <anchor>n5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>int</type>
      <name>avg_rtcp_size_</name>
      <anchor>n6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>int</type>
      <name>packet_size_</name>
      <anchor>n7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_RTCP_Flow_Factory</name>
    <filename>classTAO__AV__RTCP__Flow__Factory.html</filename>
    <base>TAO_AV_Flow_Protocol_Factory</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_RTCP_Flow_Factory</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_RTCP_Flow_Factory</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>init</name>
      <anchor>a2</anchor>
      <arglist>(int argc, char *argv[])</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>match_protocol</name>
      <anchor>a3</anchor>
      <arglist>(const char *flow_string)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_AV_Protocol_Object *</type>
      <name>make_protocol_object</name>
      <anchor>a4</anchor>
      <arglist>(TAO_FlowSpec_Entry *entry, TAO_Base_StreamEndPoint *endpoint, TAO_AV_Flow_Handler *handler, TAO_AV_Transport *transport)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_RTCP_Object</name>
    <filename>classTAO__AV__RTCP__Object.html</filename>
    <base>TAO_AV_Protocol_Object</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_RTCP_Object</name>
      <anchor>a0</anchor>
      <arglist>(TAO_AV_Callback *client_cb, TAO_AV_RTCP_Callback *&amp;rtcp_cb, TAO_AV_Transport *transport=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_RTCP_Object</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_input</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_control_input</name>
      <anchor>a3</anchor>
      <arglist>(ACE_Message_Block *frame, const ACE_Addr &amp;peer_address)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_control_output</name>
      <anchor>a4</anchor>
      <arglist>(ACE_Message_Block *frame)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>set_policies</name>
      <anchor>a5</anchor>
      <arglist>(const TAO_AV_PolicyList &amp;policy_list)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>start</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>stop</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>send_frame</name>
      <anchor>a8</anchor>
      <arglist>(ACE_Message_Block *frame, TAO_AV_frame_info *frame_info=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>send_frame</name>
      <anchor>a9</anchor>
      <arglist>(const iovec *iov, int iovcnt, TAO_AV_frame_info *frame_info=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>send_frame</name>
      <anchor>a10</anchor>
      <arglist>(const char *buf, size_t len)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>destroy</name>
      <anchor>a11</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>ssrc</name>
      <anchor>a12</anchor>
      <arglist>(ACE_UINT32 ssrc)</arglist>
    </member>
    <member kind="function">
      <type>ACE_UINT32</type>
      <name>ssrc</name>
      <anchor>a13</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>ts_offset</name>
      <anchor>a14</anchor>
      <arglist>(ACE_UINT32 ts_offset)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_AV_Callback *</type>
      <name>client_cb_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_AV_RTCP_Callback</type>
      <name>rtcp_cb_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_UINT32</type>
      <name>ssrc_</name>
      <anchor>o2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>TAO_AV_RTCP_Sdes</name>
    <filename>structTAO__AV__RTCP__Sdes.html</filename>
    <member kind="variable">
      <type>CORBA::String_var</type>
      <name>name_</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>CORBA::String_var</type>
      <name>value_</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_RTCP_Sdes_Policy</name>
    <filename>classTAO__AV__RTCP__Sdes__Policy.html</filename>
    <base>TAO_AV_Policy</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_RTCP_Sdes_Policy</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_RTCP_Sdes &amp;</type>
      <name>value</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>value</name>
      <anchor>a2</anchor>
      <arglist>(const TAO_AV_RTCP_Sdes &amp;sdes_val)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_RTCP_Sdes</type>
      <name>sdes_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_RTP</name>
    <filename>classTAO__AV__RTP.html</filename>
  </compound>
  <compound kind="struct">
    <name>TAO_AV_RTP::bvchdr</name>
    <filename>structTAO__AV__RTP_1_1bvchdr.html</filename>
    <member kind="variable">
      <type>unsigned char</type>
      <name>version</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>pad</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>width</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>height</name>
      <anchor>m3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ACE_UINT32</type>
      <name>quant</name>
      <anchor>m4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>sbit</name>
      <anchor>m5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>ebit</name>
      <anchor>m6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ACE_UINT16</type>
      <name>blkno</name>
      <anchor>m7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>TAO_AV_RTP::cellbhdr</name>
    <filename>structTAO__AV__RTP_1_1cellbhdr.html</filename>
    <member kind="variable">
      <type>ACE_UINT16</type>
      <name>x</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ACE_UINT16</type>
      <name>y</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ACE_UINT16</type>
      <name>width</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ACE_UINT16</type>
      <name>height</name>
      <anchor>m3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>TAO_AV_RTP::nvhdr</name>
    <filename>structTAO__AV__RTP_1_1nvhdr.html</filename>
    <member kind="variable">
      <type>ACE_UINT16</type>
      <name>width</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ACE_UINT16</type>
      <name>height</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>TAO_AV_RTP::jpeghdr</name>
    <filename>structTAO__AV__RTP_1_1jpeghdr.html</filename>
    <member kind="variable">
      <type>ACE_UINT32</type>
      <name>off</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>type</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>q</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>width</name>
      <anchor>m3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned char</type>
      <name>height</name>
      <anchor>m4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>TAO_AV_RTP::rtphdr</name>
    <filename>structTAO__AV__RTP_1_1rtphdr.html</filename>
    <member kind="variable">
      <type>ACE_UINT16</type>
      <name>rh_flags</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ACE_UINT16</type>
      <name>rh_seqno</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ACE_UINT32</type>
      <name>rh_ts</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ACE_UINT32</type>
      <name>rh_ssrc</name>
      <anchor>m3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_RTP_Flow_Factory</name>
    <filename>classTAO__AV__RTP__Flow__Factory.html</filename>
    <base>TAO_AV_Flow_Protocol_Factory</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_RTP_Flow_Factory</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_RTP_Flow_Factory</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>init</name>
      <anchor>a2</anchor>
      <arglist>(int argc, char *argv[])</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>match_protocol</name>
      <anchor>a3</anchor>
      <arglist>(const char *flow_string)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_AV_Protocol_Object *</type>
      <name>make_protocol_object</name>
      <anchor>a4</anchor>
      <arglist>(TAO_FlowSpec_Entry *entry, TAO_Base_StreamEndPoint *endpoint, TAO_AV_Flow_Handler *handler, TAO_AV_Transport *transport)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>control_flow_factory</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_RTP_Object</name>
    <filename>classTAO__AV__RTP__Object.html</filename>
    <base>TAO_AV_Protocol_Object</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_RTP_Object</name>
      <anchor>a0</anchor>
      <arglist>(TAO_AV_Callback *callback, TAO_AV_Transport *transport)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_RTP_Object</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>start</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>stop</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_input</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>send_frame</name>
      <anchor>a5</anchor>
      <arglist>(ACE_Message_Block *frame, TAO_AV_frame_info *frame_info=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>send_frame</name>
      <anchor>a6</anchor>
      <arglist>(const iovec *iov, int iovcnt, TAO_AV_frame_info *frame_info=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>send_frame</name>
      <anchor>a7</anchor>
      <arglist>(const char *buf, size_t len)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>destroy</name>
      <anchor>a8</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>set_policies</name>
      <anchor>a9</anchor>
      <arglist>(const TAO_AV_PolicyList &amp;policy_list)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>control_object</name>
      <anchor>a10</anchor>
      <arglist>(TAO_AV_Protocol_Object *object)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_UINT16</type>
      <name>sequence_num_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_UINT32</type>
      <name>timestamp_offset_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>int</type>
      <name>format_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_UINT32</type>
      <name>ssrc_</name>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Protocol_Object *</type>
      <name>control_object_</name>
      <anchor>n4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_Message_Block</type>
      <name>frame_</name>
      <anchor>n5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>int</type>
      <name>connection_gone_</name>
      <anchor>n6</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_SFP_Credit_Policy</name>
    <filename>classTAO__AV__SFP__Credit__Policy.html</filename>
    <base>TAO_AV_Policy</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_SFP_Credit_Policy</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>value</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>value</name>
      <anchor>a2</anchor>
      <arglist>(int val)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>int</type>
      <name>value_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_SFP_Factory</name>
    <filename>classTAO__AV__SFP__Factory.html</filename>
    <base>TAO_AV_Flow_Protocol_Factory</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_SFP_Factory</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_SFP_Factory</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>init</name>
      <anchor>a2</anchor>
      <arglist>(int argc, char *argv[])</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>match_protocol</name>
      <anchor>a3</anchor>
      <arglist>(const char *flow_string)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_AV_Protocol_Object *</type>
      <name>make_protocol_object</name>
      <anchor>a4</anchor>
      <arglist>(TAO_FlowSpec_Entry *entry, TAO_Base_StreamEndPoint *endpoint, TAO_AV_Flow_Handler *handler, TAO_AV_Transport *transport)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_SSRC_Policy</name>
    <filename>classTAO__AV__SSRC__Policy.html</filename>
    <base>TAO_AV_Policy</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_SSRC_Policy</name>
      <anchor>a0</anchor>
      <arglist>(CORBA::ULong ssrc=0)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::ULong</type>
      <name>value</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>value</name>
      <anchor>a2</anchor>
      <arglist>(CORBA::ULong ssrc)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::ULong</type>
      <name>ssrc_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_TCP_Acceptor</name>
    <filename>classTAO__AV__TCP__Acceptor.html</filename>
    <base>TAO_AV_Acceptor</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_TCP_Acceptor</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_TCP_Acceptor</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>open</name>
      <anchor>a2</anchor>
      <arglist>(TAO_Base_StreamEndPoint *endpoint, TAO_AV_Core *av_core, TAO_FlowSpec_Entry *entry, TAO_AV_Flow_Protocol_Factory *factory, TAO_AV_Core::Flow_Component flow_component=TAO_AV_Core::TAO_AV_DATA)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>open_default</name>
      <anchor>a3</anchor>
      <arglist>(TAO_Base_StreamEndPoint *endpoint, TAO_AV_Core *av_core, TAO_FlowSpec_Entry *entry, TAO_AV_Flow_Protocol_Factory *factory, TAO_AV_Core::Flow_Component flow_component=TAO_AV_Core::TAO_AV_DATA)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>close</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>make_svc_handler</name>
      <anchor>a5</anchor>
      <arglist>(TAO_AV_TCP_Flow_Handler *&amp;handler)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_TCP_Base_Acceptor</type>
      <name>acceptor_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_FlowSpec_Entry *</type>
      <name>entry_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_Base_StreamEndPoint *</type>
      <name>endpoint_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Flow_Protocol_Factory *</type>
      <name>flow_protocol_factory_</name>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_TCP_Base_Acceptor</name>
    <filename>classTAO__AV__TCP__Base__Acceptor.html</filename>
    <base>ACE_Acceptor&lt; TAO_AV_TCP_Flow_Handler, ACE_SOCK_ACCEPTOR &gt;</base>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>acceptor_open</name>
      <anchor>a0</anchor>
      <arglist>(TAO_AV_TCP_Acceptor *acceptor, ACE_Reactor *reactor, const ACE_INET_Addr &amp;local_addr, TAO_FlowSpec_Entry *entry)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>make_svc_handler</name>
      <anchor>a1</anchor>
      <arglist>(TAO_AV_TCP_Flow_Handler *&amp;handler)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_TCP_Acceptor *</type>
      <name>acceptor_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_Reactor *</type>
      <name>reactor_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_FlowSpec_Entry *</type>
      <name>entry_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_TCP_Base_Connector</name>
    <filename>classTAO__AV__TCP__Base__Connector.html</filename>
    <base>ACE_Connector&lt; TAO_AV_TCP_Flow_Handler, ACE_SOCK_CONNECTOR &gt;</base>
    <member kind="function">
      <type>int</type>
      <name>connector_open</name>
      <anchor>a0</anchor>
      <arglist>(TAO_AV_TCP_Connector *connector, ACE_Reactor *reactor)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>connector_connect</name>
      <anchor>a1</anchor>
      <arglist>(TAO_AV_TCP_Flow_Handler *&amp;handler, const ACE_INET_Addr &amp;remote_addr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>make_svc_handler</name>
      <anchor>a2</anchor>
      <arglist>(TAO_AV_TCP_Flow_Handler *&amp;handler)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_TCP_Connector *</type>
      <name>connector_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_Reactor *</type>
      <name>reactor_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_TCP_Connector</name>
    <filename>classTAO__AV__TCP__Connector.html</filename>
    <base>TAO_AV_Connector</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_TCP_Connector</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_TCP_Connector</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>open</name>
      <anchor>a2</anchor>
      <arglist>(TAO_Base_StreamEndPoint *endpoint, TAO_AV_Core *av_core, TAO_AV_Flow_Protocol_Factory *factory)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>connect</name>
      <anchor>a3</anchor>
      <arglist>(TAO_FlowSpec_Entry *entry, TAO_AV_Transport *&amp;transport, TAO_AV_Core::Flow_Component flow_comp=TAO_AV_Core::TAO_AV_DATA)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>close</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>make_svc_handler</name>
      <anchor>a5</anchor>
      <arglist>(TAO_AV_TCP_Flow_Handler *&amp;handler)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Core *</type>
      <name>av_core_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_TCP_Base_Connector</type>
      <name>connector_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_Base_StreamEndPoint *</type>
      <name>endpoint_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_FlowSpec_Entry *</type>
      <name>entry_</name>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Flow_Protocol_Factory *</type>
      <name>flow_protocol_factory_</name>
      <anchor>n4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_TCP_Factory</name>
    <filename>classTAO__AV__TCP__Factory.html</filename>
    <base>TAO_AV_Transport_Factory</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_TCP_Factory</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_TCP_Factory</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>init</name>
      <anchor>a2</anchor>
      <arglist>(int argc, char *argv[])</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>match_protocol</name>
      <anchor>a3</anchor>
      <arglist>(const char *protocol_string)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_AV_Acceptor *</type>
      <name>make_acceptor</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_AV_Connector *</type>
      <name>make_connector</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_TCP_Flow_Factory</name>
    <filename>classTAO__AV__TCP__Flow__Factory.html</filename>
    <base>TAO_AV_Flow_Protocol_Factory</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_TCP_Flow_Factory</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_TCP_Flow_Factory</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>init</name>
      <anchor>a2</anchor>
      <arglist>(int argc, char *argv[])</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>match_protocol</name>
      <anchor>a3</anchor>
      <arglist>(const char *flow_string)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_Protocol_Object *</type>
      <name>make_protocol_object</name>
      <anchor>a4</anchor>
      <arglist>(TAO_FlowSpec_Entry *entry, TAO_Base_StreamEndPoint *endpoint, TAO_AV_Flow_Handler *handler, TAO_AV_Transport *transport)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_TCP_Flow_Handler</name>
    <filename>classTAO__AV__TCP__Flow__Handler.html</filename>
    <base virtualness="virtual">TAO_AV_Flow_Handler</base>
    <base>ACE_Svc_Handler&lt; ACE_SOCK_STREAM, ACE_NULL_SYNCH &gt;</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_TCP_Flow_Handler</name>
      <anchor>a0</anchor>
      <arglist>(TAO_AV_Callback *callback=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_TCP_Flow_Handler</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_AV_Transport *</type>
      <name>transport</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>open</name>
      <anchor>a3</anchor>
      <arglist>(void *=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_input</name>
      <anchor>a4</anchor>
      <arglist>(ACE_HANDLE fd)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_timeout</name>
      <anchor>a5</anchor>
      <arglist>(const ACE_Time_Value &amp;tv, const void *arg=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACE_Event_Handler *</type>
      <name>event_handler</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Core *</type>
      <name>av_core_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_TCP_Object</name>
    <filename>classTAO__AV__TCP__Object.html</filename>
    <base>TAO_AV_Protocol_Object</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_TCP_Object</name>
      <anchor>a0</anchor>
      <arglist>(TAO_AV_Callback *callback, TAO_AV_Transport *transport=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_TCP_Object</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_input</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>send_frame</name>
      <anchor>a3</anchor>
      <arglist>(ACE_Message_Block *frame, TAO_AV_frame_info *frame_info=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>send_frame</name>
      <anchor>a4</anchor>
      <arglist>(const iovec *iov, int iovcnt, TAO_AV_frame_info *frame_info=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>send_frame</name>
      <anchor>a5</anchor>
      <arglist>(const char *buf, size_t len)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>destroy</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_Message_Block</type>
      <name>frame_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_TCP_Transport</name>
    <filename>classTAO__AV__TCP__Transport.html</filename>
    <base>TAO_AV_Transport</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_TCP_Transport</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_AV_TCP_Transport</name>
      <anchor>a1</anchor>
      <arglist>(TAO_AV_TCP_Flow_Handler *handler)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_TCP_Transport</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>open</name>
      <anchor>a3</anchor>
      <arglist>(ACE_Addr *address)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>close</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>mtu</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACE_Addr *</type>
      <name>get_peer_addr</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ssize_t</type>
      <name>send</name>
      <anchor>a7</anchor>
      <arglist>(const ACE_Message_Block *mblk, ACE_Time_Value *s=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ssize_t</type>
      <name>send</name>
      <anchor>a8</anchor>
      <arglist>(const char *buf, size_t len, ACE_Time_Value *s=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ssize_t</type>
      <name>send</name>
      <anchor>a9</anchor>
      <arglist>(const iovec *iov, int iovcnt, ACE_Time_Value *s=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ssize_t</type>
      <name>recv</name>
      <anchor>a10</anchor>
      <arglist>(char *buf, size_t len, ACE_Time_Value *s=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ssize_t</type>
      <name>recv</name>
      <anchor>a11</anchor>
      <arglist>(char *buf, size_t len, int flags, ACE_Time_Value *s=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ssize_t</type>
      <name>recv</name>
      <anchor>a12</anchor>
      <arglist>(iovec *iov, int iovcnt, ACE_Time_Value *s=0)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_TCP_Flow_Handler *</type>
      <name>handler_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Transport</name>
    <filename>classTAO__AV__Transport.html</filename>
    <member kind="function">
      <type></type>
      <name>TAO_AV_Transport</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_Transport</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>open</name>
      <anchor>a2</anchor>
      <arglist>(ACE_Addr *address)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>close</name>
      <anchor>a3</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>mtu</name>
      <anchor>a4</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual ACE_Addr *</type>
      <name>get_peer_addr</name>
      <anchor>a5</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACE_Addr *</type>
      <name>get_local_addr</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual ssize_t</type>
      <name>send</name>
      <anchor>a7</anchor>
      <arglist>(const ACE_Message_Block *mblk, ACE_Time_Value *s=0)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual ssize_t</type>
      <name>send</name>
      <anchor>a8</anchor>
      <arglist>(const char *buf, size_t len, ACE_Time_Value *s=0)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual ssize_t</type>
      <name>send</name>
      <anchor>a9</anchor>
      <arglist>(const iovec *iov, int iovcnt, ACE_Time_Value *s=0)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual ssize_t</type>
      <name>recv</name>
      <anchor>a10</anchor>
      <arglist>(char *buf, size_t len, ACE_Time_Value *s=0)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual ssize_t</type>
      <name>recv</name>
      <anchor>a11</anchor>
      <arglist>(char *buf, size_t len, int flags, ACE_Time_Value *s=0)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual ssize_t</type>
      <name>recv</name>
      <anchor>a12</anchor>
      <arglist>(iovec *iov, int iovcnt, ACE_Time_Value *s=0)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Transport_Factory</name>
    <filename>classTAO__AV__Transport__Factory.html</filename>
    <base>ACE_Service_Object</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_Transport_Factory</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_Transport_Factory</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>init</name>
      <anchor>a2</anchor>
      <arglist>(int argc, char *argv[])</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>match_protocol</name>
      <anchor>a3</anchor>
      <arglist>(const char *protocol_string)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_AV_Acceptor *</type>
      <name>make_acceptor</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_AV_Connector *</type>
      <name>make_connector</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>ref_count</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_Transport_Item</name>
    <filename>classTAO__AV__Transport__Item.html</filename>
    <member kind="function">
      <type></type>
      <name>TAO_AV_Transport_Item</name>
      <anchor>a0</anchor>
      <arglist>(const ACE_CString &amp;name)</arglist>
    </member>
    <member kind="function">
      <type>const ACE_CString &amp;</type>
      <name>name</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_Transport_Factory *</type>
      <name>factory</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>factory</name>
      <anchor>a3</anchor>
      <arglist>(TAO_AV_Transport_Factory *factory)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_CString</type>
      <name>name_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>TAO_AV_Transport_Factory *</type>
      <name>factory_</name>
      <anchor>o1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_UDP_Acceptor</name>
    <filename>classTAO__AV__UDP__Acceptor.html</filename>
    <base>TAO_AV_Acceptor</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_UDP_Acceptor</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_UDP_Acceptor</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>open</name>
      <anchor>a2</anchor>
      <arglist>(TAO_Base_StreamEndPoint *endpoint, TAO_AV_Core *av_core, TAO_FlowSpec_Entry *entry, TAO_AV_Flow_Protocol_Factory *factory, TAO_AV_Core::Flow_Component flow_comp=TAO_AV_Core::TAO_AV_DATA)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>open_default</name>
      <anchor>a3</anchor>
      <arglist>(TAO_Base_StreamEndPoint *endpoint, TAO_AV_Core *av_core, TAO_FlowSpec_Entry *entry, TAO_AV_Flow_Protocol_Factory *factory, TAO_AV_Core::Flow_Component flow_comp=TAO_AV_Core::TAO_AV_DATA)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>open_i</name>
      <anchor>a4</anchor>
      <arglist>(ACE_INET_Addr *address, int is_default_open)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>close</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>activate_svc_handler</name>
      <anchor>a6</anchor>
      <arglist>(TAO_AV_Flow_Handler *handler)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_INET_Addr *</type>
      <name>address_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_INET_Addr *</type>
      <name>control_inet_address_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_Base_StreamEndPoint *</type>
      <name>endpoint_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_FlowSpec_Entry *</type>
      <name>entry_</name>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Flow_Protocol_Factory *</type>
      <name>flow_protocol_factory_</name>
      <anchor>n4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Core::Flow_Component</type>
      <name>flow_component_</name>
      <anchor>n5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_UDP_Connection_Setup</name>
    <filename>classTAO__AV__UDP__Connection__Setup.html</filename>
    <member kind="enumeration">
      <name>ConnectionType</name>
      <anchor>s2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>CONNECTOR</name>
      <anchor>s2s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACCEPTOR</name>
      <anchor>s2s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" static="yes">
      <type>int</type>
      <name>setup</name>
      <anchor>d0</anchor>
      <arglist>(TAO_AV_Flow_Handler *&amp;flow_handler, ACE_INET_Addr *inet_addr, ACE_INET_Addr *&amp;local_addr, int is_multicast, ConnectionType ct)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_UDP_Connector</name>
    <filename>classTAO__AV__UDP__Connector.html</filename>
    <base>TAO_AV_Connector</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_UDP_Connector</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_AV_UDP_Connector</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>open</name>
      <anchor>a2</anchor>
      <arglist>(TAO_Base_StreamEndPoint *endpoint, TAO_AV_Core *av_core, TAO_AV_Flow_Protocol_Factory *factory)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>connect</name>
      <anchor>a3</anchor>
      <arglist>(TAO_FlowSpec_Entry *entry, TAO_AV_Transport *&amp;transport, TAO_AV_Core::Flow_Component flow_comp=TAO_AV_Core::TAO_AV_DATA)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>activate_svc_handler</name>
      <anchor>a4</anchor>
      <arglist>(TAO_AV_Flow_Handler *handler)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>close</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_INET_Addr *</type>
      <name>control_inet_address_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_Base_StreamEndPoint *</type>
      <name>endpoint_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Core *</type>
      <name>av_core_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_FlowSpec_Entry *</type>
      <name>entry_</name>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Flow_Protocol_Factory *</type>
      <name>flow_protocol_factory_</name>
      <anchor>n4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Core::Flow_Component</type>
      <name>flow_component_</name>
      <anchor>n5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_UDP_Factory</name>
    <filename>classTAO__AV__UDP__Factory.html</filename>
    <base>TAO_AV_Transport_Factory</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_UDP_Factory</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_UDP_Factory</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>init</name>
      <anchor>a2</anchor>
      <arglist>(int argc, char *argv[])</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>match_protocol</name>
      <anchor>a3</anchor>
      <arglist>(const char *protocol_string)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_AV_Acceptor *</type>
      <name>make_acceptor</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_AV_Connector *</type>
      <name>make_connector</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_UDP_Flow_Factory</name>
    <filename>classTAO__AV__UDP__Flow__Factory.html</filename>
    <base>TAO_AV_Flow_Protocol_Factory</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_UDP_Flow_Factory</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_UDP_Flow_Factory</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>init</name>
      <anchor>a2</anchor>
      <arglist>(int argc, char *argv[])</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>match_protocol</name>
      <anchor>a3</anchor>
      <arglist>(const char *flow_string)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_Protocol_Object *</type>
      <name>make_protocol_object</name>
      <anchor>a4</anchor>
      <arglist>(TAO_FlowSpec_Entry *entry, TAO_Base_StreamEndPoint *endpoint, TAO_AV_Flow_Handler *handler, TAO_AV_Transport *transport)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_UDP_Flow_Handler</name>
    <filename>classTAO__AV__UDP__Flow__Handler.html</filename>
    <base virtualness="virtual">TAO_AV_Flow_Handler</base>
    <base virtualness="virtual">ACE_Event_Handler</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_UDP_Flow_Handler</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_UDP_Flow_Handler</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>open</name>
      <anchor>a2</anchor>
      <arglist>(ACE_Addr &amp;address)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>close</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual TAO_AV_Transport *</type>
      <name>transport</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>set_remote_address</name>
      <anchor>a5</anchor>
      <arglist>(ACE_Addr *address)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACE_HANDLE</type>
      <name>get_handle</name>
      <anchor>a6</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_input</name>
      <anchor>a7</anchor>
      <arglist>(ACE_HANDLE fd)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_timeout</name>
      <anchor>a8</anchor>
      <arglist>(const ACE_Time_Value &amp;tv, const void *arg=0)</arglist>
    </member>
    <member kind="function">
      <type>const ACE_SOCK_Dgram *</type>
      <name>get_socket</name>
      <anchor>a9</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACE_Event_Handler *</type>
      <name>event_handler</name>
      <anchor>a10</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>change_qos</name>
      <anchor>a11</anchor>
      <arglist>(AVStreams::QoS)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Core *</type>
      <name>av_core_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_INET_Addr</type>
      <name>peer_addr_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_SOCK_Dgram</type>
      <name>sock_dgram_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_UDP_MCast_Flow_Handler</name>
    <filename>classTAO__AV__UDP__MCast__Flow__Handler.html</filename>
    <base virtualness="virtual">TAO_AV_Flow_Handler</base>
    <base virtualness="virtual">ACE_Event_Handler</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_UDP_MCast_Flow_Handler</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_UDP_MCast_Flow_Handler</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACE_HANDLE</type>
      <name>get_handle</name>
      <anchor>a2</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_input</name>
      <anchor>a3</anchor>
      <arglist>(ACE_HANDLE fd)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_timeout</name>
      <anchor>a4</anchor>
      <arglist>(const ACE_Time_Value &amp;tv, const void *arg=0)</arglist>
    </member>
    <member kind="function">
      <type>ACE_SOCK_Dgram_Mcast *</type>
      <name>get_mcast_socket</name>
      <anchor>a5</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACE_Event_Handler *</type>
      <name>event_handler</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_peer_addr</name>
      <anchor>a7</anchor>
      <arglist>(ACE_INET_Addr *peer_addr)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_INET_Addr *</type>
      <name>peer_addr_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_SOCK_Dgram_Mcast *</type>
      <name>dgram_mcast_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_UDP_MCast_Transport</name>
    <filename>classTAO__AV__UDP__MCast__Transport.html</filename>
    <base>TAO_AV_Transport</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_UDP_MCast_Transport</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_AV_UDP_MCast_Transport</name>
      <anchor>a1</anchor>
      <arglist>(TAO_AV_UDP_MCast_Flow_Handler *handler)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_UDP_MCast_Transport</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>open</name>
      <anchor>a3</anchor>
      <arglist>(ACE_Addr *address)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>close</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>mtu</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACE_Addr *</type>
      <name>get_peer_addr</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACE_Addr *</type>
      <name>get_local_addr</name>
      <anchor>a7</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ssize_t</type>
      <name>send</name>
      <anchor>a8</anchor>
      <arglist>(const ACE_Message_Block *mblk, ACE_Time_Value *s=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ssize_t</type>
      <name>send</name>
      <anchor>a9</anchor>
      <arglist>(const char *buf, size_t len, ACE_Time_Value *s=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ssize_t</type>
      <name>send</name>
      <anchor>a10</anchor>
      <arglist>(const iovec *iov, int iovcnt, ACE_Time_Value *s=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ssize_t</type>
      <name>recv</name>
      <anchor>a11</anchor>
      <arglist>(char *buf, size_t len, ACE_Time_Value *s=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ssize_t</type>
      <name>recv</name>
      <anchor>a12</anchor>
      <arglist>(char *buf, size_t len, int flags, ACE_Time_Value *s=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ssize_t</type>
      <name>recv</name>
      <anchor>a13</anchor>
      <arglist>(iovec *iov, int iovcnt, ACE_Time_Value *s=0)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_UDP_MCast_Flow_Handler *</type>
      <name>handler_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_INET_Addr</type>
      <name>peer_addr_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_INET_Addr</type>
      <name>local_addr_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_UDP_Object</name>
    <filename>classTAO__AV__UDP__Object.html</filename>
    <base>TAO_AV_Protocol_Object</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_UDP_Object</name>
      <anchor>a0</anchor>
      <arglist>(TAO_AV_Callback *callback, TAO_AV_Transport *transport=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_UDP_Object</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_input</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>send_frame</name>
      <anchor>a3</anchor>
      <arglist>(ACE_Message_Block *frame, TAO_AV_frame_info *frame_info=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>send_frame</name>
      <anchor>a4</anchor>
      <arglist>(const iovec *iov, int iovcnt, TAO_AV_frame_info *frame_info=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>send_frame</name>
      <anchor>a5</anchor>
      <arglist>(const char *buf, size_t len)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>destroy</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="protected">
      <type>ACE_Message_Block</type>
      <name>frame_</name>
      <anchor>o0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_AV_UDP_Transport</name>
    <filename>classTAO__AV__UDP__Transport.html</filename>
    <base>TAO_AV_Transport</base>
    <member kind="function">
      <type></type>
      <name>TAO_AV_UDP_Transport</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_AV_UDP_Transport</name>
      <anchor>a1</anchor>
      <arglist>(TAO_AV_UDP_Flow_Handler *handler)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_AV_UDP_Transport</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>open</name>
      <anchor>a3</anchor>
      <arglist>(ACE_Addr *addr)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>close</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>mtu</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ACE_Addr *</type>
      <name>get_peer_addr</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>set_remote_address</name>
      <anchor>a7</anchor>
      <arglist>(const ACE_INET_Addr &amp;address)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ssize_t</type>
      <name>send</name>
      <anchor>a8</anchor>
      <arglist>(const ACE_Message_Block *mblk, ACE_Time_Value *s=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ssize_t</type>
      <name>send</name>
      <anchor>a9</anchor>
      <arglist>(const char *buf, size_t len, ACE_Time_Value *s=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ssize_t</type>
      <name>send</name>
      <anchor>a10</anchor>
      <arglist>(const iovec *iov, int iovcnt, ACE_Time_Value *s=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ssize_t</type>
      <name>recv</name>
      <anchor>a11</anchor>
      <arglist>(char *buf, size_t len, ACE_Time_Value *s=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ssize_t</type>
      <name>recv</name>
      <anchor>a12</anchor>
      <arglist>(char *buf, size_t len, int flags, ACE_Time_Value *s=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual ssize_t</type>
      <name>recv</name>
      <anchor>a13</anchor>
      <arglist>(iovec *iov, int iovcnt, ACE_Time_Value *s=0)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_UDP_Flow_Handler *</type>
      <name>handler</name>
      <anchor>a14</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_UDP_Flow_Handler *</type>
      <name>handler_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_Addr *</type>
      <name>addr_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_INET_Addr</type>
      <name>peer_addr_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_Base_StreamEndPoint</name>
    <filename>classTAO__Base__StreamEndPoint.html</filename>
    <member kind="function">
      <type></type>
      <name>TAO_Base_StreamEndPoint</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_Base_StreamEndPoint</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_open</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_close</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_stop</name>
      <anchor>a4</anchor>
      <arglist>(const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_start</name>
      <anchor>a5</anchor>
      <arglist>(const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_destroy</name>
      <anchor>a6</anchor>
      <arglist>(const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>handle_preconnect</name>
      <anchor>a7</anchor>
      <arglist>(AVStreams::flowSpec &amp;the_spec)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>handle_postconnect</name>
      <anchor>a8</anchor>
      <arglist>(AVStreams::flowSpec &amp;the_spec)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>handle_connection_requested</name>
      <anchor>a9</anchor>
      <arglist>(AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>get_callback</name>
      <anchor>a10</anchor>
      <arglist>(const char *flowname, TAO_AV_Callback *&amp;callback)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>get_control_callback</name>
      <anchor>a11</anchor>
      <arglist>(const char *flowname, TAO_AV_Callback *&amp;callback)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>set_protocol_object</name>
      <anchor>a12</anchor>
      <arglist>(const char *flowname, TAO_AV_Protocol_Object *object)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_flow_handler</name>
      <anchor>a13</anchor>
      <arglist>(const char *flowname, TAO_AV_Flow_Handler *handler)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_control_flow_handler</name>
      <anchor>a14</anchor>
      <arglist>(const char *flowname, TAO_AV_Flow_Handler *handler)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_QoS &amp;</type>
      <name>qos</name>
      <anchor>a15</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_QoS</type>
      <name>qos_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>Flow_Handler_Map</type>
      <name>flow_handler_map_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>Flow_Handler_Map</type>
      <name>control_flow_handler_map_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_Basic_StreamCtrl</name>
    <filename>classTAO__Basic__StreamCtrl.html</filename>
    <member kind="function">
      <type></type>
      <name>TAO_Basic_StreamCtrl</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_Basic_StreamCtrl</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>stop</name>
      <anchor>a2</anchor>
      <arglist>(const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>start</name>
      <anchor>a3</anchor>
      <arglist>(const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>destroy</name>
      <anchor>a4</anchor>
      <arglist>(const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>modify_QoS</name>
      <anchor>a5</anchor>
      <arglist>(AVStreams::streamQoS &amp;new_qos, const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>push_event</name>
      <anchor>a6</anchor>
      <arglist>(const struct CosPropertyService::Property &amp;the_event ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_FPStatus</name>
      <anchor>a7</anchor>
      <arglist>(const AVStreams::flowSpec &amp;the_spec, const char *fp_name, const CORBA::Any &amp;fp_settings ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Object_ptr</type>
      <name>get_flow_connection</name>
      <anchor>a8</anchor>
      <arglist>(const char *flow_name ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_flow_connection</name>
      <anchor>a9</anchor>
      <arglist>(const char *flow_name, CORBA::Object_ptr flow_connection ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="typedef" protection="public">
      <type>ACE_Hash_Map_Manager&lt; ACE_CString, AVStreams::FlowConnection_var, ACE_Null_Mutex &gt;</type>
      <name>FlowConnection_Map</name>
      <anchor>t0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef" protection="public">
      <type>ACE_Hash_Map_Iterator&lt; ACE_CString, AVStreams::FlowConnection_var, ACE_Null_Mutex &gt;</type>
      <name>FlowConnection_Map_Iterator</name>
      <anchor>t1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef" protection="public">
      <type>ACE_Hash_Map_Entry&lt; ACE_CString, AVStreams::FlowConnection_var &gt;</type>
      <name>FlowConnection_Map_Entry</name>
      <anchor>t2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::VDev_var</type>
      <name>vdev_a_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::VDev_var</type>
      <name>vdev_b_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::StreamEndPoint_A_var</type>
      <name>sep_a_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::StreamEndPoint_B_var</type>
      <name>sep_b_</name>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>FlowConnection_Map</type>
      <name>flow_connection_map_</name>
      <anchor>n4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::FlowConnection_seq</type>
      <name>flowConnections_</name>
      <anchor>n5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>u_int</type>
      <name>flow_count_</name>
      <anchor>n6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::flowSpec</type>
      <name>flows_</name>
      <anchor>n7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_FDev</name>
    <filename>classTAO__FDev.html</filename>
    <templarg>T_Producer</templarg>
    <templarg>T_Consumer</templarg>
    <member kind="function">
      <type></type>
      <name>TAO_FDev</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_FDev</name>
      <anchor>a1</anchor>
      <arglist>(const char *flowname)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_FDev</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>flowname</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>flowname</name>
      <anchor>a4</anchor>
      <arglist>(const char *flowname)</arglist>
    </member>
    <member kind="function">
      <type>AVStreams::FlowProducer_ptr</type>
      <name>create_producer</name>
      <anchor>a5</anchor>
      <arglist>(AVStreams::FlowConnection_ptr the_requester, AVStreams::QoS &amp;the_qos, CORBA::Boolean_out met_qos, char *&amp;named_fdev ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual AVStreams::FlowProducer_ptr</type>
      <name>make_producer</name>
      <anchor>a6</anchor>
      <arglist>(AVStreams::FlowConnection_ptr the_requester, AVStreams::QoS &amp;the_qos, CORBA::Boolean_out met_qos, char *&amp;named_fdev ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual AVStreams::FlowConsumer_ptr</type>
      <name>create_consumer</name>
      <anchor>a7</anchor>
      <arglist>(AVStreams::FlowConnection_ptr the_requester, AVStreams::QoS &amp;the_qos, CORBA::Boolean_out met_qos, char *&amp;named_fdev ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual AVStreams::FlowConsumer_ptr</type>
      <name>make_consumer</name>
      <anchor>a8</anchor>
      <arglist>(AVStreams::FlowConnection_ptr the_requester, AVStreams::QoS &amp;the_qos, CORBA::Boolean_out met_qos, char *&amp;named_fdev ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual AVStreams::FlowConnection_ptr</type>
      <name>bind</name>
      <anchor>a9</anchor>
      <arglist>(AVStreams::FDev_ptr peer_device, AVStreams::QoS &amp;the_qos, CORBA::Boolean_out is_met ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual AVStreams::FlowConnection_ptr</type>
      <name>bind_mcast</name>
      <anchor>a10</anchor>
      <arglist>(AVStreams::FDev_ptr first_peer, AVStreams::QoS &amp;the_qos, CORBA::Boolean_out is_met ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>destroy</name>
      <anchor>a11</anchor>
      <arglist>(AVStreams::FlowEndPoint_ptr the_ep, const char *fdev_name ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="typedef" protection="public">
      <type>ACE_DLList_Iterator&lt; TAO_FlowProducer &gt;</type>
      <name>PRODUCER_LIST_ITERATOR</name>
      <anchor>t0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef" protection="public">
      <type>ACE_DLList_Iterator&lt; TAO_FlowConsumer &gt;</type>
      <name>CONSUMER_LIST_ITERATOR</name>
      <anchor>t1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_DLList&lt; TAO_FlowProducer &gt;</type>
      <name>producer_list_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_DLList&lt; TAO_FlowConsumer &gt;</type>
      <name>consumer_list_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::String_var</type>
      <name>flowname_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_FlowConnection</name>
    <filename>classTAO__FlowConnection.html</filename>
    <member kind="function">
      <type></type>
      <name>TAO_FlowConnection</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>stop</name>
      <anchor>a1</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>start</name>
      <anchor>a2</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>destroy</name>
      <anchor>a3</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>modify_QoS</name>
      <anchor>a4</anchor>
      <arglist>(AVStreams::QoS &amp;new_qos ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>use_flow_protocol</name>
      <anchor>a5</anchor>
      <arglist>(const char *fp_name, const CORBA::Any &amp;fp_settings ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>push_event</name>
      <anchor>a6</anchor>
      <arglist>(const AVStreams::streamEvent &amp;the_event ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>connect_devs</name>
      <anchor>a7</anchor>
      <arglist>(AVStreams::FDev_ptr a_party, AVStreams::FDev_ptr b_party, AVStreams::QoS &amp;the_qos ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>connect</name>
      <anchor>a8</anchor>
      <arglist>(AVStreams::FlowProducer_ptr flow_producer, AVStreams::FlowConsumer_ptr flow_consumer, AVStreams::QoS &amp;the_qos ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>disconnect</name>
      <anchor>a9</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>add_producer</name>
      <anchor>a10</anchor>
      <arglist>(AVStreams::FlowProducer_ptr flow_producer, AVStreams::QoS &amp;the_qos ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>add_consumer</name>
      <anchor>a11</anchor>
      <arglist>(AVStreams::FlowConsumer_ptr flow_consumer, AVStreams::QoS &amp;the_qos ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>drop</name>
      <anchor>a12</anchor>
      <arglist>(AVStreams::FlowEndPoint_ptr target ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>set_mcast_addr</name>
      <anchor>a13</anchor>
      <arglist>(ACE_CString addr, u_short port)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_protocol</name>
      <anchor>a14</anchor>
      <arglist>(const char *protocol)</arglist>
    </member>
    <member kind="typedef" protection="public">
      <type>ACE_Unbounded_Set&lt; AVStreams::FlowProducer_ptr &gt;</type>
      <name>FlowProducer_Set</name>
      <anchor>t0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef" protection="public">
      <type>ACE_Unbounded_Set_Iterator&lt; AVStreams::FlowProducer_ptr &gt;</type>
      <name>FlowProducer_SetItor</name>
      <anchor>t1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef" protection="public">
      <type>ACE_Unbounded_Set&lt; AVStreams::FlowConsumer_ptr &gt;</type>
      <name>FlowConsumer_Set</name>
      <anchor>t2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef" protection="public">
      <type>ACE_Unbounded_Set_Iterator&lt; AVStreams::FlowConsumer_ptr &gt;</type>
      <name>FlowConsumer_SetItor</name>
      <anchor>t3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>FlowProducer_Set</type>
      <name>flow_producer_set_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>FlowConsumer_Set</type>
      <name>flow_consumer_set_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::String_var</type>
      <name>fp_name_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::Any</type>
      <name>fp_settings_</name>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::String_var</type>
      <name>producer_address_</name>
      <anchor>n4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>int</type>
      <name>ip_multicast_</name>
      <anchor>n5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_MCastConfigIf *</type>
      <name>mcastconfigif_i_</name>
      <anchor>n6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::MCastConfigIf_var</type>
      <name>mcastconfigif_</name>
      <anchor>n7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>u_short</type>
      <name>mcast_port_</name>
      <anchor>n8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_CString</type>
      <name>mcast_addr_</name>
      <anchor>n9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::String_var</type>
      <name>protocol_</name>
      <anchor>n10</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_FlowConsumer</name>
    <filename>classTAO__FlowConsumer.html</filename>
    <base virtualness="virtual">TAO_FlowEndPoint</base>
    <member kind="function">
      <type></type>
      <name>TAO_FlowConsumer</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_FlowConsumer</name>
      <anchor>a1</anchor>
      <arglist>(const char *flowname, AVStreams::protocolSpec protocols, const char *format)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>stop</name>
      <anchor>a2</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>start</name>
      <anchor>a3</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual char *</type>
      <name>go_to_listen</name>
      <anchor>a4</anchor>
      <arglist>(AVStreams::QoS &amp;the_qos, CORBA::Boolean is_mcast, AVStreams::FlowEndPoint_ptr peer, char *&amp;flowProtocol ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>connect_to_peer</name>
      <anchor>a5</anchor>
      <arglist>(AVStreams::QoS &amp;the_qos, const char *address, const char *use_flow_protocol ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_FlowEndPoint</name>
    <filename>classTAO__FlowEndPoint.html</filename>
    <base virtualness="virtual">TAO_Base_StreamEndPoint</base>
    <member kind="function">
      <type></type>
      <name>TAO_FlowEndPoint</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_FlowEndPoint</name>
      <anchor>a1</anchor>
      <arglist>(const char *flowname, AVStreams::protocolSpec &amp;protocols, const char *format)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>open</name>
      <anchor>a2</anchor>
      <arglist>(const char *flowname, AVStreams::protocolSpec &amp;protocols, const char *format)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>set_flowname</name>
      <anchor>a3</anchor>
      <arglist>(const char *flowname)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_flow_handler</name>
      <anchor>a4</anchor>
      <arglist>(const char *flowname, TAO_AV_Flow_Handler *handler)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>set_protocol_object</name>
      <anchor>a5</anchor>
      <arglist>(const char *flowname, TAO_AV_Protocol_Object *object)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>lock</name>
      <anchor>a6</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>unlock</name>
      <anchor>a7</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>destroy</name>
      <anchor>a8</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual AVStreams::StreamEndPoint_ptr</type>
      <name>related_sep</name>
      <anchor>a9</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>related_sep</name>
      <anchor>a10</anchor>
      <arglist>(AVStreams::StreamEndPoint_ptr related_sep ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual AVStreams::FlowConnection_ptr</type>
      <name>related_flow_connection</name>
      <anchor>a11</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>related_flow_connection</name>
      <anchor>a12</anchor>
      <arglist>(AVStreams::FlowConnection_ptr related_flow_connection ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual AVStreams::FlowEndPoint_ptr</type>
      <name>get_connected_fep</name>
      <anchor>a13</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>use_flow_protocol</name>
      <anchor>a14</anchor>
      <arglist>(const char *fp_name, const CORBA::Any &amp;fp_settings ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_format</name>
      <anchor>a15</anchor>
      <arglist>(const char *format ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_dev_params</name>
      <anchor>a16</anchor>
      <arglist>(const CosPropertyService::Properties &amp;new_settings ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_protocol_restriction</name>
      <anchor>a17</anchor>
      <arglist>(const AVStreams::protocolSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>is_fep_compatible</name>
      <anchor>a18</anchor>
      <arglist>(AVStreams::FlowEndPoint_ptr fep ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>set_peer</name>
      <anchor>a19</anchor>
      <arglist>(AVStreams::FlowConnection_ptr the_fc, AVStreams::FlowEndPoint_ptr the_peer_fep, AVStreams::QoS &amp;the_qos ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>set_Mcast_peer</name>
      <anchor>a20</anchor>
      <arglist>(AVStreams::FlowConnection_ptr the_fc, AVStreams::MCastConfigIf_ptr a_mcastconfigif, AVStreams::QoS &amp;the_qos ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual CORBA::Boolean</type>
      <name>connect_to_peer</name>
      <anchor>a21</anchor>
      <arglist>(AVStreams::QoS &amp;the_qos, const char *address, const char *use_flow_protocol ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>connect_to_peer_i</name>
      <anchor>a22</anchor>
      <arglist>(TAO_FlowSpec_Entry::Role role, AVStreams::QoS &amp;the_qos, const char *address, const char *use_flow_protocol ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual char *</type>
      <name>go_to_listen</name>
      <anchor>a23</anchor>
      <arglist>(AVStreams::QoS &amp;the_qos, CORBA::Boolean is_mcast, AVStreams::FlowEndPoint_ptr peer, char *&amp;flowProtocol ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual char *</type>
      <name>go_to_listen_i</name>
      <anchor>a24</anchor>
      <arglist>(TAO_FlowSpec_Entry::Role role, AVStreams::QoS &amp;the_qos, CORBA::Boolean is_mcast, AVStreams::FlowEndPoint_ptr peer, char *&amp;flowProtocol ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::StreamEndPoint_var</type>
      <name>related_sep_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::FlowConnection_var</type>
      <name>related_flow_connection_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::FlowEndPoint_var</type>
      <name>peer_fep_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::protocolSpec</type>
      <name>protocols_</name>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::protocolSpec</type>
      <name>protocol_addresses_</name>
      <anchor>n4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::MCastConfigIf_var</type>
      <name>mcast_peer_</name>
      <anchor>n5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::Boolean</type>
      <name>lock_</name>
      <anchor>n6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::String_var</type>
      <name>format_</name>
      <anchor>n7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::String_var</type>
      <name>flowname_</name>
      <anchor>n8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CosPropertyService::Properties</type>
      <name>dev_params_</name>
      <anchor>n9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_FlowSpecSet</type>
      <name>flow_spec_set_</name>
      <anchor>n10</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::String_var</type>
      <name>reverse_channel_</name>
      <anchor>n11</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_FlowProducer</name>
    <filename>classTAO__FlowProducer.html</filename>
    <base virtualness="virtual">TAO_FlowEndPoint</base>
    <member kind="function">
      <type></type>
      <name>TAO_FlowProducer</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_FlowProducer</name>
      <anchor>a1</anchor>
      <arglist>(const char *flowname, AVStreams::protocolSpec protocols, const char *format)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual char *</type>
      <name>get_rev_channel</name>
      <anchor>a2</anchor>
      <arglist>(const char *pcol_name ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>stop</name>
      <anchor>a3</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>start</name>
      <anchor>a4</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual char *</type>
      <name>go_to_listen</name>
      <anchor>a5</anchor>
      <arglist>(AVStreams::QoS &amp;the_qos, CORBA::Boolean is_mcast, AVStreams::FlowEndPoint_ptr peer, char *&amp;flowProtocol ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>connect_to_peer</name>
      <anchor>a6</anchor>
      <arglist>(AVStreams::QoS &amp;the_qos, const char *address, const char *use_flow_protocol ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual char *</type>
      <name>connect_mcast</name>
      <anchor>a7</anchor>
      <arglist>(AVStreams::QoS &amp;the_qos, CORBA::Boolean_out is_met, const char *address, const char *use_flow_protocol ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_key</name>
      <anchor>a8</anchor>
      <arglist>(const AVStreams::key &amp;the_key ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_source_id</name>
      <anchor>a9</anchor>
      <arglist>(CORBA::Long source_id ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::Long</type>
      <name>source_id_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::String_var</type>
      <name>peer_address_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_FlowSpec_Entry</name>
    <filename>classTAO__FlowSpec__Entry.html</filename>
    <member kind="enumeration">
      <name>Direction</name>
      <anchor>s6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_INVALID</name>
      <anchor>s6s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_DIR_IN</name>
      <anchor>s6s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_DIR_OUT</name>
      <anchor>s6s2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>Role</name>
      <anchor>s7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_INVALID_ROLE</name>
      <anchor>s7s3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_PRODUCER</name>
      <anchor>s7s4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_CONSUMER</name>
      <anchor>s7s5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_FlowSpec_Entry</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_FlowSpec_Entry</name>
      <anchor>a1</anchor>
      <arglist>(const char *flowname, const char *direction, const char *format_name, const char *flow_protocol, const char *carrier_protocol, ACE_Addr *address, ACE_Addr *control_address=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_FlowSpec_Entry</name>
      <anchor>a2</anchor>
      <arglist>(const char *flowname, const char *direction, const char *format_name, const char *flow_protocol, const char *address)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>parse</name>
      <anchor>a3</anchor>
      <arglist>(const char *flowSpec_entry)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_FlowSpec_Entry</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>direction</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual Role</type>
      <name>role</name>
      <anchor>a6</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>role</name>
      <anchor>a7</anchor>
      <arglist>(Role role)</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>direction_str</name>
      <anchor>a8</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>flow_protocol_str</name>
      <anchor>a9</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>flow_protocol_str</name>
      <anchor>a10</anchor>
      <arglist>(const char *flow_protocol_str)</arglist>
    </member>
    <member kind="function">
      <type>ACE_Addr *</type>
      <name>address</name>
      <anchor>a11</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>ACE_Addr *</type>
      <name>control_address</name>
      <anchor>a12</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>address</name>
      <anchor>a13</anchor>
      <arglist>(ACE_Addr *address)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>control_address</name>
      <anchor>a14</anchor>
      <arglist>(ACE_Addr *address)</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>address_str</name>
      <anchor>a15</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_Core::Protocol</type>
      <name>carrier_protocol</name>
      <anchor>a16</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>carrier_protocol_str</name>
      <anchor>a17</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>format</name>
      <anchor>a18</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>flowname</name>
      <anchor>a19</anchor>
      <arglist>(void) const</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual const char *</type>
      <name>entry_to_string</name>
      <anchor>a20</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>set_peer_addr</name>
      <anchor>a21</anchor>
      <arglist>(ACE_Addr *peer_addr)</arglist>
    </member>
    <member kind="function">
      <type>ACE_Addr *</type>
      <name>get_peer_addr</name>
      <anchor>a22</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>set_peer_control_addr</name>
      <anchor>a23</anchor>
      <arglist>(ACE_Addr *peer_control_addr)</arglist>
    </member>
    <member kind="function">
      <type>ACE_Addr *</type>
      <name>get_peer_control_addr</name>
      <anchor>a24</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>set_local_addr</name>
      <anchor>a25</anchor>
      <arglist>(ACE_Addr *local_addr)</arglist>
    </member>
    <member kind="function">
      <type>ACE_Addr *</type>
      <name>get_local_addr</name>
      <anchor>a26</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>char *</type>
      <name>get_local_addr_str</name>
      <anchor>a27</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>set_local_control_addr</name>
      <anchor>a28</anchor>
      <arglist>(ACE_Addr *local_control_addr)</arglist>
    </member>
    <member kind="function">
      <type>ACE_Addr *</type>
      <name>get_local_control_addr</name>
      <anchor>a29</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>char *</type>
      <name>get_local_control_addr_str</name>
      <anchor>a30</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_Transport *</type>
      <name>transport</name>
      <anchor>a31</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>transport</name>
      <anchor>a32</anchor>
      <arglist>(TAO_AV_Transport *transport)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_Transport *</type>
      <name>control_transport</name>
      <anchor>a33</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>control_transport</name>
      <anchor>a34</anchor>
      <arglist>(TAO_AV_Transport *control_transport)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_Flow_Handler *</type>
      <name>handler</name>
      <anchor>a35</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>handler</name>
      <anchor>a36</anchor>
      <arglist>(TAO_AV_Flow_Handler *handler)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_Flow_Handler *</type>
      <name>control_handler</name>
      <anchor>a37</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>control_handler</name>
      <anchor>a38</anchor>
      <arglist>(TAO_AV_Flow_Handler *control_handler)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_Protocol_Object *</type>
      <name>protocol_object</name>
      <anchor>a39</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>protocol_object</name>
      <anchor>a40</anchor>
      <arglist>(TAO_AV_Protocol_Object *object)</arglist>
    </member>
    <member kind="function">
      <type>TAO_AV_Protocol_Object *</type>
      <name>control_protocol_object</name>
      <anchor>a41</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>control_protocol_object</name>
      <anchor>a42</anchor>
      <arglist>(TAO_AV_Protocol_Object *object)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>parse_address</name>
      <anchor>a43</anchor>
      <arglist>(const char *format_string, TAO_AV_Core::Flow_Component flow_component)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>is_multicast</name>
      <anchor>a44</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>parse_flow_protocol_string</name>
      <anchor>b0</anchor>
      <arglist>(const char *flow_options_string)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>set_direction</name>
      <anchor>b1</anchor>
      <arglist>(const char *direction_string)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>set_protocol</name>
      <anchor>b2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_Addr *</type>
      <name>address_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>int</type>
      <name>clean_up_address_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_Addr *</type>
      <name>control_address_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>int</type>
      <name>clean_up_control_address_</name>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_CString</type>
      <name>address_str_</name>
      <anchor>n4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_CString</type>
      <name>format_</name>
      <anchor>n5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>Direction</type>
      <name>direction_</name>
      <anchor>n6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_CString</type>
      <name>direction_str_</name>
      <anchor>n7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_CString</type>
      <name>flowname_</name>
      <anchor>n8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Core::Protocol</type>
      <name>protocol_</name>
      <anchor>n9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_CString</type>
      <name>carrier_protocol_</name>
      <anchor>n10</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_CString</type>
      <name>flow_protocol_</name>
      <anchor>n11</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>int</type>
      <name>use_flow_protocol_</name>
      <anchor>n12</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_CString</type>
      <name>entry_</name>
      <anchor>n13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>int</type>
      <name>is_multicast_</name>
      <anchor>n14</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_Addr *</type>
      <name>peer_addr_</name>
      <anchor>n15</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_Addr *</type>
      <name>peer_control_addr_</name>
      <anchor>n16</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_Addr *</type>
      <name>local_addr_</name>
      <anchor>n17</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_Addr *</type>
      <name>local_control_addr_</name>
      <anchor>n18</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Transport *</type>
      <name>transport_</name>
      <anchor>n19</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Transport *</type>
      <name>control_transport_</name>
      <anchor>n20</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Flow_Handler *</type>
      <name>handler_</name>
      <anchor>n21</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Flow_Handler *</type>
      <name>control_handler_</name>
      <anchor>n22</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Protocol_Object *</type>
      <name>protocol_object_</name>
      <anchor>n23</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Protocol_Object *</type>
      <name>control_protocol_object_</name>
      <anchor>n24</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>Role</type>
      <name>role_</name>
      <anchor>n25</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_Forward_FlowSpec_Entry</name>
    <filename>classTAO__Forward__FlowSpec__Entry.html</filename>
    <base>TAO_FlowSpec_Entry</base>
    <member kind="enumeration">
      <name>Position</name>
      <anchor>s5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_FLOWNAME</name>
      <anchor>s5s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_DIRECTION</name>
      <anchor>s5s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_FORMAT</name>
      <anchor>s5s2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_FLOW_PROTOCOL</name>
      <anchor>s5s3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_ADDRESS</name>
      <anchor>s5s4</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_Forward_FlowSpec_Entry</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_Forward_FlowSpec_Entry</name>
      <anchor>a1</anchor>
      <arglist>(const char *flowname, const char *direction, const char *format_name, const char *flow_protocol, const char *carrier_protocol, ACE_Addr *address, ACE_Addr *control_address=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_Forward_FlowSpec_Entry</name>
      <anchor>a2</anchor>
      <arglist>(const char *flowname, const char *direction, const char *format_name, const char *flow_protocol, const char *address)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_Forward_FlowSpec_Entry</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>entry_to_string</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Role</type>
      <name>role</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>parse</name>
      <anchor>a6</anchor>
      <arglist>(const char *flowSpec_entry)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_MCastConfigIf</name>
    <filename>classTAO__MCastConfigIf.html</filename>
    <member kind="enumeration">
      <name>Peer_Interface</name>
      <anchor>s2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>VDEV</name>
      <anchor>s2s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>FLOWENDPOINT</name>
      <anchor>s2s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_MCastConfigIf</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_MCastConfigIf</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>set_peer</name>
      <anchor>a2</anchor>
      <arglist>(CORBA::Object_ptr peer, AVStreams::streamQoS &amp;the_qos, const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>configure</name>
      <anchor>a3</anchor>
      <arglist>(const CosPropertyService::Property &amp;a_configuration ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_initial_configuration</name>
      <anchor>a4</anchor>
      <arglist>(const CosPropertyService::Properties &amp;initial ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_format</name>
      <anchor>a5</anchor>
      <arglist>(const char *flowName, const char *format_name ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_dev_params</name>
      <anchor>a6</anchor>
      <arglist>(const char *flowName, const CosPropertyService::Properties &amp;new_params ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>in_flowSpec</name>
      <anchor>b0</anchor>
      <arglist>(const AVStreams::flowSpec &amp;flow_spec, const char *flow_name)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_SOCK_Dgram_Mcast</type>
      <name>sock_mcast_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CosPropertyService::Properties</type>
      <name>initial_configuration_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_DLList&lt; Peer_Info &gt;</type>
      <name>peer_list_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_DLList_Iterator&lt; Peer_Info &gt;</type>
      <name>peer_list_iterator_</name>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>TAO_MCastConfigIf::Peer_Info</name>
    <filename>structTAO__MCastConfigIf_1_1Peer__Info.html</filename>
    <member kind="variable">
      <type>AVStreams::VDev_var</type>
      <name>peer_</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>AVStreams::FlowEndPoint_var</type>
      <name>fep_</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>AVStreams::streamQoS</type>
      <name>qos_</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>AVStreams::flowSpec</type>
      <name>flow_spec_</name>
      <anchor>m3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>Peer_Interface</type>
      <name>interface_</name>
      <anchor>m4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_MediaControl</name>
    <filename>classTAO__MediaControl.html</filename>
    <member kind="function">
      <type></type>
      <name>TAO_MediaControl</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual AVStreams::Position</type>
      <name>get_media_position</name>
      <anchor>a1</anchor>
      <arglist>(AVStreams::PositionOrigin an_origin, AVStreams::PositionKey a_key ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>set_media_position</name>
      <anchor>a2</anchor>
      <arglist>(const AVStreams::Position &amp;a_position ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>start</name>
      <anchor>a3</anchor>
      <arglist>(const AVStreams::Position &amp;a_position ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>pause</name>
      <anchor>a4</anchor>
      <arglist>(const AVStreams::Position &amp;a_position ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>resume</name>
      <anchor>a5</anchor>
      <arglist>(const AVStreams::Position &amp;a_position ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual void</type>
      <name>stop</name>
      <anchor>a6</anchor>
      <arglist>(const AVStreams::Position &amp;a_position ACE_ENV_ARG_DECL_WITH_DEFAULTS)=0</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_MMDevice</name>
    <filename>classTAO__MMDevice.html</filename>
    <member kind="enumeration">
      <name>MMDevice_Type</name>
      <anchor>s2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>MMDEVICE_A</name>
      <anchor>s2s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>MMDEVICE_B</name>
      <anchor>s2s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_MMDevice</name>
      <anchor>a0</anchor>
      <arglist>(TAO_AV_Endpoint_Strategy *endpoint_strategy_)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual AVStreams::StreamEndPoint_ptr</type>
      <name>create_A_B</name>
      <anchor>a1</anchor>
      <arglist>(MMDevice_Type type, AVStreams::StreamCtrl_ptr the_requester, AVStreams::VDev_out the_vdev, AVStreams::streamQoS &amp;the_qos, CORBA::Boolean_out met_qos, char *&amp;named_vdev, const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual AVStreams::StreamCtrl_ptr</type>
      <name>bind</name>
      <anchor>a2</anchor>
      <arglist>(AVStreams::MMDevice_ptr peer_device, AVStreams::streamQoS &amp;the_qos, CORBA::Boolean_out is_met, const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual AVStreams::StreamCtrl_ptr</type>
      <name>bind_mcast</name>
      <anchor>a3</anchor>
      <arglist>(AVStreams::MMDevice_ptr first_peer, AVStreams::streamQoS &amp;the_qos, CORBA::Boolean_out is_met, const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual AVStreams::StreamEndPoint_A_ptr</type>
      <name>create_A</name>
      <anchor>a4</anchor>
      <arglist>(AVStreams::StreamCtrl_ptr the_requester, AVStreams::VDev_out the_vdev, AVStreams::streamQoS &amp;the_qos, CORBA::Boolean_out met_qos, char *&amp;named_vdev, const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual AVStreams::StreamEndPoint_B_ptr</type>
      <name>create_B</name>
      <anchor>a5</anchor>
      <arglist>(AVStreams::StreamCtrl_ptr the_requester, AVStreams::VDev_out the_vdev, AVStreams::streamQoS &amp;the_qos, CORBA::Boolean_out met_qos, char *&amp;named_vdev, const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>destroy</name>
      <anchor>a6</anchor>
      <arglist>(AVStreams::StreamEndPoint_ptr the_ep, const char *vdev_name ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual char *</type>
      <name>add_fdev</name>
      <anchor>a7</anchor>
      <arglist>(CORBA::Object_ptr the_fdev ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Object_ptr</type>
      <name>get_fdev</name>
      <anchor>a8</anchor>
      <arglist>(const char *flow_name ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>remove_fdev</name>
      <anchor>a9</anchor>
      <arglist>(const char *flow_name ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_MMDevice</name>
      <anchor>a10</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="typedef" protection="public">
      <type>ACE_Hash_Map_Manager&lt; ACE_CString, AVStreams::FDev_var, ACE_Null_Mutex &gt;</type>
      <name>FDev_Map</name>
      <anchor>t0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef" protection="public">
      <type>ACE_Hash_Map_Iterator&lt; ACE_CString, AVStreams::FDev_var, ACE_Null_Mutex &gt;</type>
      <name>FDev_Map_Iterator</name>
      <anchor>t1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef" protection="public">
      <type>ACE_Hash_Map_Entry&lt; ACE_CString, AVStreams::FDev_var &gt;</type>
      <name>FDev_Map_Entry</name>
      <anchor>t2</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="public">
      <type>char *</type>
      <name>add_fdev_i</name>
      <anchor>b0</anchor>
      <arglist>(AVStreams::FDev_ptr fdev ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_Endpoint_Strategy *</type>
      <name>endpoint_strategy_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>u_int</type>
      <name>flow_count_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>u_int</type>
      <name>flow_num_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>FDev_Map</type>
      <name>fdev_map_</name>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::flowSpec</type>
      <name>flows_</name>
      <anchor>n4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_StreamCtrl *</type>
      <name>stream_ctrl_</name>
      <anchor>n5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_Negotiator</name>
    <filename>classTAO__Negotiator.html</filename>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>negotiate</name>
      <anchor>a0</anchor>
      <arglist>(AVStreams::Negotiator_ptr remote_negotiator, const AVStreams::streamQoS &amp;qos_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_Reverse_FlowSpec_Entry</name>
    <filename>classTAO__Reverse__FlowSpec__Entry.html</filename>
    <base>TAO_FlowSpec_Entry</base>
    <member kind="enumeration">
      <name>Position</name>
      <anchor>s5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_FLOWNAME</name>
      <anchor>s5s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_ADDRESS</name>
      <anchor>s5s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_FLOW_PROTOCOL</name>
      <anchor>s5s2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_DIRECTION</name>
      <anchor>s5s3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TAO_AV_FORMAT</name>
      <anchor>s5s4</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_Reverse_FlowSpec_Entry</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_Reverse_FlowSpec_Entry</name>
      <anchor>a1</anchor>
      <arglist>(const char *flowname, const char *direction, const char *format_name, const char *flow_protocol, const char *carrier_protocol, ACE_Addr *address, ACE_Addr *control_address=0)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_Reverse_FlowSpec_Entry</name>
      <anchor>a2</anchor>
      <arglist>(const char *flowname, const char *direction, const char *format_name, const char *flow_protocol, const char *address)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_Reverse_FlowSpec_Entry</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual const char *</type>
      <name>entry_to_string</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual Role</type>
      <name>role</name>
      <anchor>a5</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>parse</name>
      <anchor>a6</anchor>
      <arglist>(const char *flowSpec_entry)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_SFP_Base</name>
    <filename>classTAO__SFP__Base.html</filename>
    <member kind="enumeration">
      <name>State</name>
      <anchor>s6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ACTIVE_START</name>
      <anchor>s6s0</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>PASSIVE_START</name>
      <anchor>s6s1</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TIMEDOUT_T1</name>
      <anchor>s6s2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>TIMEDOUT_T2</name>
      <anchor>s6s3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>REPLY_RECEIVED</name>
      <anchor>s6s4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>START_RECEIVED</name>
      <anchor>s6s5</anchor>
      <arglist></arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_SFP_Base</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::Boolean</type>
      <name>start_frame</name>
      <anchor>d0</anchor>
      <arglist>(CORBA::Octet flags, flowProtocol::MsgType type, TAO_OutputCDR &amp;msg)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::Boolean</type>
      <name>write_start_message</name>
      <anchor>d1</anchor>
      <arglist>(TAO_OutputCDR &amp;msg)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::Boolean</type>
      <name>write_start_reply_message</name>
      <anchor>d2</anchor>
      <arglist>(TAO_OutputCDR &amp;msg)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::Boolean</type>
      <name>write_credit_message</name>
      <anchor>d3</anchor>
      <arglist>(CORBA::ULong cred_num, TAO_OutputCDR &amp;msg)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::Boolean</type>
      <name>write_fragment_message</name>
      <anchor>d4</anchor>
      <arglist>(CORBA::Octet flags, CORBA::ULong fragment_number, CORBA::ULong sequence_number, CORBA::ULong source_id, TAO_OutputCDR &amp;msg)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>CORBA::Boolean</type>
      <name>write_frame_message</name>
      <anchor>d5</anchor>
      <arglist>(CORBA::ULong timestamp, CORBA::ULong synchSource, flowProtocol::my_seq_ulong source_ids, CORBA::ULong sequence_num, TAO_OutputCDR &amp;msg)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>int</type>
      <name>send_message</name>
      <anchor>d6</anchor>
      <arglist>(TAO_AV_Transport *transport, TAO_OutputCDR &amp;stream, ACE_Message_Block *mb=0)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>int</type>
      <name>peek_message_type</name>
      <anchor>d7</anchor>
      <arglist>(TAO_AV_Transport *transport, flowProtocol::MsgType &amp;type)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>int</type>
      <name>read_start_message</name>
      <anchor>d8</anchor>
      <arglist>(TAO_AV_Transport *transport, flowProtocol::Start &amp;start, TAO_InputCDR &amp;cdr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>int</type>
      <name>read_start_reply_message</name>
      <anchor>d9</anchor>
      <arglist>(TAO_AV_Transport *transport, flowProtocol::StartReply &amp;start_reply, TAO_InputCDR &amp;cdr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>int</type>
      <name>read_credit_message</name>
      <anchor>d10</anchor>
      <arglist>(TAO_AV_Transport *transport, flowProtocol::credit &amp;credit, TAO_InputCDR &amp;cdr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>int</type>
      <name>read_endofstream_message</name>
      <anchor>d11</anchor>
      <arglist>(TAO_AV_Transport *transport, flowProtocol::frameHeader &amp;endofstream, TAO_InputCDR &amp;cdr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>int</type>
      <name>read_frame</name>
      <anchor>d12</anchor>
      <arglist>(TAO_AV_Transport *transport, flowProtocol::frameHeader &amp;frame_header, TAO_SFP_Frame_State &amp;state, TAO_AV_frame_info *&amp;frame_info)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>int</type>
      <name>read_fragment</name>
      <anchor>d13</anchor>
      <arglist>(TAO_AV_Transport *transport, flowProtocol::fragment &amp;fragment, TAO_SFP_Frame_State &amp;state, TAO_AV_frame_info *&amp;frame_info)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>int</type>
      <name>peek_frame_header</name>
      <anchor>d14</anchor>
      <arglist>(TAO_AV_Transport *transport, flowProtocol::frameHeader &amp;header, TAO_InputCDR &amp;cdr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>int</type>
      <name>peek_fragment_header</name>
      <anchor>d15</anchor>
      <arglist>(TAO_AV_Transport *transport, flowProtocol::fragment &amp;fragment, TAO_InputCDR &amp;cdr)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>int</type>
      <name>handle_input</name>
      <anchor>d16</anchor>
      <arglist>(TAO_AV_Transport *transport, TAO_SFP_Frame_State &amp;state, TAO_AV_frame_info *&amp;frame_info)</arglist>
    </member>
    <member kind="function" static="yes">
      <type>ACE_Message_Block *</type>
      <name>check_all_fragments</name>
      <anchor>d17</anchor>
      <arglist>(TAO_SFP_Fragment_Table_Entry *fragment_entry)</arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>TAO_SFP_ORB_ARGUMENTS</name>
      <anchor>p0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>TAO_SFP_MAGIC_NUMBER</name>
      <anchor>p1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>TAO_SFP_FRAGMENT_MAGIC_NUMBER</name>
      <anchor>p2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>TAO_SFP_START_MAGIC_NUMBER</name>
      <anchor>p3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>TAO_SFP_CREDIT_MAGIC_NUMBER</name>
      <anchor>p4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const char *</type>
      <name>TAO_SFP_STARTREPLY_MAGIC_NUMBER</name>
      <anchor>p5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const unsigned char</type>
      <name>TAO_SFP_MAJOR_VERSION</name>
      <anchor>p6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const unsigned char</type>
      <name>TAO_SFP_MINOR_VERSION</name>
      <anchor>p7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const unsigned char</type>
      <name>TAO_SFP_FRAME_HEADER_LEN</name>
      <anchor>p8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const unsigned char</type>
      <name>TAO_SFP_MESSAGE_SIZE_OFFSET</name>
      <anchor>p9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>const unsigned char</type>
      <name>TAO_SFP_FRAGMENT_SIZE_OFFSET</name>
      <anchor>p10</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>u_int</type>
      <name>frame_header_len</name>
      <anchor>p11</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>u_int</type>
      <name>start_reply_len</name>
      <anchor>p12</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>u_int</type>
      <name>start_len</name>
      <anchor>p13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>u_int</type>
      <name>credit_len</name>
      <anchor>p14</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" static="yes">
      <type>u_int</type>
      <name>fragment_len</name>
      <anchor>p15</anchor>
      <arglist></arglist>
    </member>
    <member kind="function" protection="public" static="yes">
      <type>void</type>
      <name>dump_buf</name>
      <anchor>e0</anchor>
      <arglist>(char *buf, int n)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_SFP_Consumer_Object</name>
    <filename>classTAO__SFP__Consumer__Object.html</filename>
    <base>TAO_SFP_Object</base>
    <member kind="function">
      <type></type>
      <name>TAO_SFP_Consumer_Object</name>
      <anchor>a0</anchor>
      <arglist>(TAO_AV_Callback *callback, TAO_AV_Transport *transport, ACE_CString &amp;flow_options)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_input</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_SFP_Fragment_Node</name>
    <filename>classTAO__SFP__Fragment__Node.html</filename>
    <member kind="function">
      <type></type>
      <name>TAO_SFP_Fragment_Node</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable">
      <type>flowProtocol::fragment</type>
      <name>fragment_info_</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ACE_Message_Block *</type>
      <name>data_</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="friend">
      <type>friend int</type>
      <name>operator&lt;</name>
      <anchor>l0</anchor>
      <arglist>(const TAO_SFP_Fragment_Node &amp;left, const TAO_SFP_Fragment_Node &amp;right)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_SFP_Fragment_Table_Entry</name>
    <filename>classTAO__SFP__Fragment__Table__Entry.html</filename>
    <member kind="function">
      <type></type>
      <name>TAO_SFP_Fragment_Table_Entry</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable">
      <type>int</type>
      <name>last_received_</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>size_t</type>
      <name>num_fragments_</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>TAO_AV_frame_info</type>
      <name>frame_info</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ACE_Ordered_MultiSet&lt; TAO_SFP_Fragment_Node &gt;</type>
      <name>fragment_set_</name>
      <anchor>m3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_SFP_Frame_State</name>
    <filename>classTAO__SFP__Frame__State.html</filename>
    <member kind="function">
      <type></type>
      <name>TAO_SFP_Frame_State</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Boolean</type>
      <name>is_complete</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>reset</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable">
      <type>TAO_InputCDR</type>
      <name>cdr</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>flowProtocol::frameHeader</type>
      <name>frame_header_</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>flowProtocol::fragment</type>
      <name>fragment_</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>flowProtocol::frame</type>
      <name>frame_</name>
      <anchor>m3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>CORBA::Boolean</type>
      <name>more_fragments_</name>
      <anchor>m4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ACE_Message_Block *</type>
      <name>frame_block_</name>
      <anchor>m5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>ACE_Message_Block</type>
      <name>static_frame_</name>
      <anchor>m6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>TAO_SFP_Fragment_Table_Map</type>
      <name>fragment_table_map_</name>
      <anchor>m7</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_SFP_Object</name>
    <filename>classTAO__SFP__Object.html</filename>
    <base>TAO_AV_Protocol_Object</base>
    <member kind="function">
      <type></type>
      <name>TAO_SFP_Object</name>
      <anchor>a0</anchor>
      <arglist>(TAO_AV_Callback *callback, TAO_AV_Transport *transport)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_SFP_Object</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="pure">
      <type>virtual int</type>
      <name>handle_input</name>
      <anchor>a2</anchor>
      <arglist>(void)=0</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>send_frame</name>
      <anchor>a3</anchor>
      <arglist>(ACE_Message_Block *frame, TAO_AV_frame_info *frame_info=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>send_frame</name>
      <anchor>a4</anchor>
      <arglist>(const iovec *iov, int iovcnt, TAO_AV_frame_info *frame_info=0)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>send_frame</name>
      <anchor>a5</anchor>
      <arglist>(const char *buf, size_t len)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>destroy</name>
      <anchor>a6</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>set_policies</name>
      <anchor>a7</anchor>
      <arglist>(const TAO_AV_PolicyList &amp;policies)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>ACE_Message_Block *</type>
      <name>get_fragment</name>
      <anchor>b0</anchor>
      <arglist>(ACE_Message_Block *&amp;frame, size_t initial_len, size_t &amp;last_mb_orig_len, size_t &amp;last_mb_current_len)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::ULong</type>
      <name>sequence_num_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::ULong</type>
      <name>source_id_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::Long</type>
      <name>max_credit_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::Long</type>
      <name>current_credit_</name>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_SFP_Frame_State</type>
      <name>state_</name>
      <anchor>n4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_SFP_Producer_Object</name>
    <filename>classTAO__SFP__Producer__Object.html</filename>
    <base>TAO_SFP_Object</base>
    <member kind="function">
      <type></type>
      <name>TAO_SFP_Producer_Object</name>
      <anchor>a0</anchor>
      <arglist>(TAO_AV_Callback *callback, TAO_AV_Transport *transport, const char *flow_options)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>handle_input</name>
      <anchor>a1</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::ULong</type>
      <name>credit_sequence_num_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_StreamCtrl</name>
    <filename>classTAO__StreamCtrl.html</filename>
    <base virtualness="virtual">TAO_Basic_StreamCtrl</base>
    <member kind="function">
      <type></type>
      <name>TAO_StreamCtrl</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>TAO_StreamCtrl</name>
      <anchor>a1</anchor>
      <arglist>(TAO_StreamCtrl const &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_StreamCtrl</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>operator=</name>
      <anchor>a3</anchor>
      <arglist>(TAO_StreamCtrl const &amp;)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>stop</name>
      <anchor>a4</anchor>
      <arglist>(const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>start</name>
      <anchor>a5</anchor>
      <arglist>(const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>destroy</name>
      <anchor>a6</anchor>
      <arglist>(const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>bind_devs</name>
      <anchor>a7</anchor>
      <arglist>(AVStreams::MMDevice_ptr a_party, AVStreams::MMDevice_ptr b_party, AVStreams::streamQoS &amp;the_qos, const AVStreams::flowSpec &amp;the_flows ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>bind</name>
      <anchor>a8</anchor>
      <arglist>(AVStreams::StreamEndPoint_A_ptr a_party, AVStreams::StreamEndPoint_B_ptr b_party, AVStreams::streamQoS &amp;the_qos, const AVStreams::flowSpec &amp;the_flows ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>unbind_dev</name>
      <anchor>a9</anchor>
      <arglist>(AVStreams::MMDevice_ptr dev, const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>unbind_party</name>
      <anchor>a10</anchor>
      <arglist>(AVStreams::StreamEndPoint_ptr the_ep, const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>unbind</name>
      <anchor>a11</anchor>
      <arglist>(ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual AVStreams::VDev_ptr</type>
      <name>get_related_vdev</name>
      <anchor>a12</anchor>
      <arglist>(AVStreams::MMDevice_ptr adev, AVStreams::StreamEndPoint_out sep ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>modify_QoS</name>
      <anchor>a13</anchor>
      <arglist>(AVStreams::streamQoS &amp;new_qos, const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="typedef" protection="public">
      <type>ACE_Hash_Map_Manager&lt; MMDevice_Map_Hash_Key, MMDevice_Map_Entry, ACE_Null_Mutex &gt;</type>
      <name>MMDevice_Map</name>
      <anchor>t0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef" protection="public">
      <type>ACE_Hash_Map_Iterator&lt; MMDevice_Map_Hash_Key, MMDevice_Map_Entry, ACE_Null_Mutex &gt;</type>
      <name>MMDevice_Map_Iterator</name>
      <anchor>t1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>MMDevice_Map</type>
      <name>mmdevice_a_map_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>MMDevice_Map</type>
      <name>mmdevice_b_map_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_MCastConfigIf *</type>
      <name>mcastconfigif_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::MCastConfigIf_var</type>
      <name>mcastconfigif_ptr_</name>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::StreamCtrl_var</type>
      <name>streamctrl_</name>
      <anchor>n4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::ULong</type>
      <name>source_id_</name>
      <anchor>n5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>TAO_StreamCtrl::MMDevice_Map_Entry</name>
    <filename>structTAO__StreamCtrl_1_1MMDevice__Map__Entry.html</filename>
    <member kind="variable">
      <type>AVStreams::StreamEndPoint_var</type>
      <name>sep_</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>AVStreams::VDev_var</type>
      <name>vdev_</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>AVStreams::flowSpec</type>
      <name>flowspec_</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>AVStreams::streamQoS</type>
      <name>qos_</name>
      <anchor>m3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_StreamEndPoint</name>
    <filename>classTAO__StreamEndPoint.html</filename>
    <base virtualness="virtual">TAO_Base_StreamEndPoint</base>
    <member kind="function">
      <type></type>
      <name>TAO_StreamEndPoint</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>stop</name>
      <anchor>a1</anchor>
      <arglist>(const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>start</name>
      <anchor>a2</anchor>
      <arglist>(const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>destroy</name>
      <anchor>a3</anchor>
      <arglist>(const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>connect</name>
      <anchor>a4</anchor>
      <arglist>(AVStreams::StreamEndPoint_ptr responder, AVStreams::streamQoS &amp;qos_spec, const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>request_connection</name>
      <anchor>a5</anchor>
      <arglist>(AVStreams::StreamEndPoint_ptr initiator, CORBA::Boolean is_mcast, AVStreams::streamQoS &amp;qos, AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>modify_QoS</name>
      <anchor>a6</anchor>
      <arglist>(AVStreams::streamQoS &amp;new_qos, const AVStreams::flowSpec &amp;the_flows ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual int</type>
      <name>change_qos</name>
      <anchor>a7</anchor>
      <arglist>(AVStreams::streamQoS &amp;new_qos, const AVStreams::flowSpec &amp;the_flows ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>set_protocol_restriction</name>
      <anchor>a8</anchor>
      <arglist>(const AVStreams::protocolSpec &amp;the_pspec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>disconnect</name>
      <anchor>a9</anchor>
      <arglist>(const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_FPStatus</name>
      <anchor>a10</anchor>
      <arglist>(const AVStreams::flowSpec &amp;the_spec, const char *fp_name, const CORBA::Any &amp;fp_settings ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Object_ptr</type>
      <name>get_fep</name>
      <anchor>a11</anchor>
      <arglist>(const char *flow_name ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual char *</type>
      <name>add_fep</name>
      <anchor>a12</anchor>
      <arglist>(CORBA::Object_ptr the_fep ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>remove_fep</name>
      <anchor>a13</anchor>
      <arglist>(const char *fep_name ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_negotiator</name>
      <anchor>a14</anchor>
      <arglist>(AVStreams::Negotiator_ptr new_negotiator ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_key</name>
      <anchor>a15</anchor>
      <arglist>(const char *flow_name, const AVStreams::key &amp;the_key ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_source_id</name>
      <anchor>a16</anchor>
      <arglist>(CORBA::Long source_id ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_StreamEndPoint</name>
      <anchor>a17</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>CORBA::Boolean</type>
      <name>multiconnect</name>
      <anchor>a18</anchor>
      <arglist>(AVStreams::streamQoS &amp;the_qos, AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>char *</type>
      <name>add_fep_i</name>
      <anchor>b0</anchor>
      <arglist>(AVStreams::FlowEndPoint_ptr fep ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>char *</type>
      <name>add_fep_i_add_property</name>
      <anchor>b1</anchor>
      <arglist>(AVStreams::FlowEndPoint_ptr fep ACE_ENV_ARG_DECL)</arglist>
    </member>
    <member kind="function" protection="public">
      <type>int</type>
      <name>translate_qos</name>
      <anchor>b2</anchor>
      <arglist>(const AVStreams::streamQoS &amp;application_qos, AVStreams::streamQoS &amp;network_qos)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>u_int</type>
      <name>flow_count_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>u_int</type>
      <name>flow_num_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>FlowEndPoint_Map</type>
      <name>fep_map_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::flowSpec</type>
      <name>flows_</name>
      <anchor>n3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::Long</type>
      <name>source_id_</name>
      <anchor>n4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::Negotiator_var</type>
      <name>negotiator_</name>
      <anchor>n5</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::protocolSpec</type>
      <name>protocols_</name>
      <anchor>n6</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>CORBA::String_var</type>
      <name>protocol_</name>
      <anchor>n7</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::key</type>
      <name>key_</name>
      <anchor>n8</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>u_short</type>
      <name>mcast_port_</name>
      <anchor>n9</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_CString</type>
      <name>mcast_addr_</name>
      <anchor>n10</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_Hash_Map_Manager&lt; ACE_CString, TAO_FlowSpec_Entry *, ACE_Null_Mutex &gt;</type>
      <name>mcast_entry_map_</name>
      <anchor>n11</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_FlowSpecSet</type>
      <name>forward_flow_spec_set</name>
      <anchor>n12</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>TAO_AV_FlowSpecSet</type>
      <name>reverse_flow_spec_set</name>
      <anchor>n13</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::StreamEndPoint_var</type>
      <name>peer_sep_</name>
      <anchor>n14</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::SFPStatus *</type>
      <name>sfp_status_</name>
      <anchor>n15</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::StreamCtrl_var</type>
      <name>streamctrl_</name>
      <anchor>n16</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_StreamEndPoint_A</name>
    <filename>classTAO__StreamEndPoint__A.html</filename>
    <base virtualness="virtual">TAO_StreamEndPoint</base>
    <member kind="function">
      <type></type>
      <name>TAO_StreamEndPoint_A</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>multiconnect</name>
      <anchor>a1</anchor>
      <arglist>(AVStreams::streamQoS &amp;the_qos, AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>connect_leaf</name>
      <anchor>a2</anchor>
      <arglist>(AVStreams::StreamEndPoint_B_ptr the_ep, AVStreams::streamQoS &amp;the_qos, const AVStreams::flowSpec &amp;the_flows ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>disconnect_leaf</name>
      <anchor>a3</anchor>
      <arglist>(AVStreams::StreamEndPoint_B_ptr the_ep, const AVStreams::flowSpec &amp;theSpec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_StreamEndPoint_A</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_StreamEndPoint_B</name>
    <filename>classTAO__StreamEndPoint__B.html</filename>
    <base virtualness="virtual">TAO_StreamEndPoint</base>
    <member kind="function">
      <type></type>
      <name>TAO_StreamEndPoint_B</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>multiconnect</name>
      <anchor>a1</anchor>
      <arglist>(AVStreams::streamQoS &amp;the_qos, AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_StreamEndPoint_B</name>
      <anchor>a2</anchor>
      <arglist>(void)</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_Tokenizer</name>
    <filename>classTAO__Tokenizer.html</filename>
    <member kind="function">
      <type></type>
      <name>TAO_Tokenizer</name>
      <anchor>a0</anchor>
      <arglist>(const char *string, char delimiter)</arglist>
    </member>
    <member kind="function">
      <type></type>
      <name>~TAO_Tokenizer</name>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>parse</name>
      <anchor>a2</anchor>
      <arglist>(const char *string, char delimiter)</arglist>
    </member>
    <member kind="function">
      <type>char *</type>
      <name>token</name>
      <anchor>a3</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>int</type>
      <name>num_tokens</name>
      <anchor>a4</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function">
      <type>const char *</type>
      <name>operator[]</name>
      <anchor>a5</anchor>
      <arglist>(size_t index) const</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>ACE_Array&lt; char *&gt;</type>
      <name>token_array_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>size_t</type>
      <name>count_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>size_t</type>
      <name>num_tokens_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>char</type>
      <name>string_</name>
      <anchor>n3</anchor>
      <arglist>[BUFSIZ]</arglist>
    </member>
  </compound>
  <compound kind="class">
    <name>TAO_VDev</name>
    <filename>classTAO__VDev.html</filename>
    <member kind="function">
      <type></type>
      <name>TAO_VDev</name>
      <anchor>a0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>set_peer</name>
      <anchor>a1</anchor>
      <arglist>(AVStreams::StreamCtrl_ptr the_ctrl, AVStreams::VDev_ptr the_peer_dev, AVStreams::streamQoS &amp;the_qos, const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>set_Mcast_peer</name>
      <anchor>a2</anchor>
      <arglist>(AVStreams::StreamCtrl_ptr the_ctrl, AVStreams::MCastConfigIf_ptr a_mcastconfigif, AVStreams::streamQoS &amp;the_qos, const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>configure</name>
      <anchor>a3</anchor>
      <arglist>(const CosPropertyService::Property &amp;the_config_mesg ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_format</name>
      <anchor>a4</anchor>
      <arglist>(const char *flowName, const char *format_name ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual void</type>
      <name>set_dev_params</name>
      <anchor>a5</anchor>
      <arglist>(const char *flowName, const CosPropertyService::Properties &amp;new_params ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>modify_QoS</name>
      <anchor>a6</anchor>
      <arglist>(AVStreams::streamQoS &amp;the_qos, const AVStreams::flowSpec &amp;the_spec ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual</type>
      <name>~TAO_VDev</name>
      <anchor>b0</anchor>
      <arglist>(void)</arglist>
    </member>
    <member kind="function" protection="public" virtualness="virtual">
      <type>virtual CORBA::Boolean</type>
      <name>set_media_ctrl</name>
      <anchor>b1</anchor>
      <arglist>(CORBA::Object_ptr media_ctrl ACE_ENV_ARG_DECL_WITH_DEFAULTS)</arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::StreamCtrl_var</type>
      <name>streamctrl_</name>
      <anchor>n0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::VDev_var</type>
      <name>peer_</name>
      <anchor>n1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable" protection="public">
      <type>AVStreams::MCastConfigIf_var</type>
      <name>mcast_peer_</name>
      <anchor>n2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>AVStreams</name>
    <filename>namespaceAVStreams.html</filename>
    <class kind="exception">AVStreams::alreadyConnected</class>
    <class kind="interface">AVStreams::Basic_StreamCtrl</class>
    <class kind="exception">AVStreams::deviceQosMismatch</class>
    <class kind="exception">AVStreams::failedToConnect</class>
    <class kind="exception">AVStreams::failedToListen</class>
    <class kind="interface">AVStreams::FDev</class>
    <class kind="exception">AVStreams::FEPMismatch</class>
    <class kind="interface">AVStreams::FlowConnection</class>
    <class kind="interface">AVStreams::FlowConsumer</class>
    <class kind="interface">AVStreams::FlowEndPoint</class>
    <class kind="interface">AVStreams::FlowProducer</class>
    <class kind="struct">AVStreams::flowStatus</class>
    <class kind="exception">AVStreams::formatMismatch</class>
    <class kind="exception">AVStreams::formatNotSupported</class>
    <class kind="exception">AVStreams::FPError</class>
    <class kind="exception">AVStreams::InvalidPosition</class>
    <class kind="exception">AVStreams::invalidSettings</class>
    <class kind="interface">AVStreams::MCastConfigIf</class>
    <class kind="interface">AVStreams::MediaControl</class>
    <class kind="interface">AVStreams::MMDevice</class>
    <class kind="interface">AVStreams::Negotiator</class>
    <class kind="exception">AVStreams::noSuchFlow</class>
    <class kind="exception">AVStreams::notConnected</class>
    <class kind="exception">AVStreams::notSupported</class>
    <class kind="struct">AVStreams::Position</class>
    <class kind="exception">AVStreams::MediaControl::PostionKeyNotSupported</class>
    <class kind="exception">AVStreams::PostionKeyNotSupported</class>
    <class kind="exception">AVStreams::PropertyException</class>
    <class kind="exception">AVStreams::protocolNotSupported</class>
    <class kind="struct">AVStreams::QoS</class>
    <class kind="exception">AVStreams::QoSRequestFailed</class>
    <class kind="struct">AVStreams::SFPStatus</class>
    <class kind="interface">AVStreams::StreamCtrl</class>
    <class kind="interface">AVStreams::StreamEndPoint</class>
    <class kind="interface">AVStreams::StreamEndpoint</class>
    <class kind="interface">AVStreams::StreamEndPoint_A</class>
    <class kind="interface">AVStreams::StreamEndPoint_B</class>
    <class kind="exception">AVStreams::streamOpDenied</class>
    <class kind="exception">AVStreams::streamOpFailed</class>
    <class kind="interface">AVStreams::VDev</class>
    <member kind="typedef">
      <type>sequence&lt; QoS &gt;</type>
      <name>streamQoS</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>sequence&lt; string &gt;</type>
      <name>flowSpec</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>sequence&lt; string &gt;</type>
      <name>protocolSpec</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>sequence&lt; octet &gt;</type>
      <name>key</name>
      <anchor>a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>CosPropertyService::Property</type>
      <name>streamEvent</name>
      <anchor>a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>sequence&lt; FlowConnection &gt;</type>
      <name>FlowConnection_seq</name>
      <anchor>a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>sequence&lt; StreamEndPoint_A &gt;</type>
      <name>StreamEndPoint_A_seq</name>
      <anchor>a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>sequence&lt; StreamEndPoint_B &gt;</type>
      <name>StreamEndPoint_B_seq</name>
      <anchor>a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>sequence&lt; FlowEndPoint &gt;</type>
      <name>FlowEndPoint_seq</name>
      <anchor>a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>sequence&lt; Object &gt;</type>
      <name>Object_seq</name>
      <anchor>a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>flowState</name>
      <anchor>a21</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>stopped</name>
      <anchor>a21a10</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>started</name>
      <anchor>a21a11</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>dead</name>
      <anchor>a21a12</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>dirType</name>
      <anchor>a22</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>dir_in</name>
      <anchor>a22a13</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>dir_out</name>
      <anchor>a22a14</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>PositionOrigin</name>
      <anchor>a23</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>AbsolutePosition</name>
      <anchor>a23a15</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>RelativePosition</name>
      <anchor>a23a16</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ModuloPosition</name>
      <anchor>a23a17</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>PositionKey</name>
      <anchor>a24</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>ByteCount</name>
      <anchor>a24a18</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SampleCount</name>
      <anchor>a24a19</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>MediaTime</name>
      <anchor>a24a20</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="exception">
    <name>AVStreams::alreadyConnected</name>
    <filename>exceptionAVStreams_1_1alreadyConnected.html</filename>
  </compound>
  <compound kind="interface">
    <name>AVStreams::Basic_StreamCtrl</name>
    <filename>interfaceAVStreams_1_1Basic__StreamCtrl.html</filename>
    <member kind="function">
      <type>void</type>
      <name>stop</name>
      <anchor>a0</anchor>
      <arglist>(in flowSpec the_spec)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>start</name>
      <anchor>a1</anchor>
      <arglist>(in flowSpec the_spec)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>destroy</name>
      <anchor>a2</anchor>
      <arglist>(in flowSpec the_spec)</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>modify_QoS</name>
      <anchor>a3</anchor>
      <arglist>(inout streamQoS new_qos, in flowSpec the_spec)</arglist>
    </member>
    <member kind="function">
      <type>oneway void</type>
      <name>push_event</name>
      <anchor>a4</anchor>
      <arglist>(in streamEvent the_event)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_FPStatus</name>
      <anchor>a5</anchor>
      <arglist>(in flowSpec the_spec, in string fp_name, in any fp_settings)</arglist>
    </member>
    <member kind="function">
      <type>Object</type>
      <name>get_flow_connection</name>
      <anchor>a6</anchor>
      <arglist>(in string flow_name)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_flow_connection</name>
      <anchor>a7</anchor>
      <arglist>(in string flow_name, in Object flow_connection)</arglist>
    </member>
  </compound>
  <compound kind="exception">
    <name>AVStreams::deviceQosMismatch</name>
    <filename>exceptionAVStreams_1_1deviceQosMismatch.html</filename>
  </compound>
  <compound kind="exception">
    <name>AVStreams::failedToConnect</name>
    <filename>exceptionAVStreams_1_1failedToConnect.html</filename>
    <member kind="variable">
      <type>string</type>
      <name>reason</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="exception">
    <name>AVStreams::failedToListen</name>
    <filename>exceptionAVStreams_1_1failedToListen.html</filename>
    <member kind="variable">
      <type>string</type>
      <name>reason</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>AVStreams::FDev</name>
    <filename>interfaceAVStreams_1_1FDev.html</filename>
    <member kind="function">
      <type>FlowProducer</type>
      <name>create_producer</name>
      <anchor>a0</anchor>
      <arglist>(in FlowConnection the_requester, inout AVStreams::QoS the_qos, out boolean met_qos, inout string named_fdev)</arglist>
    </member>
    <member kind="function">
      <type>FlowConsumer</type>
      <name>create_consumer</name>
      <anchor>a1</anchor>
      <arglist>(in FlowConnection the_requester, inout AVStreams::QoS the_qos, out boolean met_qos, inout string named_fdev)</arglist>
    </member>
    <member kind="function">
      <type>FlowConnection</type>
      <name>bind</name>
      <anchor>a2</anchor>
      <arglist>(in FDev peer_device, inout AVStreams::QoS the_qos, out boolean is_met)</arglist>
    </member>
    <member kind="function">
      <type>FlowConnection</type>
      <name>bind_mcast</name>
      <anchor>a3</anchor>
      <arglist>(in FDev first_peer, inout AVStreams::QoS the_qos, out boolean is_met)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>destroy</name>
      <anchor>a4</anchor>
      <arglist>(in FlowEndPoint the_ep, in string fdev_name)</arglist>
    </member>
  </compound>
  <compound kind="exception">
    <name>AVStreams::FEPMismatch</name>
    <filename>exceptionAVStreams_1_1FEPMismatch.html</filename>
  </compound>
  <compound kind="interface">
    <name>AVStreams::FlowConnection</name>
    <filename>interfaceAVStreams_1_1FlowConnection.html</filename>
    <member kind="function">
      <type>void</type>
      <name>stop</name>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>start</name>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>destroy</name>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>modify_QoS</name>
      <anchor>a3</anchor>
      <arglist>(inout AVStreams::QoS new_qos)</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>use_flow_protocol</name>
      <anchor>a4</anchor>
      <arglist>(in string fp_name, in any fp_settings)</arglist>
    </member>
    <member kind="function">
      <type>oneway void</type>
      <name>push_event</name>
      <anchor>a5</anchor>
      <arglist>(in AVStreams::streamEvent the_event)</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>connect_devs</name>
      <anchor>a6</anchor>
      <arglist>(in FDev a_party, in FDev b_party, inout AVStreams::QoS the_qos)</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>connect</name>
      <anchor>a7</anchor>
      <arglist>(in FlowProducer flow_producer, in FlowConsumer flow_consumer, inout AVStreams::QoS the_qos)</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>disconnect</name>
      <anchor>a8</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>add_producer</name>
      <anchor>a9</anchor>
      <arglist>(in FlowProducer flow_producer, inout AVStreams::QoS the_qos)</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>add_consumer</name>
      <anchor>a10</anchor>
      <arglist>(in FlowConsumer flow_consumer, inout AVStreams::QoS the_qos)</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>drop</name>
      <anchor>a11</anchor>
      <arglist>(in FlowEndPoint target)</arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>AVStreams::FlowConsumer</name>
    <filename>interfaceAVStreams_1_1FlowConsumer.html</filename>
    <base>AVStreams::FlowEndPoint</base>
  </compound>
  <compound kind="interface">
    <name>AVStreams::FlowEndPoint</name>
    <filename>interfaceAVStreams_1_1FlowEndPoint.html</filename>
    <member kind="function">
      <type>boolean</type>
      <name>lock</name>
      <anchor>a0</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>unlock</name>
      <anchor>a1</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>stop</name>
      <anchor>a2</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>start</name>
      <anchor>a3</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>destroy</name>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>FlowEndPoint</type>
      <name>get_connected_fep</name>
      <anchor>a5</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>use_flow_protocol</name>
      <anchor>a6</anchor>
      <arglist>(in string fp_name, in any fp_settings)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_format</name>
      <anchor>a7</anchor>
      <arglist>(in string format)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_dev_params</name>
      <anchor>a8</anchor>
      <arglist>(in CosPropertyService::Properties new_settings)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_protocol_restriction</name>
      <anchor>a9</anchor>
      <arglist>(in AVStreams::protocolSpec the_spec)</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>is_fep_compatible</name>
      <anchor>a10</anchor>
      <arglist>(in FlowEndPoint fep)</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>set_peer</name>
      <anchor>a11</anchor>
      <arglist>(in FlowConnection the_fc, in FlowEndPoint the_peer_fep, inout AVStreams::QoS the_qos)</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>set_Mcast_peer</name>
      <anchor>a12</anchor>
      <arglist>(in FlowConnection the_fc, in AVStreams::MCastConfigIf a_mcastconfigif, inout AVStreams::QoS the_qos)</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>connect_to_peer</name>
      <anchor>a13</anchor>
      <arglist>(inout AVStreams::QoS the_qos, in string address, in string use_flow_protocol)</arglist>
    </member>
    <member kind="function">
      <type>string</type>
      <name>go_to_listen</name>
      <anchor>a14</anchor>
      <arglist>(inout AVStreams::QoS the_qos, in boolean is_mcast, in FlowEndPoint peer, inout string flowProtocol)</arglist>
    </member>
    <member kind="variable">
      <type>attribute AVStreams::StreamEndPoint</type>
      <name>related_sep</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>attribute FlowConnection</type>
      <name>related_flow_connection</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>AVStreams::FlowProducer</name>
    <filename>interfaceAVStreams_1_1FlowProducer.html</filename>
    <base>AVStreams::FlowEndPoint</base>
    <member kind="function">
      <type>string</type>
      <name>connect_mcast</name>
      <anchor>a0</anchor>
      <arglist>(inout AVStreams::QoS the_qos, out boolean is_met, in string address, in string use_flow_protocol)</arglist>
    </member>
    <member kind="function">
      <type>string</type>
      <name>get_rev_channel</name>
      <anchor>a1</anchor>
      <arglist>(in string pcol_name)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_key</name>
      <anchor>a2</anchor>
      <arglist>(in AVStreams::key the_key)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_source_id</name>
      <anchor>a3</anchor>
      <arglist>(in long source_id)</arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>AVStreams::flowStatus</name>
    <filename>structAVStreams_1_1flowStatus.html</filename>
    <member kind="variable">
      <type>string</type>
      <name>flowName</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>dirType</type>
      <name>directionality</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>flowState</type>
      <name>status</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>SFPStatus</type>
      <name>theFormat</name>
      <anchor>m3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>QoS</type>
      <name>theQoS</name>
      <anchor>m4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="exception">
    <name>AVStreams::formatMismatch</name>
    <filename>exceptionAVStreams_1_1formatMismatch.html</filename>
  </compound>
  <compound kind="exception">
    <name>AVStreams::formatNotSupported</name>
    <filename>exceptionAVStreams_1_1formatNotSupported.html</filename>
  </compound>
  <compound kind="exception">
    <name>AVStreams::FPError</name>
    <filename>exceptionAVStreams_1_1FPError.html</filename>
    <member kind="variable">
      <type>string</type>
      <name>flow_name</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="exception">
    <name>AVStreams::InvalidPosition</name>
    <filename>exceptionAVStreams_1_1InvalidPosition.html</filename>
    <member kind="variable">
      <type>PositionKey</type>
      <name>key</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="exception">
    <name>AVStreams::invalidSettings</name>
    <filename>exceptionAVStreams_1_1invalidSettings.html</filename>
    <member kind="variable">
      <type>string</type>
      <name>settings</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>AVStreams::MCastConfigIf</name>
    <filename>interfaceAVStreams_1_1MCastConfigIf.html</filename>
    <member kind="function">
      <type>boolean</type>
      <name>set_peer</name>
      <anchor>a0</anchor>
      <arglist>(in Object peer, inout streamQoS the_qos, in flowSpec the_spec)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>configure</name>
      <anchor>a1</anchor>
      <arglist>(in CosPropertyService::Property a_configuration)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_initial_configuration</name>
      <anchor>a2</anchor>
      <arglist>(in CosPropertyService::Properties initial)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_format</name>
      <anchor>a3</anchor>
      <arglist>(in string flowName, in string format_name)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_dev_params</name>
      <anchor>a4</anchor>
      <arglist>(in string flowName, in CosPropertyService::Properties new_params)</arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>AVStreams::MediaControl</name>
    <filename>interfaceAVStreams_1_1MediaControl.html</filename>
    <member kind="function">
      <type>Position</type>
      <name>get_media_position</name>
      <anchor>a0</anchor>
      <arglist>(in PositionOrigin an_origin, in PositionKey a_key)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_media_position</name>
      <anchor>a1</anchor>
      <arglist>(in Position a_position)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>start</name>
      <anchor>a2</anchor>
      <arglist>(in Position a_position)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>pause</name>
      <anchor>a3</anchor>
      <arglist>(in Position a_position)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>resume</name>
      <anchor>a4</anchor>
      <arglist>(in Position a_position)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>stop</name>
      <anchor>a5</anchor>
      <arglist>(in Position a_position)</arglist>
    </member>
  </compound>
  <compound kind="exception">
    <name>AVStreams::MediaControl::PostionKeyNotSupported</name>
    <filename>exceptionAVStreams_1_1MediaControl_1_1PostionKeyNotSupported.html</filename>
    <member kind="variable">
      <type>PositionKey</type>
      <name>key</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>AVStreams::MMDevice</name>
    <filename>interfaceAVStreams_1_1MMDevice.html</filename>
    <member kind="function">
      <type>StreamEndPoint_A</type>
      <name>create_A</name>
      <anchor>a0</anchor>
      <arglist>(in StreamCtrl the_requester, out VDev the_vdev, inout streamQoS the_qos, out boolean met_qos, inout string named_vdev, in flowSpec the_spec)</arglist>
    </member>
    <member kind="function">
      <type>StreamEndPoint_B</type>
      <name>create_B</name>
      <anchor>a1</anchor>
      <arglist>(in StreamCtrl the_requester, out VDev the_vdev, inout streamQoS the_qos, out boolean met_qos, inout string named_vdev, in flowSpec the_spec)</arglist>
    </member>
    <member kind="function">
      <type>StreamCtrl</type>
      <name>bind</name>
      <anchor>a2</anchor>
      <arglist>(in MMDevice peer_device, inout streamQoS the_qos, out boolean is_met, in flowSpec the_spec)</arglist>
    </member>
    <member kind="function">
      <type>StreamCtrl</type>
      <name>bind_mcast</name>
      <anchor>a3</anchor>
      <arglist>(in MMDevice first_peer, inout streamQoS the_qos, out boolean is_met, in flowSpec the_spec)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>destroy</name>
      <anchor>a4</anchor>
      <arglist>(in StreamEndPoint the_ep, in string vdev_name)</arglist>
    </member>
    <member kind="function">
      <type>string</type>
      <name>add_fdev</name>
      <anchor>a5</anchor>
      <arglist>(in Object the_fdev)</arglist>
    </member>
    <member kind="function">
      <type>Object</type>
      <name>get_fdev</name>
      <anchor>a6</anchor>
      <arglist>(in string flow_name)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>remove_fdev</name>
      <anchor>a7</anchor>
      <arglist>(in string flow_name)</arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>AVStreams::Negotiator</name>
    <filename>interfaceAVStreams_1_1Negotiator.html</filename>
    <member kind="function">
      <type>boolean</type>
      <name>negotiate</name>
      <anchor>a0</anchor>
      <arglist>(in Negotiator remote_negotiator, in streamQoS qos_spec)</arglist>
    </member>
  </compound>
  <compound kind="exception">
    <name>AVStreams::noSuchFlow</name>
    <filename>exceptionAVStreams_1_1noSuchFlow.html</filename>
  </compound>
  <compound kind="exception">
    <name>AVStreams::notConnected</name>
    <filename>exceptionAVStreams_1_1notConnected.html</filename>
  </compound>
  <compound kind="exception">
    <name>AVStreams::notSupported</name>
    <filename>exceptionAVStreams_1_1notSupported.html</filename>
  </compound>
  <compound kind="struct">
    <name>AVStreams::Position</name>
    <filename>structAVStreams_1_1Position.html</filename>
    <member kind="variable">
      <type>PositionOrigin</type>
      <name>origin</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>PositionKey</type>
      <name>key</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>long</type>
      <name>value</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="exception">
    <name>AVStreams::MediaControl::PostionKeyNotSupported</name>
    <filename>exceptionAVStreams_1_1MediaControl_1_1PostionKeyNotSupported.html</filename>
    <member kind="variable">
      <type>PositionKey</type>
      <name>key</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="exception">
    <name>AVStreams::PostionKeyNotSupported</name>
    <filename>exceptionAVStreams_1_1PostionKeyNotSupported.html</filename>
    <member kind="variable">
      <type>PositionKey</type>
      <name>key</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="exception">
    <name>AVStreams::PropertyException</name>
    <filename>exceptionAVStreams_1_1PropertyException.html</filename>
  </compound>
  <compound kind="exception">
    <name>AVStreams::protocolNotSupported</name>
    <filename>exceptionAVStreams_1_1protocolNotSupported.html</filename>
  </compound>
  <compound kind="struct">
    <name>AVStreams::QoS</name>
    <filename>structAVStreams_1_1QoS.html</filename>
    <member kind="variable">
      <type>string</type>
      <name>QoSType</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>CosPropertyService::Properties</type>
      <name>QoSParams</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="exception">
    <name>AVStreams::QoSRequestFailed</name>
    <filename>exceptionAVStreams_1_1QoSRequestFailed.html</filename>
    <member kind="variable">
      <type>string</type>
      <name>reason</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>AVStreams::SFPStatus</name>
    <filename>structAVStreams_1_1SFPStatus.html</filename>
    <member kind="variable">
      <type>boolean</type>
      <name>isFormatted</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>boolean</type>
      <name>isSpecialFormat</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>boolean</type>
      <name>seqNums</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>boolean</type>
      <name>timestamps</name>
      <anchor>m3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>boolean</type>
      <name>sourceIndicators</name>
      <anchor>m4</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>AVStreams::StreamCtrl</name>
    <filename>interfaceAVStreams_1_1StreamCtrl.html</filename>
    <base>AVStreams::Basic_StreamCtrl</base>
    <member kind="function">
      <type>boolean</type>
      <name>bind_devs</name>
      <anchor>a0</anchor>
      <arglist>(in MMDevice a_party, in MMDevice b_party, inout streamQoS the_qos, in flowSpec the_flows)</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>bind</name>
      <anchor>a1</anchor>
      <arglist>(in StreamEndPoint_A a_party, in StreamEndPoint_B b_party, inout streamQoS the_qos, in flowSpec the_flows)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>unbind_dev</name>
      <anchor>a2</anchor>
      <arglist>(in MMDevice dev, in flowSpec the_spec)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>unbind_party</name>
      <anchor>a3</anchor>
      <arglist>(in StreamEndPoint the_ep, in flowSpec the_spec)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>unbind</name>
      <anchor>a4</anchor>
      <arglist>()</arglist>
    </member>
    <member kind="function">
      <type>VDev</type>
      <name>get_related_vdev</name>
      <anchor>a5</anchor>
      <arglist>(in MMDevice adev, out StreamEndPoint sep)</arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>AVStreams::StreamEndPoint</name>
    <filename>interfaceAVStreams_1_1StreamEndPoint.html</filename>
    <member kind="function">
      <type>void</type>
      <name>stop</name>
      <anchor>a0</anchor>
      <arglist>(in flowSpec the_spec)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>start</name>
      <anchor>a1</anchor>
      <arglist>(in flowSpec the_spec)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>destroy</name>
      <anchor>a2</anchor>
      <arglist>(in flowSpec the_spec)</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>connect</name>
      <anchor>a3</anchor>
      <arglist>(in StreamEndPoint responder, inout streamQoS qos_spec, in flowSpec the_spec)</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>request_connection</name>
      <anchor>a4</anchor>
      <arglist>(in StreamEndPoint initiator, in boolean is_mcast, inout streamQoS qos, inout flowSpec the_spec)</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>modify_QoS</name>
      <anchor>a5</anchor>
      <arglist>(inout streamQoS new_qos, in flowSpec the_flows)</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>set_protocol_restriction</name>
      <anchor>a6</anchor>
      <arglist>(in protocolSpec the_pspec)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>disconnect</name>
      <anchor>a7</anchor>
      <arglist>(in flowSpec the_spec)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_FPStatus</name>
      <anchor>a8</anchor>
      <arglist>(in flowSpec the_spec, in string fp_name, in any fp_settings)</arglist>
    </member>
    <member kind="function">
      <type>Object</type>
      <name>get_fep</name>
      <anchor>a9</anchor>
      <arglist>(in string flow_name)</arglist>
    </member>
    <member kind="function">
      <type>string</type>
      <name>add_fep</name>
      <anchor>a10</anchor>
      <arglist>(in Object the_fep)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>remove_fep</name>
      <anchor>a11</anchor>
      <arglist>(in string fep_name)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_negotiator</name>
      <anchor>a12</anchor>
      <arglist>(in Negotiator new_negotiator)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_key</name>
      <anchor>a13</anchor>
      <arglist>(in string flow_name, in key the_key)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_source_id</name>
      <anchor>a14</anchor>
      <arglist>(in long source_id)</arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>AVStreams::StreamEndpoint</name>
    <filename>interfaceAVStreams_1_1StreamEndpoint.html</filename>
  </compound>
  <compound kind="interface">
    <name>AVStreams::StreamEndPoint_A</name>
    <filename>interfaceAVStreams_1_1StreamEndPoint__A.html</filename>
    <base>AVStreams::StreamEndPoint</base>
    <member kind="function">
      <type>boolean</type>
      <name>multiconnect</name>
      <anchor>a0</anchor>
      <arglist>(inout streamQoS the_qos, inout flowSpec the_spec)</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>connect_leaf</name>
      <anchor>a1</anchor>
      <arglist>(in StreamEndPoint_B the_ep, inout streamQoS the_qos, in flowSpec the_flows)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>disconnect_leaf</name>
      <anchor>a2</anchor>
      <arglist>(in StreamEndPoint_B the_ep, in flowSpec theSpec)</arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>AVStreams::StreamEndPoint_B</name>
    <filename>interfaceAVStreams_1_1StreamEndPoint__B.html</filename>
    <base>AVStreams::StreamEndPoint</base>
    <member kind="function">
      <type>boolean</type>
      <name>multiconnect</name>
      <anchor>a0</anchor>
      <arglist>(inout streamQoS the_qos, inout flowSpec the_spec)</arglist>
    </member>
  </compound>
  <compound kind="exception">
    <name>AVStreams::streamOpDenied</name>
    <filename>exceptionAVStreams_1_1streamOpDenied.html</filename>
    <member kind="variable">
      <type>string</type>
      <name>reason</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="exception">
    <name>AVStreams::streamOpFailed</name>
    <filename>exceptionAVStreams_1_1streamOpFailed.html</filename>
    <member kind="variable">
      <type>string</type>
      <name>reason</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="interface">
    <name>AVStreams::VDev</name>
    <filename>interfaceAVStreams_1_1VDev.html</filename>
    <member kind="function">
      <type>boolean</type>
      <name>set_peer</name>
      <anchor>a0</anchor>
      <arglist>(in StreamCtrl the_ctrl, in VDev the_peer_dev, inout streamQoS the_qos, in flowSpec the_spec)</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>set_Mcast_peer</name>
      <anchor>a1</anchor>
      <arglist>(in StreamCtrl the_ctrl, in MCastConfigIf a_mcastconfigif, inout streamQoS the_qos, in flowSpec the_spec)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>configure</name>
      <anchor>a2</anchor>
      <arglist>(in CosPropertyService::Property the_config_mesg)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_format</name>
      <anchor>a3</anchor>
      <arglist>(in string flowName, in string format_name)</arglist>
    </member>
    <member kind="function">
      <type>void</type>
      <name>set_dev_params</name>
      <anchor>a4</anchor>
      <arglist>(in string flowName, in CosPropertyService::Properties new_params)</arglist>
    </member>
    <member kind="function">
      <type>boolean</type>
      <name>modify_QoS</name>
      <anchor>a5</anchor>
      <arglist>(inout streamQoS the_qos, in flowSpec the_spec)</arglist>
    </member>
  </compound>
  <compound kind="namespace">
    <name>flowProtocol</name>
    <filename>namespaceflowProtocol.html</filename>
    <class kind="struct">flowProtocol::credit</class>
    <class kind="struct">flowProtocol::fragment</class>
    <class kind="struct">flowProtocol::frame</class>
    <class kind="struct">flowProtocol::frameHeader</class>
    <class kind="struct">flowProtocol::sequencedFrame</class>
    <class kind="struct">flowProtocol::specialFrame</class>
    <class kind="struct">flowProtocol::Start</class>
    <class kind="struct">flowProtocol::StartReply</class>
    <member kind="typedef">
      <type>sequence&lt; char &gt;</type>
      <name>my_seq_char</name>
      <anchor>a0</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>sequence&lt; unsigned long &gt;</type>
      <name>my_seq_ulong</name>
      <anchor>a1</anchor>
      <arglist></arglist>
    </member>
    <member kind="typedef">
      <type>unsigned long</type>
      <name>frameID</name>
      <anchor>a2</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumeration">
      <name>MsgType</name>
      <anchor>a12</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>Start_Msg</name>
      <anchor>a12a3</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>EndofStream_Msg</name>
      <anchor>a12a4</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SimpleFrame_Msg</name>
      <anchor>a12a5</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SequencedFrame_Msg</name>
      <anchor>a12a6</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>Frame_Msg</name>
      <anchor>a12a7</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>SpecialFrame_Msg</name>
      <anchor>a12a8</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>StartReply_Msg</name>
      <anchor>a12a9</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>Credit_Msg</name>
      <anchor>a12a10</anchor>
      <arglist></arglist>
    </member>
    <member kind="enumvalue">
      <name>Fragment_Msg</name>
      <anchor>a12a11</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>flowProtocol::credit</name>
    <filename>structflowProtocol_1_1credit.html</filename>
    <member kind="variable">
      <type>char</type>
      <name>magic_number</name>
      <anchor>m0</anchor>
      <arglist>[4]</arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>cred_num</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>flowProtocol::fragment</name>
    <filename>structflowProtocol_1_1fragment.html</filename>
    <member kind="variable">
      <type>char</type>
      <name>magic_number</name>
      <anchor>m0</anchor>
      <arglist>[4]</arglist>
    </member>
    <member kind="variable">
      <type>octet</type>
      <name>flags</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>frag_number</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>sequence_num</name>
      <anchor>m3</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>frag_sz</name>
      <anchor>m4</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>source_id</name>
      <anchor>m5</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>flowProtocol::frame</name>
    <filename>structflowProtocol_1_1frame.html</filename>
    <member kind="variable">
      <type>unsigned long</type>
      <name>timestamp</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>synchSource</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>my_seq_ulong</type>
      <name>source_ids</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>sequence_num</name>
      <anchor>m3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>flowProtocol::frameHeader</name>
    <filename>structflowProtocol_1_1frameHeader.html</filename>
    <member kind="variable">
      <type>char</type>
      <name>magic_number</name>
      <anchor>m0</anchor>
      <arglist>[4]</arglist>
    </member>
    <member kind="variable">
      <type>octet</type>
      <name>flags</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>octet</type>
      <name>message_type</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>unsigned long</type>
      <name>message_size</name>
      <anchor>m3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>flowProtocol::sequencedFrame</name>
    <filename>structflowProtocol_1_1sequencedFrame.html</filename>
    <member kind="variable">
      <type>unsigned long</type>
      <name>sequence_num</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>flowProtocol::specialFrame</name>
    <filename>structflowProtocol_1_1specialFrame.html</filename>
    <member kind="variable">
      <type>frameID</type>
      <name>context_id</name>
      <anchor>m0</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>sequence&lt; octet &gt;</type>
      <name>context_data</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>flowProtocol::Start</name>
    <filename>structflowProtocol_1_1Start.html</filename>
    <member kind="variable">
      <type>char</type>
      <name>magic_number</name>
      <anchor>m0</anchor>
      <arglist>[4]</arglist>
    </member>
    <member kind="variable">
      <type>octet</type>
      <name>major_version</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>octet</type>
      <name>minor_version</name>
      <anchor>m2</anchor>
      <arglist></arglist>
    </member>
    <member kind="variable">
      <type>octet</type>
      <name>flags</name>
      <anchor>m3</anchor>
      <arglist></arglist>
    </member>
  </compound>
  <compound kind="struct">
    <name>flowProtocol::StartReply</name>
    <filename>structflowProtocol_1_1StartReply.html</filename>
    <member kind="variable">
      <type>char</type>
      <name>magic_number</name>
      <anchor>m0</anchor>
      <arglist>[4]</arglist>
    </member>
    <member kind="variable">
      <type>octet</type>
      <name>flags</name>
      <anchor>m1</anchor>
      <arglist></arglist>
    </member>
  </compound>
</tagfile>
