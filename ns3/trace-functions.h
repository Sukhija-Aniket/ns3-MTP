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
  DisplayObject obj = Trace(context, pkt, ONOFFTX);
  (*objs).push_back(obj);
}

void BulkSendApplicationTxWithAddressesTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt, const Address& addr1, const Address& addr2) {
  DisplayObject obj = Trace(context, pkt, BULKSENDTX);
  (*objs).push_back(obj);
}

void PacketSinkApplicationTxWithAddressesTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const Packet> pkt, const Address& addr1, const Address& addr2) {
  DisplayObject obj = Trace(context, pkt, PACKETSINKRX);
  (*objs).push_back(obj);
}

void MacEnqueueTrace(std::vector<DisplayObject> *objs, std::string context, Ptr<const WifiMacQueueItem> item) {
  Ptr<const Packet> pkt = item->GetPacket();
  DisplayObject obj = Trace(context, pkt, PACKETSINKRX);
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

void getTimeTrace(std::vector<std::vector<DisplayObject>*> objGrid, FILE* fp=NULL) {

  uint32_t n = objGrid.size();
  std::map<int, std::vector<double>> mp;

  for(auto &obj: *(objGrid[0])) {
    if (mp.find(obj.getUid()) == mp.end()) {
      mp[obj.getUid()] = std::vector<double>();
    }
  }

  for(auto &objContainer: objGrid) {
    for(auto &obj: *objContainer) {
      if (mp.find(obj.getUid()) == mp.end()) continue;
      mp[obj.getUid()].push_back(obj.getTime());
    }
  }
  for(auto x:mp) {
    std::cout<<std::setprecision(15)<<"Uid: "<<x.first<<std::endl;
    for(uint32_t i=0;i<n;i++) {
      std::cout<<std::setprecision(15)<<"T"<<i<<": "<<x.second[i]<<std::endl;
    }
  }
  fclose(fp);
}

template<class T> void prettyPrint(std::vector<T>& v) { for (T x : v) {std::cout<<x<<std::endl;} }
template<class T, class V> void prettyPrint(std::pair<T,V> &p) {std::cout<<"first: "<<p.first<<"\nsecond: "<<p.second<<std::endl;}
template<class T, class V> void prettyPrint(std::map<T,V>& m) {for(auto x: m) {std::cout<<"key: "<<x.first<<"\nvalue: "<<x.second<<std::endl;}}
}
#endif
