#include <iostream>
#include <cmath>

struct Point
{
    float x, y ,z;
};

float zero_distance(const Point& a){
    return sqrt((a.x*a.x)+(a.y*a.y)+(a.z*a.z));
}

float distance(Point a,Point b){
    float x_distance = a.x+b.x;
    float y_distance = a.y+b.y;
    float z_distance = a.z+b.z;
    return sqrt((x_distance*x_distance)+(y_distance*y_distance)+(z_distance*z_distance));
}

void compare(Point a, Point b){
    float first_value = zero_distance(a);
    float second_value = zero_distance(b);
    float big_value;
    std::string big_one;
    if (first_value > second_value){
        big_one = "Ilk girilen deger buyuktur";
        big_value = first_value;

    }else if(second_value> first_value){
        big_one = "Ikinci girilen deger buyuktur.";
        big_value = second_value;
    }else{
        big_one = "Iki deger birbirine esittir.";
        big_value = first_value;
    }
    std::cout<<"Ilk girilen deger= "<< first_value<<std::endl; 
    std::cout<<"Ikinci girilen deger= "<< second_value<<std::endl; 
    std::cout<< big_one << "ve değeri "<< big_value<< std::endl;

}

enum class Region{
    Orijin,
    X_Eksen,
    Y_Eksen,
    Z_Eksen,
    XY_Duzlemi,
    YZ_Duzlemi,
    XZ_Duzlemi,
    Birinci, //
    Ikinci,
    Ucuncu,
    Dorduncu,
    Besinci,
    Altinci,
    Yedinci,
    Sekizinci    
};

Region region(Point a){
    if (a.x == 0 && a.y == 0 && a.z == 0) {
        return Region::Orijin;  
    } else if (a.x == 0 && a.y != 0 && a.z != 0) {
        return Region::X_Eksen;  
    } else if (a.y == 0 && a.x != 0 && a.z != 0) {
        return Region::Y_Eksen;  
    } else if (a.z == 0 && a.x != 0 && a.y != 0) {
        return Region::Z_Eksen;  
    } else if (a.z == 0 && a.x != 0 && a.y != 0) {
        return Region::XY_Duzlemi;  
    } else if (a.x == 0 && a.y != 0 && a.z != 0) {
        return Region::YZ_Duzlemi; 
    } else if (a.y == 0 && a.x != 0 && a.z != 0) {
        return Region::XZ_Duzlemi;  
    } else if (a.x > 0 && a.y > 0 && a.z > 0) {
        return Region::Birinci;
    } else if (a.x < 0 && a.y > 0 && a.z > 0) {
        return Region::Ikinci;
    } else if (a.x < 0 && a.y < 0 && a.z > 0) {
        return Region::Ucuncu;
    } else if (a.x > 0 && a.y < 0 && a.z > 0) {
        return Region::Dorduncu;
    } else if (a.x > 0 && a.y > 0 && a.z < 0) {
        return Region::Besinci;
    } else if (a.x < 0 && a.y > 0 && a.z < 0) {
        return Region::Altinci;
    } else if (a.x < 0 && a.y < 0 && a.z < 0) {
        return Region::Yedinci;
    } else if (a.x > 0 && a.y < 0 && a.z < 0) {
        return Region::Sekizinci;
    }
}
const char* regionToString(Region r) {
    switch (r) {
        case Region::Orijin: return "Orijin (0, 0, 0)";
        case Region::X_Eksen: return "X Ekseni (X=0, Y ve Z pozitif)";
        case Region::Y_Eksen: return "Y Ekseni (Y=0, X ve Z pozitif)";
        case Region::Z_Eksen: return "Z Ekseni (Z=0, X ve Y pozitif)";
        case Region::XY_Duzlemi: return "XY Düzlemi (Z=0, X ve Y pozitif)";
        case Region::YZ_Duzlemi: return "YZ Düzlemi (X=0, Y ve Z pozitif)";
        case Region::XZ_Duzlemi: return "XZ Düzlemi (Y=0, X ve Z pozitif)";
        case Region::Birinci: return "Birinci Bölge (X pozitif, Y pozitif, Z pozitif)";
        case Region::Ikinci: return "İkinci Bölge (X negatif, Y pozitif, Z pozitif)";
        case Region::Ucuncu: return "Üçüncü Bölge (X negatif, Y negatif, Z pozitif)";
        case Region::Dorduncu: return "Dördüncü Bölge (X pozitif, Y negatif, Z pozitif)";
        case Region::Besinci: return "Beşinci Bölge (X pozitif, Y pozitif, Z negatif)";
        case Region::Altinci: return "Altinci Bölge (X negatif, Y pozitif, Z negatif)";
        case Region::Yedinci: return "Yedinci Bölge (X negatif, Y negatif, Z negatif)";
        case Region::Sekizinci: return "Sekizinci Bölge (X pozitif, Y negatif, Z negatif)";
        default: return "Bilinmeyen Bölge";
    }
}

