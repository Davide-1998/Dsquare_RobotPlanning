#include "roadmap.h"
#include <iostream>
#include <stdio.h>


void points_map::add_arena_points(point_list ArenaPoints){
	*arena = ArenaPoints;
};

void points_map::set_robot_position(double x, double y){
  robot = new(Robot);
  robot -> x = x;
  printf("%0.2f", robot -> x);
  robot -> y = y;
  return;
};

void points_map::print_info(){
  printf("Robot location: %0.4f - %0.4f\n", robot->x, robot->y);
};
