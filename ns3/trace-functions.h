#ifndef TRACE_FUNCTIONS_H
#define TRACE_FUNCTIONS_H

#include "ns3/core-module.h"
#include "ns3/custom-display.h"
#include "mutex"
#include "ns3/phy-entity.h"
#include "ns3/wifi-mac.h"
#include "ns3/wifi-mac-queue.h"

#define PHYTXBEGIN BLUE
#define PHYTXEND GREEN
#define PHYRXBEGIN CYAN
#define PHYRXEND YELLOW
#define MACTX RED
#define MACRX MAGENTA
#define PHYTXDROP BRIGHT_BLUE
#define PHYRXDROP BRIGHT_GREEN
#define MACTXDROP BRIGHT_RED
#define MACRXDROP BRIGHT_MAGENTA
#define IPV4L3PROTOCOLTX BRIGHT_YELLOW
#define IPV4L3PROTOCOLRX BRIGHT_CYAN
#define TCPSOCKETBASETX CYAN
#define TCPSOCKETBASERX YELLOW

#define UDPSERVERTX BLUE
#define UDPSERVERRX GREEN
#define UDPECHOSERVERTX CYAN
#define UDPECHOSERVERRX YELLOW
#define PACKETSINKRX RED

#define UDPCLIENTTX BLUE
#define UDPCLIENTRX GREEN
#define UDPECHOCLIENTTX CYAN
#define UDPECHOCLIENTRX YELLOW
#define BULKSENDTX RED
#define ONOFFTX MAGENTA

#define MACENQUEUE BLUE
#define MACDEQUEUE GREEN

#define ENQUEUE BRIGHT_BLUE
#define DEQUEUE BRIGHT_GREEN


enum TraceNum {
  PHYTXBEGINENUM,
  PHYTXENDENUM,
  PHYRXBEGINENUM,
  PHYRXENDNUM,
  ONOFFTXNUM,
  BULKSENDTXNUM,
  PACKETSINKRXNUM,
  UDPECHOSERVERTXNUM,
  UDPECHOCLIENTTXNUM,
  UDPSERVERTXNUM,
  UDPSERVERRXNUM,
  UDPCLIENTTXNUM,
  UDPCLIENTRXNUM,
  MACENQUEUENUM,
  MACDEQUEUENUM,
  ENQUEUENUM,
  DEQUEUENUM,
  TCPSOCKETBASETXNUM,
  TCPSOCKETBASERXNUM,
  IPV4L3PROTOCOLTXNUM,
  IPV4L3PROTOCOLRXNUM,
  PHYTXDROPNUM,
  PHYRXDROPNUM,
  MACTXDROPNUM,
  MACRXDROPNUM,
  MACTXNUM,
  MACRXNUM,
};

enum FeatureNum {
  PHYAVERAGE = 80,
  MACAVERAGE,
  APPLICATIONAVERAGE,
  IPV4L3AVERAGE,
  PHYTXDROPCOUNT,
  PHYRXDROPCOUNT,
  PHYDROPCOUNT,
  MACDROPCOUNT,
  TOTALTXCOUNT,
  TOTALRXCOUNT,
  TOTALDROPCOUNT,
};

const char* traceMap[] = {
  "PHYTXBEGINENUM",
  "PHYTXENDENUM",
  "PHYRXBEGINENUM",
  "PHYRXENDNUM",
  "ONOFFTXNUM",
  "BULKSENDTXNUM",
  "PACKETSINKRXNUM",
  "UDPECHOSERVERTXNUM",
  "UDPECHOCLIENTTXNUM",
  "UDPSERVERTXNUM",
  "UDPSERVERRXNUM",
  "UDPCLIENTTXNUM",
  "UDPCLIENTRXNUM",
  "MACENQUEUENUM",
  "MACDEQUEUENUM",
  "ENQUEUENUM",
  "DEQUEUENUM",
  "TCPSOCKETBASETXNUM",
  "TCPSOCKETBASERXNUM",
  "IPV4L3PROTOCOLTXNUM",
  "IPV4L3PROTOCOLRXNUM",
  "PHYTXDROPNUM",
  "PHYRXDROPNUM",
  "MACTXDROPNUM",
  "MACRXDROPNUM",
  "MACTXNUM",
  "MACRXNUM",
};

