#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <vector>

using namespace std;

struct xyz
{
    double x, y, z;
};

int main()
{
    ofstream config;
    config.open("config_fcc8.dat");
    const double ratio = 8;
    config << "Lammps data file for initial configuration" << endl << endl;
    const double pi=3.1415926536;

    const double big_d = 10;
    const double small_d = 2;
    const int big_c = -48;
    const int small_c = 6;

    const int num_lattice = 4;
    const int a_prime = 20;
    const int a = a_prime*2;
    const double size = num_lattice*a;
    const double size2 = size - small_d*2;

    const int num_per_cell = 4;
    const int num_big = num_per_cell*num_lattice*num_lattice*num_lattice;
//    const int ratio = 8;
    const int num_small = num_big * ratio;
    const int length = 100*num_lattice/6;
//    const int num_salt = 10;//int(0.0265*(length*length*length-pi/6.*(big_d*big_d*big_d*num_big+small_d*small_d*small_d*num_small)));
//    const int num_Cl = num_big*big_c+num_small*small_c;
//    const int num_Na = num_salt;
    
    //config << num_atoms << " atoms" << endl;
    //config << num_bodies << " molecules" << endl;
    config << num_big + num_small<< " atoms" << endl << endl;
    config << "2 atom types" << endl << endl;
    config << -size/2 << '\t' << size/2 << " xlo xhi" << endl;
    config << -size/2 << '\t' << size/2 << " ylo yhi" << endl;
    config << -size/2 << '\t' << size/2 << " zlo zhi" << endl;
    config << endl;

    config << "Masses" << endl << endl;
    config << 1 << '\t' << 25 << endl;
    config << 2 << '\t' << 0.2 << endl;
//    config << 3 << '\t' << 0.2 << endl;
//    config << 4 << '\t' << 0.2 << endl;
//    config << 5 << '\t' << 0.2 << endl;
//    config << 6 << '\t' << 0.2 << endl;

    double x, y, z; //, w0, qx, qy, qz;

    config << "Atoms" << endl << endl;
    int count = 1;
    //Large nanoparticles
    for (int i = 0; i<num_lattice; i++)
        for (int j=0; j<num_lattice; j++)
            for (int k=0; k<num_lattice; k++) {
                x=0+i*a; y=0+j*a;z=0+k*a;
                config << count << '\t' << count << '\t' << 1 << '\t' << big_c << '\t' << x-size/2 << '\t' << y-size/2 << '\t' << z-size/2 << endl;
                count++;
                x=(0.5+i)*a; y=(0.5+j)*a;z=0+k*a;
                config << count << '\t' << count << '\t' << 1 << '\t' << big_c << '\t' << x-size/2 << '\t' << y-size/2 << '\t' << z-size/2 << endl;
                count++;
                x=(0.5+i)*a; y=0+j*a;z=(0.5+k)*a;
                config << count << '\t' << count << '\t' << 1 << '\t' << big_c << '\t' << x-size/2 << '\t' << y-size/2 << '\t' << z-size/2 << endl;
                count++;
                x=0+i*a; y=(0.5+j)*a;z=(0.5+k)*a;
                config << count << '\t' << count << '\t' << 1 << '\t' << big_c << '\t' << x-size/2 << '\t' << y-size/2 << '\t' << z-size/2 << endl;
                count++;
            }
    //Small NPs
    for (int i = 1; i <= num_small; i++)
    {
        x=double(rand())/double(RAND_MAX)*size2;
        double tmp = x - int(x/a)*a;
        while (tmp<big_d/2.0 || tmp>(a-big_d/2.0)) { x=double(rand())/double(RAND_MAX)*size2; tmp = x - int(x/a)*a; }
        y=double(rand())/double(RAND_MAX)*size2;
        tmp = y - int(y/a)*a;
        while (tmp<big_d/2.0 || tmp>(a-big_d/2.0)) { y=double(rand())/double(RAND_MAX)*size2; tmp = y - int(y/a)*a; }
        z=double(rand())/double(RAND_MAX)*size2;
        tmp = z - int(z/a)*a;
        while (tmp<big_d/2.0 || tmp>(a-big_d/2.0)) { z=double(rand())/double(RAND_MAX)*size2; tmp = z - int(z/a)*a; }
        config << count << '\t' << count << '\t' << 2 << '\t' << small_c << '\t' << x-size/2 << '\t' << y-size/2 << '\t' << z-size/2 << endl;
        count++;
    }
}
//    x=double(rand())/double(RAND_MAX)*size2;
//    double tmp = x - int(x/a)*a;

//    y=double(rand())/double(RAND_MAX)*size2;
//   tmp = y - int(y/a)*a;
//    while (tmp<big_d/2.0 || tmp>(a-big_d/2.0)) { y=double(rand())/double(RAND_MAX)*size2; tmp = y - int(y/a)*a; }
//    z=double(rand())/double(RAND_MAX)*size2;
//    tmp = z - int(z/a)*a;
//   while (tmp<big_d/2.0 || tmp>(a-big_d/2.0)) { z=double(rand())/double(RAND_MAX)*size2; tmp = z - int(z/a)*a; }
//    config << count << '\t' << count << '\t' << 5 << '\t' << small_c << '\t' << x-size
