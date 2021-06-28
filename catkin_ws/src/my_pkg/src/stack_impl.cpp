#include "stack.h"
#define SUCCESS_RETURN_CODE 0
#define ERROR_RETURN_CODE -1

#define ROS_HISTORY_DEPTH 10

Basavaraj::Basavaraj(){}

int32_t Basavaraj::Initialize(){
  printf("Initialize()\n");
  fflush(stdout);

  // Start roscore in our container (must be done before ros::init())
  roscore_process_.reset(new subprocess::Popen("roscore"));

  // Initialize ROS
  int argc = 0;
  char **argv = NULL;
  ros::init(argc, argv, "stack", ros::init_options::NoSigintHandler);
  node_.reset(new ros::NodeHandle());
  spinner_.reset(new ros::AsyncSpinner(4));
  spinner_->start();


  return SUCCESS_RETURN_CODE;
}

int32_t setup(){
	return SUCCESS_RETURN_CODE;
}

int32_t Basavaraj::PublisherSetup(){
	    stack_version_publisher_ = node_->advertise<std_msgs::String>(
        kStackVersionTopic, ROS_HISTORY_DEPTH);
	return SUCCESS_RETURN_CODE;
}

int32_t Basavaraj::SubscriberSetup(){
	

	return SUCCESS_RETURN_CODE;
}

int32_t Basavaraj::CallSuscribers(){
	return SUCCESS_RETURN_CODE;
}

int32_t Basavaraj::CallPublisher(){
  stack_version_.data = "asd";
	stack_version_publisher_.publish(stack_version_);
	return SUCCESS_RETURN_CODE;
}

int32_t Basavaraj::KillPublisher(){

	return SUCCESS_RETURN_CODE;
}


int32_t SetRate(){

	return SUCCESS_RETURN_CODE;
}




// kill roscore, rosnode
int32_t Basavaraj::ProcessTeardown() {
  printf("Process killed..()\n");
  fflush(stdout);

  spinner_->stop();
  ros::shutdown();

  // Stop roscore using SIGINT (Ctrl-C)
  roscore_process_->kill(2);

  return SUCCESS_RETURN_CODE;
}

//implementation






