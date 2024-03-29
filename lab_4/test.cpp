#include <gtest/gtest.h>
#include "./include/figure_array.h"
#include "./include/triangle.h"
#include "./include/octagon.h"
#include "./include/hexagon.h"



TEST(test_1, init_triangle){
    Triangle<double> t;
    ASSERT_TRUE(double(t)==0);
}

TEST(test_2, init_triangle){
    Coord<double> co1(2,0), co2(0.48, 2.39), co3(-0.83, -0.12);
    Triangle<double> t({co1, co2, co3});
    ASSERT_TRUE(double_cmp(double(t), 1.54695));
}

TEST(test_3, init_triangle){
    Coord<double> co1(2,0), co2(0.48, 2.39), co3(-0.83, -0.12);
    vector<Coord<double>> c(3);
    c[0]=co1;
    c[1]=co2;
    c[2]=co3;
    Triangle<double> t(c);
    ASSERT_TRUE(double_cmp(double(t), 1.54695));
}

TEST(test_4, init_triangle){
    Coord<double> co1(2,0), co2(0.48, 2.39), co3(-0.83, -0.12);
    vector<Coord<double>> c(4);
    c[0]=co1;
    c[1]=co2;
    c[2]=co3;
    ASSERT_THROW(Triangle<double> t(c), logic_error);
}

TEST(test_5, init_triangle){
    Coord<double> co1(2,0), co2(0.48, 2.39), co3(-0.83, -0.12);
    Triangle<double> t({co1, co2, co3});
    Triangle<double> t2=t;
    ASSERT_TRUE(t==t2);
}

TEST(test_6, init_triangle){
    Coord<double> co1(4,0), co2(0.48, 2.39), co3(-0.83, -0.12);
    ASSERT_THROW(Triangle<double>t({co1, co2, co3}), logic_error);
}


TEST(test_7, init_hexagon){
    Hexagon<double>h;
    ASSERT_TRUE(double(h)==0);
}

TEST(test_8, init_hexagon){
    Coord<double> co1(2,0), co2(1.39,1.28),co3(-0.02, 1.4),co4(-0.83, 0.23),co5(-0.22, -1.05),co6(1.19,-1.16);

    Hexagon<double>h{co1,co2,co3, co4,co5,co6};
    ASSERT_TRUE(double_cmp(2.2501, double(h)));
}

TEST(test_9, init_hexagon){
    Coord<double> co1(2,0), co2(1.39,1.28),co3(-0.02, 1.4),co4(-0.83, 0.23),co5(-0.22, -1.05),co6(1.19,-1.16);
    vector<Coord<double>> c(6);
    c[0]=co1;
    c[1]=co2;
    c[2]=co3;
    c[3]=co4;
    c[4]=co5;
    c[5]=co6;
    Hexagon<double>h(c);
    ASSERT_TRUE(double_cmp(2.2501, double(h)));
}

TEST(test_10, init_hexagon){
    Coord<double> co1(10,0), co2(1.39,1.28),co3(-0.02, 1.4),co4(-0.83, 0.23),co5(-0.22, -1.05),co6(1.19,-1.16);
    ASSERT_THROW(Hexagon<double>h({co1,co2,co3, co4,co5,co6}), logic_error);
}

TEST(test_11, init_hexagon){
    Coord<double> co1(2,0), co2(1.39,1.28),co3(-0.02, 1.4),co4(-0.83, 0.23),co5(-0.22, -1.05),co6(1.19,-1.16);
    Hexagon<double>h{co1,co2,co3, co4,co5,co6};
    Hexagon<double>h1=h;
    ASSERT_TRUE(h1==h);
}

TEST(test_12, init_hexagon){
    Coord<double> co1(2,0), co2(1.39,1.28),co3(-0.02, 1.4),co4(-0.83, 0.23),co5(-0.22, -1.05),co6(1.19,-1.16);
    vector<Coord<double>> c(8);
    c[0]=co1;
    c[1]=co2;
    c[2]=co3;
    c[3]=co4;
    c[4]=co5;
    c[5]=co6;
    ASSERT_THROW(Hexagon<double>h(c), logic_error);
}


TEST(test_13, init_octagon){
    Octagon<double> o;
    ASSERT_TRUE(double(o)==0);
}


