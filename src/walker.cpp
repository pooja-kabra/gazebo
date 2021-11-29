/**
 * @file walker.hpp : This is a header file which initialises Walker class to
 * avoid global variable while publishing
 * @author Pooja Kabra
 * @brief
 * @version 0.1
 * @date 2021-11-28
 * @copyright Copyright (c) 2021
 * @license MIT License
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 *
 */

#include <ros/ros.h>
#include <vector>
#include <walker/walker.hpp>


Walker::Walker() {
    twist.linear.x = 0;
    twist.linear.y = 0;
    twist.linear.z = 0;
}

Walker::~Walker() {}

void Walker::intialize(ros::NodeHandle n) {
    walk_publish = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
    laser_sub = n.subscribe("/scan", 10, &Walker::callBackLaser, this);
    walk_publish.publish(twist);
}

void Walker::callBackLaser(const sensor_msgs::LaserScan::ConstPtr  &scan) {
    if (scan->ranges[0] < 0.5 || scan->ranges[335] < 0.5 || scan->ranges[25] < 0.5) {
        twist.angular.z = 0.6;
        twist.linear.x = 0;
        walk_publish.publish(twist);
    } else {
        twist.linear.z = 0;
        twist.linear.x = 0.4;
        walk_publish.publish(twist);
    }
}