void is_in_same_region(Point a, Point b){
    if(regionToString(region(a)) == regionToString(region(b))){
        std::cout<<"Ikisi ayni bolgededir."<<std::endl;
    }else{
        std::cout<<"Ikisi ayni bölgede değildir."<<std::endl;
    }
}

int main(){
    Point a, b;
    
    bool is_continue = true;
    while (is_continue) {
        int x;
        std::cout << "Hangi islemi yapmak istiyorsaniz seçin:" << std::endl;
        std::cout << "1. Distance to (0,0,0)" << std::endl;
        std::cout << "2. Iki nokta arasi uzaklik" << std::endl;
        std::cout << "3. İki nokta arasindan hangisinin orijine daha uzak olduğunu bul." << std::endl;
        std::cout << "4. Noktanin hangi bölgede oldugunu bulun." << std::endl;
        std::cout << "5. Iki noktanin ayni bolgede olup olmadigini bul." << std::endl;
        std::cout << "Isleminizi seçin. (1,2,3,4,5)" << std::endl;
        std::cin >> x;
        switch (x)
        {
        case 1:
            std::cout << "Sayinin x,y,z değerlerini girin." << std::endl;
            std::cin >> a.x;
            std::cin >> a.y;
            std::cin >> a.z;
            std::cout<<zero_distance(a)<<std::endl;
            break;
        case 2:
            std::cout << "Birinci sayinin x,y,z değerlerini girin." << std::endl;
            std::cin >> a.x;
            std::cin >> a.y;
            std::cin >> a.z;
            std::cout << "İkinci sayinin x,y,z değerlerini girin." << std::endl;
            std::cin >> b.x;
            std::cin >> b.y;
            std::cin >> b.z;
            std::cout<<distance(a, b)<<std::endl;
            break;
        case 3:
            std::cout << "Birinci sayinin x,y,z değerlerini girin." << std::endl;
            std::cin >> a.x;
            std::cin >> a.y;
            std::cin >> a.z;
            std::cout << "İkinci sayinin x,y,z değerlerini girin." << std::endl;
            std::cin >> b.x;
            std::cin >> b.y;
            std::cin >> b.z;
            compare(a,b);
            break;
        case 4:
            std::cout << "Sayinin x,y,z değerlerini girin." << std::endl;
            std::cin >> a.x;
            std::cin >> a.y;
            std::cin >> a.z;
            std::cout<< regionToString(region(a))<<std::endl;
            break;
        case 5:
            std::cout << "Birinci sayinin x,y,z değerlerini girin." << std::endl;
            std::cin >> a.x;
            std::cin >> a.y;
            std::cin >> a.z;
            std::cout << "İkinci sayinin x,y,z değerlerini girin." << std::endl;
            std::cin >> b.x;
            std::cin >> b.y;
            std::cin >> b.z;
            is_in_same_region(a, b);
            break;
        default:
            std::cout << "Sen neler saçmaliyosun öle sana hesap mesap yok yallah." << std::endl;
            is_continue=false;
            break;
        }
        std::string y_mi_no_mu;
        std::cout << "Devam mi? Tamam mi?(y/n)" << std::endl;
        std::cin >> y_mi_no_mu;
        if(y_mi_no_mu == "n"){
            is_continue =false;
        }



}




    return 0;
}