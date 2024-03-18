#include "./include/figure_array.h"
#include "./include/triangle.h"
#include "./include/octagon.h"
#include "./include/hexagon.h"


int main(){
    coord c1(2,0), c2(0.48, 2.39), c3(-0.83, -0.12);
    Triangle t({c1, c2, c3});
    cout<<t;
    cout<<double(t)<<'\n';
    coord ch1(2,0), ch2(1.39,1.28),ch3(-0.02, 1.4),ch4(-0.83, 0.23),ch5(-0.22, -1.05),ch6(1.19,-1.16);
    Hexagon h{ch1,ch2,ch3, ch4,ch5,ch6};
    cout<<double(h)<<'\n';


    coord co1(3,1), co2(2.41,-0.46),co3(3.02,-1.91),co4(4.48, -2.5),co5(5.92, -1.89),co6(6.52,-0.43),co7(5.91,1.02),co8(4.45, 1.61);
    Octagon o({co1,co2,co3,co4,co5,co6,co7,co8});
    cout<<double(o)<<'\n';


    F_array mas({&t,&h});
    
    cout<<"common s="<<mas.common_s()<<"\n\n";
    mas.print_geom_centre();
    cout<<'\n';
    mas.print_s();
    cout<<"\n===========After adding:\n";
    mas.add_figure(&o);
    cout<<"common s="<<mas.common_s()<<"\n\n";
    mas.print_geom_centre();
    cout<<'\n';
    mas.print_s();
    cout<<'\n';
    cout<<"==============Get by index\n";
    Figure *tmp;
    tmp=mas.get_figure(1);
    cout<<*tmp<<'\n';
    cout<<"\n============After deleting last elem\n";
    mas.del_figure(2);
        cout<<"common s="<<mas.common_s()<<"\n\n";
    mas.print_geom_centre();
    cout<<'\n';
    mas.print_s();
    cout<<'\n';





}
