#include "Roadmap/roadmap.h"

using namespace std;

int main(){
	point_list* a = initialize_point_list();
	for (int i=0; i<5; i++){
		add_node(a, i/2, i/5);
	};
    points_map test_map;
	test_map.set_robot_position(11.3, 22.4);
	test_map.print_info();
	return 0;
};
