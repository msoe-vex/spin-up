#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int8.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
 * member function as a callback from the timer. */

class MotorTest : public rclcpp::Node
{
public:
    MotorTest()
        : Node("motor_test"), count_(0)
    {
        publisher_ = this->create_publisher<std_msgs::msg::Int8>("/motor/intakeMotor/moveMotorVoltage", 10);
        timer_ = this->create_wall_timer(
            500ms, std::bind(&MotorTest::timer_callback, this));
    }

private:
    void timer_callback()
    {
        auto message = std_msgs::msg::Int8();
        message.data = 127;
        RCLCPP_INFO(this->get_logger(), "Publishing: '%d'", message.data);
        publisher_->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::Int8>::SharedPtr publisher_;
    size_t count_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MotorTest>());
    rclcpp::shutdown();
    return 0;
}