#ifndef __ROADMAP_H__
#define __ROADMAP_H__

#include "../Dubins/dubins.h"
#include <iostream>
#include <stdio.h>

typedef struct Robot{
	char *ID = NULL;
	double x;
	double y;
	double max_curvature_angle;

	Robot(){
		x = 0.0;
		y = 0.0;
	}
} Robot;

typedef struct obstacle{
	point_list *pl;
	obstacle *pnext = NULL;
	obstacle(point_list* pls){
		pl = pls;
	}
}obstacle;

typedef struct list_of_obstacles {
  obstacle *head = NULL;
  obstacle *tail = NULL;
}list_of_obstacles;

typedef struct points_map {
  // Lists of points belonging respectively to the arena and the obstacles
  // Supposed that the points are in clockwise or counterclockwise order
  point_list *arena = NULL;
  list_of_obstacles *obstacles = new list_of_obstacles;

  Robot *robot = NULL;
  point_node *goal_point = NULL;
  
  void add_arena_points(point_list *ArenaPoints);
  void set_robot_position(double x, double y);
  void add_obstacle(obstacle* ob);
  void print_info();
  Mat plot_arena();
  // void ~points_map();
} points_map;

#endif