TEST(test_14, init_octagon){
    Coord<double> co1(3,1), co2(2.41,-0.46),co3(3.02,-1.91),co4(4.48, -2.5),co5(5.92, -1.89),co6(6.52,-0.43),co7(5.91,1.02),co8(4.45, 1.61);
    Octagon<double> o({co1,co2,co3,co4,co5,co6,co7,co8});
    ASSERT_TRUE(double_cmp(double(o), 12.2606));
}



TEST(test_15, init_octagon){
    Coord<double> co1(3,1), co2(2.41,-0.46),co3(3.02,-1.91),co4(4.48, -2.5),co5(5.92, -1.89),co6(6.52,-0.43),co7(5.91,1.02),co8(4.45, 1.61);
    vector<Coord<double>> c(8);
    c[0]=co1;
    c[1]=co2;
    c[2]=co3;
    c[3]=co4;
    c[4]=co5;
    c[5]=co6;
    c[6]=co7;
    c[7]=co8;
    Octagon<double> o(c);
    ASSERT_TRUE(double_cmp(12.2606, double(o)));
}

TEST(test_16, init_octagon){
    Coord<double> co1(10,0), co2(1.39,1.28),co3(-0.02, 1.4),co4(-0.83, 0.23),co5(-0.22, -1.05),co6(1.19,-1.16);
    ASSERT_THROW(Octagon<double> o({co1,co2,co3, co4,co5,co6}), logic_error);
}

TEST(test_17, init_octagon){
    Coord<double> co1(3,1), co2(2.41,-0.46),co3(3.02,-1.91),co4(4.48, -2.5),co5(5.92, -1.89),co6(6.52,-0.43),co7(5.91,1.02),co8(4.45, 1.61);
    Octagon<double> o({co1,co2,co3,co4,co5,co6,co7,co8});
    Octagon<double> o1=o;
    ASSERT_TRUE(o1==o);
}

TEST(test_18, init_hexagon){
    Coord<double> co1(3,1), co2(2.41,-0.46),co3(3.02,-1.91),co4(4.48, -2.5),co5(5.92, -1.89),co6(6.52,-0.43),co7(5.91,1.02),co8(4.45, 1.61);
    vector<Coord<double>> c(9);
    c[0]=co1;
    c[1]=co2;
    c[2]=co3;
    c[3]=co4;
    c[4]=co5;
    c[5]=co6;
    c[6]=co7;
    c[7]=co8;
    ASSERT_THROW(Octagon<double> o(c), logic_error);
}

TEST(test_19, check_coord){
    Coord<double> c1(2,0), c2(0.48, 2.39), c3(-0.83, -0.12);
    Triangle<double>t({c1, c2, c3});
    Coord<double> centre = t.get_coord();
    ASSERT_TRUE(double_cmp(centre.x, 0.55) and double_cmp(centre.y, 0.756667));
}

TEST(test_20, check_coord){
    Coord<double> co1(3,1), co2(2.41,-0.46),co3(3.02,-1.91),co4(4.48, -2.5),co5(5.92, -1.89),co6(6.52,-0.43),co7(5.91,1.02),co8(4.45, 1.61);
    Octagon<double> o({co1,co2,co3,co4,co5,co6,co7,co8});
    Coord<double> centre = o.get_coord();
    ASSERT_TRUE(double_cmp(centre.x, 4.46375 ) and double_cmp(centre.y, -0.445));
}

TEST(test_21, check_coord){
    Coord<double> ch1(2,0), ch2(1.39,1.28),ch3(-0.02, 1.4),ch4(-0.83, 0.23),ch5(-0.22, -1.05),ch6(1.19,-1.16);
    Hexagon<double>h{ch1,ch2,ch3, ch4,ch5,ch6};
    Coord<double> centre = h.get_coord();
    ASSERT_TRUE(double_cmp(centre.x, 0.585 ) and double_cmp(centre.y, 0.116667));
}

TEST(test_23, check_figure_arrive){
    Coord<double> c1(2,0), c2(0.48, 2.39), c3(-0.83, -0.12);
    Triangle<double>t({c1, c2, c3});
    Coord<double> ch1(2,0), ch2(1.39,1.28),ch3(-0.02, 1.4),ch4(-0.83, 0.23),ch5(-0.22, -1.05),ch6(1.19,-1.16);
    Hexagon<double>h{ch1,ch2,ch3, ch4,ch5,ch6};
    F_array<shared_ptr<Figure<double>>> mas = {make_shared<Triangle<double>>(t), make_shared<Hexagon<double>>(h)};
    
    ASSERT_TRUE(double_cmp(mas.common_s(), 3.79705));
}


