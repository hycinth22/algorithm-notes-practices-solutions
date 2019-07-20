// 简单模拟B1026.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int c1, c2; cin >> c1 >> c2;
	const int clk_tck = 100;
	int time = roundf(static_cast<float>(c2 - c1) / clk_tck);
	// 用于表达式 out << setw(n) 或 in >> setw(n) 时，设置流 out 或 in 的 width 参数准确为 n 。
	/* 注意
	若调用任何下列函数，则流的宽度属性将被设为零（表示“不指定”）：
		输入
		operator>>(basic_istream&, basic_string&)
		operator>>(basic_istream&, char*)
		输出
		basic_ostream::operator<<() 的重载 1 - 7 （在 num_put::put() 的阶段 3 ）
		operator<<(basic_ostream&, char) 和 operator<<(basic_ostream&, char*)
		operator<<(basic_ostream&, basic_string&)
		std::put_money （在 money_put::put() 内）
		std::quoted （以输出流使用时）
		/**/
	cout << setfill('0');

	int second = time % 60;
	time /= 60;
	int minute = time % 60;
	time /= 60;
	int hour = time;

	cout << setw(2) << hour << ":" 
		<< setw(2) <<minute << ":" 
		<< setw(2)  << second << endl;


	/*
	format	-	指向指定数据转译方式的空终止多字节字符串的指针。
格式字符串由普通多字节字符（除了 % ）和转换指定构成，前者被复制到输出流而无更改。每个转换指定拥有下列格式：

引入的 % 字符
(可选)一或多个修改转换行为的标签：
- ：转换结果在域内左校正（默认为右校正）
+ ：有符号转换的符号始终前置于转换结果（默认结果前置负号仅当它为负）
空格：若有符号转换的结果不以符号开始，或为空，则前置空格于结果。若存在 + 标签则忽略空格。
# ：进行替用形式的转换。准确的效果见下表，其他情况下行为未定义。
0 ：对于整数和浮点数转换，使用前导零代替空格字符填充域。对于整数，若显式指定精度，则忽略此标签。对于其他转换，使用此标签导致未定义行为。若存在 - 标签则忽略 0 。
(可选)指定最小域宽的整数值或 * 。若有要求，则结果会以空格字符（默认情况）填充，在右校正时于左，左校正时于右。使用 * 的情况下，以一个额外的 int 类型参数指定宽度。若参数值为负数，则它导致指定 - 标签和正域宽。（注意：这是最小宽度：决不被截断值）。
(可选)后随整数或 * 或两者皆无的 . 指示转换的精度。在使用 * 的情况下，精度由额外的 int 类型参数指定。若此参数的值为负数，则它被忽略。若既不使用数字亦不使用 * ，则精度采用零。精度的准确效果见下表。
(可选)指定参数大小的长度修饰符
转换格式指定符
	*/
	printf("%02d:%02d:%02d\n", hour, minute, second);
}
