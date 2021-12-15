#ifndef __DUBINS_H__
#define __DUBINS_H__

#include <iostream>
#include <tuple>
#include <cmath>
#include <string>
#include <assert.h>
#include <opencv2/opencv.hpp>
#include "../Dubins/clipper/clipper.hpp"

/*
 * Compile command:
  g++ prova.cpp `pkg-config opencv --cflags --libs` 
*/

using namespace cv;
using namespace std;

struct double_node{
	double value;
	double_node *pnext;
}typedef double_node;

struct double_list{
	double_node *head;
	double_node *tail;
	int size;
}typedef double_list;

struct point_node{
	double x;
	double y;
	point_node *pnext;
}typedef point_node;

struct point_list{
	point_node *head;
	point_node *tail;
	int size;
	
}typedef point_list;

struct arc{
	double x0, y0, th0, k, L, xf, yf, thf;
}typedef arc;

struct curve{
	arc a1,a2,a3;
	double L;
}typedef curve;

tuple <int, curve> dubins(double, double, double, double, double, double, double);
arc dubinsarc(double, double, double, double, double);
curve dubinscurve(double, double, double, double, double, double, double, double, double);
double sinc(double);
double mod2pi(double);
double rangeSymm(double);
bool check(double, double, double, double, double, double, double, double);
tuple <double, double, double, double> scaleToStandard(double, double, double, double, double, double, double);
tuple <double, double, double> scaleFromStandard(double, double, double, double);
tuple <bool, double, double, double> LSL(double, double, double);
tuple <bool, double, double, double> RSR(double, double, double);
tuple <bool, double, double, double> LSR(double, double, double);
tuple <bool, double, double, double> RSL(double, double, double);
tuple <bool, double, double, double> RLR(double, double, double);
tuple <bool, double, double, double> LRL(double, double, double);
tuple <double, double, double> circline(double, double, double, double, double);
Mat plotarc(arc, string, Mat);
Mat plotdubins(curve, string, string, string, Mat );
void python_plot(curve, string, string, string);
tuple <point_list *, double_list *> intersLineLine(double, double, double, double, double, double, double, double);
double cross2D(double *, double *);
double dot2D(double *, double *);
tuple <point_list *, double_list *> intersCircleLine(double, double, double, double, double, double, double);
Mat plot_points(point_list *,Mat,Scalar,bool);

/*Support function*/
double_list * initialize_double_list();
point_list * initialize_point_list();
void add_node(double_list *, double);
void add_node(point_list *, double, double);
void delete_list(double_list *);
void delete_list(point_list *);
void print_list(double_list *);
void print_list(point_list *);
void sort(double_list *, point_list *);

#endif
