#ifndef DIFFDRIVE_ARDUINO_ARDUINO_COMMS_H
#define DIFFDRIVE_ARDUINO_ARDUINO_COMMS_H

#include <vector>
#include <cstring>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"
#include "v5_hal/msg/v5_motor.hpp"

class ArduinoComms : public rclcpp::Node
{
  public:
    ArduinoComms();
    float l_encoder_val_ = 0;
    float r_encoder_val_ = 0;
    void l_topic_callback(const v5_hal::msg::V5Motor &msg)
    {
      l_encoder_val_ = msg.position;
    }
    void r_topic_callback(const v5_hal::msg::V5Motor &msg)
    {
      r_encoder_val_ = msg.position;
    }
    void setup();
    void readEncoderValues(int &val_1, int &val_2);
    void setMotorValues(float val_1, float val_2);
    void setPidValues(float k_p, float k_d, float k_i, float k_o);

    bool connected() const { return true; }

    /*std::string sendMsg(const std::string &msg_to_send, bool print_output = false);*/

  private:
    const std::string prefix_ = "/motor/";
    const std::string postfix_ = "/vel";
    std::vector<std::string> l_topic_names_ { "leftFrontTopMotor", "leftFrontBottomMotor", "leftRearTopMotor", "leftRearBottomMotor" };
    std::vector<std::string> r_topic_names_ { "rightFrontTopMotor", "rightFrontBottomMotor", "rightRearTopMotor", "rightRearBottomMotor" };
    rclcpp::Subscription<v5_hal::msg::V5Motor>::SharedPtr l_subscriber_;
    rclcpp::Subscription<v5_hal::msg::V5Motor>::SharedPtr r_subscriber_;
    std::vector<rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr> l_publishers_;
    std::vector<rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr> r_publishers_;
};

#endif // DIFFDRIVE_ARDUINO_ARDUINO_COMMS_H
