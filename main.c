/*
** EPITECH PROJECT, 2018
** 104intersection
** File description:
** main.c
*/

#include "include/my.h"

static void print_help(void)
{
    printf("USAGE\n");
    printf("\t./104intersection opt xp yp zp xv yv zv p\n");
    printf("\nDESCRIPTION\n");
    printf("\topt\t\tsurface option: 1 for sphere, 2 for cylinder, 3 for a cone\n");
    printf("\t(xp, yp, zp)\tcoordinates of a point by which the light ray passes through\n");
    printf("\t(xv, yv, zv)\tcoordinates of a vector parallel to the light ray\n");
    printf("\tp\t\tparameter: radius of the sphere, radius of the cylinder, or\n");
    printf("\t\t\tangle formed by the cone and the Z-axis\n");
}

void sphere(double opt, double xp, double yp, double zp, double xv, double yv, double zv, double p)
{
	double a = pow(xv, 2) + pow(yv, 2) + pow(zv, 2);
	double b = (2 * (xp * xv)) + (2 * (yp * yv)) + (2 * (zp * zv));
	double c = pow(xp, 2) + pow(yp, 2) + pow(zp, 2) - pow(p, 2);
	double d = pow(b, 2) - (4 * a * c);
	double x1;
	double x2;

	if (d > 0) {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        printf("2 intersection points:\n");
        printf("(%.3f, %.3f, %.3f)\n", xp + x1 * xv, yp + x1 * yv, zp + x1 * zv);
        printf("(%.3f, %.3f, %.3f)\n", xp + x2 * xv, yp + x2 * yv, zp + x2 * zv);
    } else if (d == 0) {
    	x1 = -b / (2 * a);
    	printf("1 intersection point:\n");
    	printf("(%.3f, %.3f, %.3f)\n", xp + x1 * xv, yp + x1 * yv, zp + x1 * zv);
    } else {
    	printf("No intersection point.\n");
    }
}

void cylinder(double opt, double xp, double yp, double zp, double xv, double yv, double zv, double p)
{
	double a = pow(xv, 2) + pow(yv, 2);
	double b = (2 * xp * xv) + (2 * yp * yv);
	double c = pow(xp, 2) + pow(yp, 2) - pow(p, 2);
	double d = pow(b, 2) - (4 * a * c);
	double x1;
	double x2;

	if (xp == 0 && yp == 0 && xv == 0 && yv == 0) {
		if (zp == p)
			printf("There is an infinite number of intersection points.\n");
		else
			printf("No intersection point.\n");
	}
	else if (d > 0) {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        printf("2 intersection points:\n");
        printf("(%.3f, %.3f, %.3f)\n", xp + x1 * xv, yp + x1 * yv, zp + x1 * zv);
        printf("(%.3f, %.3f, %.3f)\n", xp + x2 * xv, yp + x2 * yv, zp + x2 * zv);
    } else if (d == 0) {
    	x1 = -b / (2 * a);
    	printf("1 intersection point:\n");
    	printf("(%.3f, %.3f, %.3f)\n", xp + x1 * xv, yp + x1 * yv, zp + x1 * zv);
    } else {
    	printf("No intersection point.\n");
    }
}

void cone(double opt, double xp, double yp, double zp, double xv, double yv, double zv, double p)
{
	double angle = p / 180 / M_PI;
	double a = pow(xv, 2) + pow(yv, 2) - (pow(zv, 2) / pow(tan(angle), 2));
	double b = (2 * xp * xv) + (2 * yp * yv) - (2 * zp * zv / pow(tan(angle), 2));
	double c = pow(xp, 2) + pow(yp, 2) - (pow(zp, 2) / pow(tan(angle), 2));
	double d = pow(b, 2) - (4 * a * c);
	double x1;
	double x2;

	if (d > 0) {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);
        printf("2 intersection points:\n");
        printf("(%.3f, %.3f, %.3f)\n", xp + x1 * xv, yp + x1 * yv, zp + x1 * zv);
        printf("(%.3f, %.3f, %.3f)\n", xp + x2 * xv, yp + x2 * yv, zp + x2 * zv);
    } else if (d == 0) {
    	x1 = -b / (2 * a);
    	printf("1 intersection point:\n");
    	printf("(%.3f, %.3f, %.3f)\n", xp + x1 * xv, yp + x1 * yv, zp + x1 * zv);
    } else {
    	printf("No intersection point.\n");
    }
}

int check_param(char **argv)
{
	for (int i = 1; i < 9; i++)
		if ((argv[i][0] < '0' || argv[i][0] > '9') && argv[i][0] != '-')
			return (84);
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 9) {
        if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h' && argv[1][2] == '\0') {
            print_help();
            return (0);
        }
		return (84);
    }
	if (check_param(argv) == 84)
		return (84);
	double opt = atof(argv[1]);
	double xp = atof(argv[2]);
	double yp = atof(argv[3]);
	double zp = atof(argv[4]);
	double xv = atof(argv[5]);
	double yv = atof(argv[6]);
	double zv = atof(argv[7]);
	double p = atof(argv[8]);

	if (opt == 1)
		printf("Sphere of radius %.f\n", p);
	if (opt == 2)
		printf("Cylinder of radius %.f\n", p);
	if (opt == 3)
		printf("Cone with a %.f degree angle\n", p);
	printf("Line passing through the point (%.f, %.f, %.f) and parallel to the vector (%.f, %.f, %.f)\n", xp, yp, zp, xv, yv, zv);
	if (opt == 1)
		sphere(opt, xp, yp, zp, xv, yv, zv, p);
	if (opt == 2)
		cylinder(opt, xp, yp, zp, xv, yv, zv, p);
	if (opt == 3)
		cone(opt, xp , yp, zp, xv, yv, zv, p);
	return (0);
}