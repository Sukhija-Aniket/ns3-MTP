#ifndef CUSTOM_DISPLAY_H
#define CUSTOM_DISPLAY_H

#include <iostream>
#include<iomanip>

#define RESET           "\033[0m"
#define RED             "\033[31m"
#define GREEN           "\033[32m"
#define YELLOW          "\033[33m"
#define BLUE            "\033[34m"
#define MAGENTA         "\033[35m"
#define CYAN            "\033[36m"
#define BRIGHT_RED      "\033[91m"
#define BRIGHT_GREEN    "\033[92m"
#define BRIGHT_YELLOW   "\033[93m"
#define BRIGHT_BLUE     "\033[94m"
#define BRIGHT_MAGENTA  "\033[95m"
#define BRIGHT_CYAN     "\033[96m"


namespace ns3 {

class DisplayObject
{

private:
  std::string name;
  double time;
  uint64_t packetSize;
  std::string color;
  uint64_t uid;

public:
  DisplayObject(std::string context, double t, uint64_t psz, uint64_t id) {
    uid = id;
    name = context;
    time = t;
    packetSize = psz;
    color = RESET;
  }

  DisplayObject(std::string context, double t, uint64_t psz, std::string clr, uint64_t id) {
    uid = id;
    name = context;
    time = t;
    packetSize = psz;
    color = clr;
  }

  bool operator==(const DisplayObject& other) const {
      // Compare the relevant members for equality
      return (name == other.name && time == other.time && packetSize == other.packetSize && color == other.color && uid == other.uid);
  }

  std::string getName(void) const {
    return name;
  }

  double getTime(void) const {
    return time;
  }
  uint64_t getPacketSize(void) const {
    return packetSize;
  }
  std::string getColor(void) const {
    return color;
  }
  std::uint64_t getUid(void) const {
    return uid;
  }
};

std::ostream& operator<<(std::ostream& os, const DisplayObject& obj) {
  return os <<std::setprecision(60)<<obj.getColor()<<obj.getName()<<"Uid: "<<obj.getUid()<<": Time="<<obj.getTime()<<" PacketSize="<<obj.getPacketSize()<<RESET;
}

}

#endif
