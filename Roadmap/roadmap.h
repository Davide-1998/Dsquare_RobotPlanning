#ifndef __ROADMAP_H__
#define __ROADMAP_H__

#include "../Dubins/dubins.h"

typedef struct Robot{
	char *ID = NULL;
	double x;
	double y;
	double max_curvature_angle;
} Robot;

typedef struct list_of_obstacles {
  point_list *obstacle = NULL;
  point_list *next = NULL;
} list_of_obstacles;

typedef struct points_map {
  // Lists of points belonging respectively to the arena and the obstacles
  // Supposed that the points are in clockwise or counterclockwise order
  point_list *arena = NULL;
  list_of_obstacles *obstacles = NULL;

  Robot *robot = NULL;
  point_node *goal_point = NULL;
  
  void add_arena_points(point_list ArenaPoints);
  void set_robot_position(double x, double y);
  void print_info();
  // void ~points_map();
} points_map;

#endif
