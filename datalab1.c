/*
 *
 * CSED 211, Fall 2022
 * DataLAb: Manipulating Bits
 * Assigned: 2022-09-07
 * Due: 2022-09-18 23:59 pm
 *
 * Namgyu Park (namgyu.park@postech.ac.kr) is the lead person for this assignment.
 *
*/

#if 0
LAB L1 INSTRUCTIONS :
#endif
/*
 *   #Homework1-1
 *   bitNor - ~(x|y) using only ~ and &
 *   Example: bitNor(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int bitNor(int x, int y) {
	//to be implemented

	return ~x & ~y; //��𸣰��� ��Ģ�� ���� 
}/*
 *   #Homework1-2
 *   isZero - returns 1 if x == 0, and 0 otherwise
 *   Examples: isZero(5) = 0, isZero(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int isZero(int x) {
	//to be implemented
	return !x; // 0�� �� 1, 0�̿��� �ٸ� �� (true)�� �� 0 ���
}/*
 *   #Homework1-3
 *   addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {

	//to be implemented
	int sum = x + y;
	int x_sign = (x >> 31) & 0x00000001; //x�� ��ȣ 
	int y_sign = (y >> 31) & 0x00000001; //y�� ��ȣ 
	int sum_sign = (sum >> 31) & 0x00000001; //sum�� ��ȣ 

	int xysame = !(x_sign^y_sign); //x�� y�� ��ȣ�� �ٸ��� 0 return 
	int xsumdiff = x_sign^sum_sign; //x�� sum�� ��ȣ�� �ٸ��� 1 return 

	return !(xysame & xsumdiff); //x�� y�� ���� x�� sum ��ȣ�� �ٸ� �� 0 ���, �̿��� ��Ȳ (�����÷ο� �߻�)�� �� 1 ��� 

}/*
 *   #Homework1-4
 *   absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
	//to be implemented
	int sign = x >> 31; // x�� ��ȣ�� �츲 
	int ans = x + sign; 
	ans = ans ^ sign; 
	return ans; //ans ���� return 
}/*
 *   #Homework1-5
 *   logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */

int logicalShift(int x, int n) {
	//to be implemented
	int temp = ((1 << 31) >> n) << 1; // shift�� �κб����� 1, �������� 0�� temp ���� 
	x = x >> n; // arithmetic shift ���� 
	return ~temp & x; //temp�� ����: shift�� �κб����� 0, �������� 1�̹Ƿ� x�� shift�� �κ��� ��� 0���� ����(logical shift) 
	

}
