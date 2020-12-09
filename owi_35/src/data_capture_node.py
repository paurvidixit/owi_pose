#! /usr/bin/env python
import rospy
import cv2
from cv_bridge import CvBridge, CvBridgeError
from sensor_msgs.msg import Image
bridge = CvBridge()

def callback(msg):
    print("recieved img")
    try:
        # Convert your ROS Image message to OpenCV2
        cv2_img = bridge.imgmsg_to_cv2(msg, "bgr8")
    except CvBridgeError, e:
        print(e)
    else:
        # Save your OpenCV2 image as a jpeg 
        cv2.imwrite('camera_image.jpeg', cv2_img)
if __name__ == '__main__':
   rospy.init_node('node_name')
   
   # sub_cam_info = rospy.Subscriber('/camera/rgb/raw_camera_info', CameraInfo)
   sub_rgb = rospy.Subscriber('/camera_on_stand/rgb/image_raw', Image,callback)
   rospy.spin()