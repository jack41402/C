#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <filesystem>

struct StudentInfo {
    std::string student_id;
    std::string chinese_name;
    std::string english_name;
    std::string alias;
};

int main() {
    std::string main_folder_path = std::filesystem::current_path().string();
    std::cout << "[INFO] assignment_script.exe execute in " << main_folder_path << '\n' ;

    std::string input="D1175125,黃品喆,Pierre,Coding\nD1172268,佘峻宇,Owen,Stevenson\n"
                      "D1189290,許博琮,Terry,Beaver\nD1228792,楊智臣,Jason,fuij3752\nD1228803,陳宣妤,Adeline,Panasonic\n"
                      "D1228817,黃政睿,Rey,red5\nD1262015,張宇呈,Austin,INFPMAN\nD1262028,李皓鈞,Jimmy,HaoDai\n"
                      "D1262032,劉哲瑋,Derek,Saminamina\nD1262058,謝柏尉,David,vivox90\nD1262062,邱畇諠,Aimee,mi216\n"
                      "D1262075,陳映聿,Morris,EFGHI\nD1262089,蔡睿宇,Ray,Chrona\nD1262092,陳彥勻,Antonio,Abab1020\n"
                      "D1265065,曾語晨,Corrine,quokka\nD1265154,曾郁珊,Mina,coffee18\nD1265209,王子宸,Jensen,HELLO\n"
                      "D1265273,葉緯圻,Joshua,kinyo5647\nD1265315,張子桓,Harrison,Hhhh\nD1265672,王崧喻,Charlie,\n"
                      "D1265686,何柏勳,Terry,Jacky\nD1271403,王祺,Osmond,qvb2358\nD1271450,李宇恩,Eileen,Starbucks";

    std::vector<StudentInfo> students;
    std::stringstream file_stream(input) ;
    std::string line;
    while (std::getline(file_stream, line))
    {
        std::istringstream line_stream(line);
//        std::cout << line << std::endl ;

        std::vector<std::string> row ;
        while (std::getline(line_stream, line, ',')) row.emplace_back(line) ;
        StudentInfo student;
        student.student_id = row[0] ;
        student.chinese_name = row[1] ;
        student.english_name = row[2] ;
        student.alias = row[3] ;
//        std::cout << "Student id: " << student.student_id << '\n';
//        std::cout << "Chinese name: " << student.chinese_name << '\n';
//        std::cout << "English name: " << student.english_name << '\n';
//        std::cout << "Alias: " << student.alias << '\n';
//        std::cout << std::endl;
        students.push_back(student);
    }

    for (const auto& entry : std::filesystem::directory_iterator(main_folder_path)) {
        if (entry.is_directory()) {
            std::string folder_name = entry.path().filename().string();
            std::vector<std::string> token ;
            std::istringstream folder_stream(folder_name) ;
            while(std::getline(folder_stream, line, '_')) token.emplace_back(line) ;
//            std::cout << token[0] << '\n' ;
            for (const auto& student : students)
            {
                if (student.chinese_name == token[0])
                {
//                    std::cout << "Find: " << student.chinese_name << '\n' ;
                    std::string new_folder_name = main_folder_path + "/" + student.student_id + "_" + student.english_name;
                    std::filesystem::rename(entry.path(), new_folder_name);
                    std::cout << "Rename folder " << folder_name << " as " << new_folder_name << std::endl;
                    break ;
                }
            }
        }
    }
    std::cout << "[INFO] assignment_script.exe executed successfully." << '\n' ;
    return 0;
}