const char* featureMap[] = {
  "PHYAVERAGE",
  "MACAVERAGE",
  "APPLICATIONAVERAGE",
  "IPV4L3AVERAGE",
  "PHYTXDROPCOUNT",
  "PHYRXDROPCOUNT",
  "PHYDROPCOUNT",
  "MACDROPCOUNT",
  "TOTALTXCOUNT",
  "TOTALRXCOUNT",
  "TOTALDROPCOUNT",
};

using namespace std;

namespace ns3 {

DisplayObject Trace(std::string context, Ptr<const Packet> pkt, std::string color) {
  Time now = Simulator::Now ();
  double t = now.GetNanoSeconds();
  const uint64_t sz = pkt->GetSize();
  const uint64_t uid = pkt->GetUid();
  DisplayObject obj = DisplayObject(context, t, sz, color, uid);
  return obj;
}

void PhyTxBeginTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt, double pow) {
  DisplayObject obj = Trace(context, pkt, BLUE);
  (*objs).push_back(obj);
}

void PhyTxEndTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt) {
  DisplayObject obj = Trace(context, pkt, GREEN);
  (*objs).push_back(obj);
}

void PhyRxBeginTrace (std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt, RxPowerWattPerChannelBand rpw) {
  DisplayObject obj = Trace(context, pkt, CYAN);
  (*objs).push_back(obj);
}

void PhyRxEndTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt) {
  DisplayObject obj = Trace(context, pkt, YELLOW);
  (*objs).push_back(obj);
}

void MacTxTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt) {
  DisplayObject obj = Trace(context, pkt, RED);
  (*objs).push_back(obj);
}

void MacRxTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt) {
  DisplayObject obj = Trace(context, pkt, MAGENTA);
  (*objs).push_back(obj);
}

void PhyTxDropTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt) {
  DisplayObject obj = Trace(context, pkt, BRIGHT_BLUE);
  (*objs).push_back(obj);
}

void PhyRxDropTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt, WifiPhyRxfailureReason wfr) {
  DisplayObject obj = Trace(context, pkt, PHYRXDROP);
  (*objs).push_back(obj);
}

void MacTxDropTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt) {
  DisplayObject obj = Trace(context, pkt, MACTXDROP);
  (*objs).push_back(obj);
}

void MacRxDropTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt) {
  DisplayObject obj = Trace(context, pkt, MACRXDROP);
  (*objs).push_back(obj);
}

void Ipv4L3ProtocolTxTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt, Ptr<Ipv4> ipv4, uint32_t n) {
  DisplayObject obj = Trace(context, pkt, IPV4L3PROTOCOLTX);
  (*objs).push_back(obj);
}

void Ipv4L3ProtocolRxTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt, Ptr<Ipv4> ipv4, uint32_t n) {
  DisplayObject obj = Trace(context, pkt, IPV4L3PROTOCOLRX);
  (*objs).push_back(obj);
}

void TcpSocketBaseTxTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt, const TcpHeader &tcpHeader, Ptr<const TcpSocketBase> tcpSocketBase) {
  DisplayObject obj = Trace(context, pkt, TCPSOCKETBASETX);
  (*objs).push_back(obj);
}

void TcpSocketBaseRxTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt, const TcpHeader &tcpHeader, Ptr<const TcpSocketBase> tcpSocketBase) {
  DisplayObject obj = Trace(context, pkt, TCPSOCKETBASERX);
  (*objs).push_back(obj);
}

void UdpClientTxWithAddressesTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt, const Address& addr1, const Address& addr2) {
  DisplayObject obj = Trace(context, pkt, UDPCLIENTTX);
  (*objs).push_back(obj);
}

void UdpClientRxWithAddressesTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt, const Address& addr1, const Address& addr2) {
  DisplayObject obj = Trace(context, pkt, UDPCLIENTRX);
  (*objs).push_back(obj);
}

void UdpEchoClientTxWithAddressesTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt, const Address& addr1, const Address& addr2) {
  DisplayObject obj = Trace(context, pkt, UDPECHOCLIENTTX);
  (*objs).push_back(obj);
}

void UdpEchoClientRxWithAddressesTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt, const Address& addr1, const Address& addr2) {
  DisplayObject obj = Trace(context, pkt, UDPECHOCLIENTRX);
  (*objs).push_back(obj);
}

void UdpServerRxWithAddressesTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt, const Address& addr1, const Address& addr2) {
  DisplayObject obj = Trace(context, pkt, UDPSERVERRX);
  (*objs).push_back(obj);
}

void UdpEchoServerRxWithAddressesTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt, const Address& addr1, const Address& addr2) {
  DisplayObject obj = Trace(context, pkt, UDPECHOSERVERRX);
  (*objs).push_back(obj);
}

void OnOffApplicationTxWithAddressesTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt, const Address& addr1, const Address& addr2) {
  // std::cout<<"OnOff: "<<addr1<<": "<<addr2<<std::endl;
  DisplayObject obj = Trace(context, pkt, ONOFFTX);
  (*objs).push_back(obj);
}

void BulkSendApplicationTxWithAddressesTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt, const Address& addr1, const Address& addr2) {
  DisplayObject obj = Trace(context, pkt, BULKSENDTX);
  (*objs).push_back(obj);
}

void PacketSinkApplicationTxWithAddressesTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt, const Address& addr1, const Address& addr2) {
  // std::cout<<"packetSink"<<addr1<<": "<<addr2<<"\n\n";
  DisplayObject obj = Trace(context, pkt, PACKETSINKRX);
  (*objs).push_back(obj);
}

void PacketSinkApplicationRxWithAddressesTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt, const Address& addr1, const Address& addr2) {
  // std::cout<<addr1<<": "<<addr2<<"\n\n";
  DisplayObject obj = Trace(context, pkt, PACKETSINKRX);
  (*objs).push_back(obj);
}

void MacEnqueueTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const WifiMacQueueItem> item) {
  Ptr<const Packet> pkt = item->GetPacket();
  DisplayObject obj = Trace(context, pkt, MACENQUEUE);
  (*objs).push_back(obj);
}


void MacDequeueTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const WifiMacQueueItem> item) {
  Ptr<const Packet> pkt = item->GetPacket();
  DisplayObject obj = Trace(context, pkt, MACDEQUEUE);
  (*objs).push_back(obj);
}

void EnqueueTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt) {
  DisplayObject obj = Trace(context, pkt, ENQUEUE);
  (*objs).push_back(obj);
}


void DequeueTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt) {
  DisplayObject obj = Trace(context, pkt, DEQUEUE);
  (*objs).push_back(obj);
}

bool tmcmp(std::pair<std::string, double> &a, std::pair<std::string, double> &b) {
  return a.second < b.second;
}

bool cmp(std::pair<int,int>&a, std::pair<int,int> &b) {
  return a.first < b.first;
}

// void getOutput(vector<vector<DisplayObject>*> objGrid, FILE* fp, int sender, int reciever) {
//   int numpacketsSent = objGrid[sender]->size();
//   int numpacketsRecieved = objGrid[reciever]->size();
//   int numpacketsDropped = numpacketsSent - numpacketsRecieved;
//   int phycnt = 0;
//   int ipv4cnt = 0;
//   int maccnt = 0;
//   int appcnt = 0;
//   int enqueDequecnt = 0;
//   double phyavg = 0;
//   double macavg = 0;
//   double ipv4avg = 0;
//   double appavg = 0;
//   double enqueDequeavg = 0;
//   // create a map
//   std::map<int,std::vector<double>> mp;
//   int n = objGrid.size();

//   for(auto &obj: *(objGrid[sender])) {
//     if (mp.find(obj.getUid()) == mp.end()) {
//       mp[obj.getUid()] = std::vector<double>(n);
//     }
//   }

//   for(int i=0;i<n;i++) {
//     for(auto &obj: *(objGrid[i])) {
//       if (mp.find(obj.getUid()) == mp.end()) continue;
//       mp[obj.getUid()][i] = obj.getTime();
//     }
//   }

