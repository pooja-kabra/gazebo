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

#ifndef INCLUDE_WALKER_WALKER_HPP_
#define INCLUDE_WALKER_HPP_

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>
#include <iostream>

class Walker{
 private:
    ros::Publisher publish;
    geometry_msgs::Twist twist;
    ros::Subscriber laser_sub;
 public:
    explicit Walker(ros::NodeHandle n);
    void callBackLaser(const sensor_msgs::LaserScan::ConstPtr &scan);
};


#endif  // WALKER_SRC_WALKER_INCLUDE_WALKER_HPP
