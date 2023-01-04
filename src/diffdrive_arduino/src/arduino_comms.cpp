#include "diffdrive_arduino/arduino_comms.h"

#include <cstdlib>
#include <sstream>

// #include <ros/console.h>
void ArduinoComms::setup() {
  for (auto topic_name : l_topic_names_) {
    l_publishers_.push_back(this->create_publisher<std_msgs::msg::Float32>(
        prefix_ + topic_name + postfix_, 10));
  }

  for (auto topic_name : r_topic_names_) {
    r_publishers_.push_back(this->create_publisher<std_msgs::msg::Float32>(
        prefix_ + topic_name + postfix_, 10));
  }
  l_subscriber_ = this->create_subscription<v5_hal::msg::V5Motor>(
      prefix_ + l_topic_names_.front(), 10,
      std::bind(&ArduinoComms::l_topic_callback, this, std::placeholders::_1));
  r_subscriber_ = this->create_subscription<v5_hal::msg::V5Motor>(
      prefix_ + r_topic_names_.front(), 10,
      std::bind(&ArduinoComms::r_topic_callback, this, std::placeholders::_1));
}

void ArduinoComms::readEncoderValues(int& val_1, int& val_2) {
  val_1 = l_encoder_val_;
  val_2 = r_encoder_val_;
}

void ArduinoComms::setMotorValues(float val_1, float val_2) {
  for (auto pub : l_publishers_) {
    auto message = std_msgs::msg::Float32();
    message.data = val_1;
    pub->publish(message);
  }
  for (auto pub : r_publishers_) {
    auto message = std_msgs::msg::Float32();
    message.data = val_2;
    pub->publish(message);
  }
}

void ArduinoComms::setPidValues(float k_p, float k_d, float k_i, float k_o) {}

/*std::string ArduinoComms::sendMsg(const std::string &msg_to_send, bool
print_output)
{
    serial_conn_.write(msg_to_send);
    std::string response = serial_conn_.readline();

    if (print_output)
    {
        // RCLCPP_INFO_STREAM(logger_,"Sent: " << msg_to_send);
        // RCLCPP_INFO_STREAM(logger_,"Received: " << response);
    }

    return response;
}*/