//   for(auto x:mp) {
//     if (x.second[PHYTXBEGINENUM] > 0 && x.second[PHYRXENDNUM] > 0) {
//       phyavg += (x.second[PHYRXENDNUM] - x.second[PHYTXBEGINENUM]);
//       phycnt++;
//     }
//     if (x.second[IPV4L3PROTOCOLTXNUM] > 0 && x.second[IPV4L3PROTOCOLRXNUM] > 0) {
//       ipv4avg += (x.second[IPV4L3PROTOCOLRXNUM] - x.second[IPV4L3PROTOCOLTXNUM]);
//       ipv4cnt++;
//     }
//     if (x.second[MACTXNUM] > 0 && x.second[MACRXNUM] > 0) {
//       macavg += (x.second[MACRXNUM] - x.second[MACTXNUM]);
//       maccnt++;
//     }
//     if (x.second[sender] > 0 && x.second[reciever] > 0) {
//       appavg += (x.second[reciever] - x.second[sender]);
//       appcnt++;
//     }
//     if (x.second[MACENQUEUENUM] > 0 && x.second[MACDEQUEUENUM] > 0) {
//       enqueDequeavg += (x.second[MACDEQUEUENUM] - x.second[MACENQUEUENUM]);
//       enqueDequecnt++;
//     }
//   }

//   enqueDequeavg /= enqueDequecnt;
//   macavg /= maccnt;
//   phyavg /= phycnt;
//   ipv4avg /= ipv4cnt;
//   appavg /= appcnt;

//   cout<<"Total Transmitted packets: "<<numpacketsSent<<endl;
//   cout<<"Total Received packets: "<<numpacketsRecieved<<endl;
//   cout<<"Total Dropped packets: "<<numpacketsDropped<<endl;

//   cout<<"AppAvg: "<<appavg<<endl;
//   cout<<"Ipv4Avg: "<<ipv4avg<<endl;
//   cout<<"EnqueDequeAvg: "<<enqueDequeavg<<endl;
//   cout<<"MacAvg: "<<macavg<<endl;
//   cout<<"phyAvg : "<<phyavg<<endl;
// }

void getTimeTrace(std::vector<std::vector<DisplayObject>*> objGrid, int clr, FILE* fp=NULL) {
  std::map<int, std::vector<std::pair<std::string,double>>> mp;
  int n = objGrid.size();

  for(auto &obj: *(objGrid[clr])) {
    if (mp.find(obj.getUid()) == mp.end()) {
      mp[obj.getUid()] = std::vector<std::pair<std::string,double>>(n,std::make_pair("",0));
    }
  }

  for(int i=0;i<n;i++) {
    for(auto &obj: *(objGrid[i])) {
      if (mp.find(obj.getUid()) == mp.end()) continue;
      mp[obj.getUid()][i] = std::make_pair(obj.getName(), obj.getTime());
    }
  }

  for(auto x:mp) {
    std::cout<<std::setprecision(15)<<"Uid: "<<x.first<<std::endl;
    std::vector<std::pair<int,int>> temp(n);
    for(int i=0;i<n;i++) temp[i] = std::make_pair(x.second[i].second, i);
    sort(temp.begin(),temp.end(),cmp);
    for(int i=0;i<n;i++) {
      if (temp[i].first == 0) continue;
      std::cout<<std::setprecision(15)<<traceMap[temp[i].second]<<": "<<temp[i].first<<std::endl;
      // std::cout<<std::setprecision(15)<<traceMap[temp[i].second]<<": "<<temp[i].first<<": "<<x.second[temp[i].second].first<<std::endl;
    }
  }

  fclose(fp);
}

template<class T> void prettyPrint(std::vector<T>& v) { for (T x : v) {std::cout<<x<<std::endl;} }
template<class T, class V> void prettyPrint(std::pair<T,V> &p) {std::cout<<"first: "<<p.first<<"\nsecond: "<<p.second<<std::endl;}
template<class T, class V> void prettyPrint(std::map<T,V>& m) {for(auto x: m) {std::cout<<"key: "<<x.first<<"\nvalue: "<<x.second<<std::endl;}}
}
#endif
