#include <sstream>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"
#include "stack.h"
#include <signal.h>

Basavaraj process;

volatile sig_atomic_t stop;

void inthand(int signum) {
    process.ProcessTeardown();
    stop = 1;
    exit(signum);
}


int main(int argc, char **argv)
{
  signal(SIGINT, inthand);
  process.Initialize();
  process.PublisherSetup();
  process.SubscriberSetup();
  ros::Rate loop_rate(10);

  while (ros::ok())
  {

    process.CallSuscribers();
    process.CallPublisher();
    loop_rate.sleep();
    ros::spinOnce();


  }

  
  return EXIT_SUCCESS;
}