TEST(test_22, check_figure_arrive){
    Coord<double> c1(2,0), c2(0.48, 2.39), c3(-0.83, -0.12);
    Triangle<double>t({c1, c2, c3});
    Coord<double> ch1(2,0), ch2(1.39,1.28),ch3(-0.02, 1.4),ch4(-0.83, 0.23),ch5(-0.22, -1.05),ch6(1.19,-1.16);
    Hexagon<double>h{ch1,ch2,ch3, ch4,ch5,ch6};
    F_array<shared_ptr<Figure<double>>> mas = {make_shared<Triangle<double>>(t), make_shared<Hexagon<double>>(h)};

    int s=mas.get_size();
    ASSERT_TRUE(s==2);
}

TEST(test_24, check_figure_arrive){
    Coord<double> c1(2,0), c2(0.48, 2.39), c3(-0.83, -0.12);
    Triangle<double>t({c1, c2, c3});
    Coord<double> ch1(2,0), ch2(1.39,1.28),ch3(-0.02, 1.4),ch4(-0.83, 0.23),ch5(-0.22, -1.05),ch6(1.19,-1.16);
    Hexagon<double>h{ch1,ch2,ch3, ch4,ch5,ch6};
    F_array<shared_ptr<Figure<double>>> mas = {make_shared<Triangle<double>>(t), make_shared<Hexagon<double>>(h)};
    
    Coord<double> co1(3,1), co2(2.41,-0.46),co3(3.02,-1.91),co4(4.48, -2.5),co5(5.92, -1.89),co6(6.52,-0.43),co7(5.91,1.02),co8(4.45, 1.61);
    Octagon<double> o({co1,co2,co3,co4,co5,co6,co7,co8});
    mas.add_figure(make_shared<Octagon<double>>(o));

    ASSERT_TRUE(double_cmp(mas.common_s(), 16.0576));
}

TEST(test_25, check_figure_arrive){
    Coord<double> c1(2,0), c2(0.48, 2.39), c3(-0.83, -0.12);
    Triangle<double>t({c1, c2, c3});
    Coord<double> ch1(2,0), ch2(1.39,1.28),ch3(-0.02, 1.4),ch4(-0.83, 0.23),ch5(-0.22, -1.05),ch6(1.19,-1.16);
    Hexagon<double>h{ch1,ch2,ch3, ch4,ch5,ch6};
    
    F_array<shared_ptr<Figure<double>>> mas = {make_shared<Triangle<double>>(t), make_shared<Hexagon<double>>(h)};
    
    Coord<double> co1(3,1), co2(2.41,-0.46),co3(3.02,-1.91),co4(4.48, -2.5),co5(5.92, -1.89),co6(6.52,-0.43),co7(5.91,1.02),co8(4.45, 1.61);
    Octagon<double> o({co1,co2,co3,co4,co5,co6,co7,co8});
    mas.add_figure(make_shared<Octagon<double>>(o));

    auto tmp=make_shared<Figure<double>>();
    tmp=mas.get_figure(1);

    ASSERT_TRUE(*tmp==h);
}

TEST(test_26, check_figure_arrive){
    Coord<double> c1(2,0), c2(0.48, 2.39), c3(-0.83, -0.12);
    Triangle<double>t({c1, c2, c3});
    Coord<double> ch1(2,0), ch2(1.39,1.28),ch3(-0.02, 1.4),ch4(-0.83, 0.23),ch5(-0.22, -1.05),ch6(1.19,-1.16);
    Hexagon<double>h{ch1,ch2,ch3, ch4,ch5,ch6};
    F_array<shared_ptr<Figure<double>>> mas = {make_shared<Triangle<double>>(t), make_shared<Hexagon<double>>(h)};
    
    Coord<double> co1(3,1), co2(2.41,-0.46),co3(3.02,-1.91),co4(4.48, -2.5),co5(5.92, -1.89),co6(6.52,-0.43),co7(5.91,1.02),co8(4.45, 1.61);
    Octagon<double> o({co1,co2,co3,co4,co5,co6,co7,co8});
    mas.add_figure(make_shared<Octagon<double>>(o));

    mas.del_figure(2);

    ASSERT_TRUE(double_cmp(mas.common_s(), 3.79705));
}

TEST(test_27, check_figure_arrive){
    F_array<shared_ptr<Figure<double>>> mas;

    ASSERT_TRUE(mas.get_size()==0);
}


int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
