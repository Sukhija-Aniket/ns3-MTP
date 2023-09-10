#ifdef NS3_MODULE_COMPILATION 
    error "Do not include ns3 module aggregator headers from other modules these are meant only for end user scripts." 
#endif 
#ifndef NS3_MODULE_WAVE
    // Module headers: 
    #include <ns3/wave-bsm-helper.h>
    #include <ns3/wave-bsm-stats.h>
    #include <ns3/wave-helper.h>
    #include <ns3/wave-mac-helper.h>
    #include <ns3/wifi-80211p-helper.h>
    #include <ns3/bsm-application.h>
    #include <ns3/channel-coordinator.h>
    #include <ns3/channel-manager.h>
    #include <ns3/channel-scheduler.h>
    #include <ns3/default-channel-scheduler.h>
    #include <ns3/higher-tx-tag.h>
    #include <ns3/ocb-wifi-mac.h>
    #include <ns3/vendor-specific-action.h>
    #include <ns3/vsa-manager.h>
    #include <ns3/wave-frame-exchange-manager.h>
    #include <ns3/wave-net-device.h>
#endif 