#include<stdio.h>
#include<ctime>
#include<iostream>
#include<string>
using namespace std;


string byond_utf_c[] = {"&#1040;","&#1041;","&#1042;","&#1043;","&#1044;","&#1045;","&#1046;","&#1047;","&#1048;","&#1049;","&#1050;","&#1051;","&#1052;","&#1053;","&#1054;","&#1055;","&#1056;","&#1057;","&#1058;","&#1059;","&#1060;","&#1061;","&#1062;","&#1063;","&#1064;","&#1065;","&#1066;","&#1067;","&#1068;","&#1069;","&#1070;","&#1071;","&#1072;","&#1073;","&#1074;","&#1075;","&#1076;","&#1077;","&#1078;","&#1079;","&#1080;","&#1081;","&#1082;","&#1083;","&#1084;","&#1085;","&#1086;","&#1087;","&#1088;","&#1089;","&#1090;","&#1091;","&#1092;","&#1093;","&#1094;","&#1095;","&#1096;","&#1097;","&#1098;","&#1099;","&#1100;","&#1101;","&#1102;","&#1103;","&#1105;","&#1025;"};
string normal_sim_c[] = {"À","Á","Â","Ã","Ä","Å","Æ","Ç","È","É","Ê","Ë","Ì","Í","Î","Ï","Ð","Ñ","Ò","Ó","Ô","Õ","Ö","×","Ø","Ù","Ú","Û","Ü","Ý","Þ","ß","à","á","â","ã","ä","å","æ","ç","è","é","ê","ë","ì","í","î","ï","ð","ñ","ò","ó","ô","õ","ö","÷","ø","ù","ú","û","ü","ý","þ","ÿ","¨","¸"};

string replace_s(string str, string seach, string rep)
{
    size_t find_s = str.find(seach);///Pos
    int e_pos = seach.size() + find_s; ///End pos
    str.replace(find_s,e_pos, rep);
    return str;
}

void log_write(char* path, char* data)
{
    string d = data;
    FILE* f;
    f = fopen(path,"a");
    
    for(int i = 0;i<66;i++)///Только по 1 символу меняет.
    {
        d = replace_s(d,byond_utf_c[i],normal_sim_c[i]);
    }
    data = (char*)d.c_str();
    
    ///Get time
    time_t t = time(0);
    struct tm time_n;
    char time_now[128];
    time_n = *localtime(&t);
    strftime(time_now,sizeof(time_now),"%Y-%m-%d.%X", &time_n);
    
    ///Output in file
    char data_out[1024];
    sprintf(data_out,"[%s]%s\n",time_now,data);
    fprintf(f,data_out);
    fclose(f);
}


