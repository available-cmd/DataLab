/* 
 * CS:APP Data Lab 
 * 
 * 任子衡 available-cmd
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.
  4. Interprets integer expressions using the Data Lab 32-bit bit-vector
     model: results outside the signed range retain their low 32 bits.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
#include "bits.h"

// P1
/* 
 * signMask - return a mask with only the most significant bit set (0x80000000)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int signMask(void) {
  return (1<<31);
}

// P2
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1, bitXor(7, 7) = 0
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 2
 */
int bitXor(int x, int y) {
	return ~(~x & ~y) & ~(x & y);
}

// P3
/*
 * negativePart - return -x if x < 0, otherwise return 0
 *   Examples: negativePart(-10) = 10, negativePart(5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int negativePart(int x){
  return (x>>31) & (~x + 1);
}


// P4
/*
 * copyByteWithin - copy byte src of x to byte dst, leaving all other bytes unchanged
 *   Bytes are numbered from 0 (least significant) to 3 (most significant).
 *   You can assume 0 <= src <= 3 and 0 <= dst <= 3.
 *   Example: copyByteWithin(0x11223344, 0, 2) = 0x11443344
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int copyByteWithin(int x, int src, int dst) {
  /**/
  int y=(x >> (src << 3)) & 0xFF;
  int z=(y << (dst << 3)) ;
  int w=x & ~(0xFF << (dst << 3));
  return w | z;
}

// P5
/* 
 * logicalShift - shift x to the right by n bits, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int logicalShift(int x, int n) {
  return (x >>n) & ~(((1<< 31)>>n) << 1);
}

// P6
/*
 * swapNibblePairs - swap the low and high 4 bits within each byte of x
 *   Examples: swapNibblePairs(0xAB) = 0xBA
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 18
 *   Rating: 4
 */
int swapNibblePairs(int x) {
  int low=0x0F|(0x0F<<8)|(0x0F<<16)|(0x0F<<24);
  int high=0xF0 | (0xF0<<8) | (0xF0<<16) | (0xF0<<24);
  return ((x & low) <<4)|(((x & high)>>4) & low);
}

// P7
/*
 * secondLowestZeroBit - return a mask that marks the position of the second least significant 0 bit
 *   Examples: secondLowestZeroBit(0xFFFFFFFA) = 0x4, secondLowestZeroBit(0x7FFFFFFF) = 0
 *             secondLowestZeroBit(-1) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 4
 */
int secondLowestZeroBit(int x) {
    int first = ~x & (x+1);
    int x2 = x | first;
    int second = ~x2 &(x2 +1);
    return second;
}

// P8
/*
 * oddParity - return the odd parity bit of x, that is,
 *      when the number of 1s in the binary representation of x is even, then the return 1, otherwise return 0.
 *   Examples: oddParity(5) = 1, oddParity(7) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 56
 *   Rating: 5
 */
int oddParity(int x) {
  /**/
  x ^= x >> 1;
  x ^= x >> 2;
  x ^= x >> 4;
  x ^= x >> 8;
  x ^= x >> 16;
  x &= 1;
  return x ^ 1;
}

// P9
/* 
 * rotateRightBits - rotate x to right by n bits
 *   you can assume n >= 0
 *   Examples: rotateRightBits(0x12345678, 8) = 0x78123456
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 5
 */
int rotateRightBits(int x, int n) {
  int low=x&((1<<n)+ ~0);       
  int high=  ~(((1  << 31) >>n)<< 1)& (x >>  n); 
  return (low << (32 + ~n + 1)) | high;
}

// P10
/*
 * roundEvenPow2 - round nonnegative x to the nearest multiple of 2^n.
 *   If x is exactly halfway between two multiples, choose the multiple whose
 *   quotient by 2^n is even.
 *   You can assume 0 <= x <= 0x3fffffff and 1 <= n <= 16.
 *   Examples: roundEvenPow2(10, 2) = 8, roundEvenPow2(14, 2) = 16
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 5
 */
int roundEvenPow2(int x, int n) {
  int mask=((1 << n )+ ~0);
  int q = x & ~mask;
  int r =x  & mask;
  int half = 1 << (n + ~0);
  int r_is_half = !(r ^ half);
  int x_n = (x >> n) & 1;
  int roundup = (((r + half) >> n) & 1) & (!r_is_half | x_n);
  return q + (roundup << n);  
}

// P11
/* 
 * midpointTowardFirst - return the exact mathematical midpoint (x+y)/2
 *   without overflow. If the exact midpoint lies halfway between two
 *   integers, choose the adjacent integer that is closer to the first
 *   argument x.
 *   Examples: midpointTowardFirst(4, 7) = 5,
 *             midpointTowardFirst(7, 4) = 6
 *   Legal ops: ! ~ & ^ | + << >>  
 *   Max ops: 32
 *   Rating: 5
 */
int midpointTowardFirst(int x, int y) {
  int mid = (x & y) + ((x ^ y) >> 1);
  int odd = (x ^ y) & 1;
  int sx = x >> 31;
  int sy = y >> 31;
  int samesign = !(sx ^ sy);
  int diff = x + ~y + 1;
  int sameGt = (!(diff >> 31)) & !!diff;
  int diffGt = (!sx) & !!sy;
  int mask = ~samesign + 1;
  int gt = (sameGt & mask) | (diffGt & ~mask);
  return mid + (odd & gt);
}


// P12
/* 
 * isBetweenEitherOrder - return 1 when x lies in the inclusive interval whose
 *   endpoints are a and b. The endpoints may be given in either order.
 *   Example: isBetweenEitherOrder(5, 8, 3) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 48
 *   Rating: 7
 */
int isBetweenEitherOrder(int x, int a, int b) {
  int sx = x >> 31;
  int sa = a >> 31;
  int sb = b >> 31;
  int nx = ~x;
  int d_xa = x + ~a + 1;
  int d_xb = x + ~b + 1;
  int d_bx = b + nx + 1;
  int d_ax = a + nx + 1;
  int xsa = sx ^ sa;
  int xsb = sx ^ sb;
  int nsx = ~sx;
  int ge_xa = (xsa & nsx) | ~(xsa | (d_xa >> 31));
  int ge_ax = (xsa & ~sa) | ~(xsa | (d_ax >> 31));
  int ge_xb = (xsb & nsx) | ~(xsb | (d_xb >> 31));
  int ge_bx = (xsb & ~sb) | ~(xsb | (d_bx >> 31));
  int r1 = ge_xa & ge_bx;
  int r2 = ge_xb & ge_ax;
  return !!(r1 | r2);    
}

// P13
/* 
 * mul5Sat - return x*5, and if x*5 overflow, change the result to 
 * INT_MAX(0x7fffffff) or INT_MIN(0x80000000) correspondingly
 *   Examples: mul5Sat(1) = 0x5, mul5Sat(0x40000000) = 0x7fffffff
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 7
 */
int mul5Sat(int x) {
  int res = x + (x << 2);
  int sign = x >> 31;
  int abs_x = (x + sign) ^ sign;
  int lim = (0x19 << 24) | (0x99 << 16) | (0x99 << 8) | 0x99;
  int mask = (lim + ~abs_x + 1) >> 31;
  int sat = ((~sign) & ~(1 << 31)) | (sign & (1 << 31));
  return (res & ~mask) | (sat & mask);
}

// P14
/* 
 * classifyAdd3 - classify the exact mathematical sum x+y+z.
 *   Return 1 if the sum is greater than INT_MAX, -1 if it is less than
 *   INT_MIN, and 0 otherwise. You may not use a wider integer type.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 52
 *   Rating: 7
 */
int classifyAdd3(int x, int y, int z) {
    int t = x + y;
    int sx = x >> 31, sy = y >> 31, st = t >> 31;
    int sz = z >> 31;
    int xy_same = ~(sx ^ sy);
    int xy_ovf  = xy_same & (sx ^ st);
    int xy_pos  = xy_ovf & ~sx;
    int xy_neg  = xy_ovf & sx;
    int u = t + z;
    int su = u >> 31;
    int tz_same = ~(st ^ sz);
    int tz_ovf  = tz_same & (st ^ su);
    int tz_pos  = tz_ovf & ~st;
    int tz_neg  = tz_ovf & st;
    int ret1 = (~xy_ovf & tz_pos) | (xy_pos & ~tz_neg);
    int retm1 = (~xy_ovf & tz_neg) | (xy_neg & ~tz_pos);
    return (!!ret1) + (~(!!retm1) + 1);
}
// P15
/*
 * floatScaleThreeHalves - Return bit-level equivalent of expression f*3/2 for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   Use round-to-nearest-even. Preserve the sign of both +0 and -0.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 60
 *   Rating: 7
 */
unsigned floatScaleThreeHalves(unsigned uf) {
    unsigned s    = uf & 0x80000000;
    unsigned exp  = (uf >> 23) & 0xFF;
    unsigned frac = uf & 0x7FFFFF;
    if (exp == 0xFF) return uf;
    unsigned m;
    int e;
    if (exp == 0) {
        m = frac;
        e = -149;
    } else {
        m = (1 << 23) | frac;
        e = exp - 150;
    }
    unsigned m3 = m * 3;
    e = e - 1;
    if (m3 >= (1 << 23)) {
        int shift = 0;
        if (m3 >= (1 << 24)) shift = 1;
        if (m3 >= (1 << 25)) shift = 2;
        unsigned m_norm = m3 >> shift;
        if (shift == 1) {
            if ((m3 & 1) && (m_norm & 1)) m_norm++;
        } else if (shift == 2) {
            unsigned rem = m3 & 3;
            if (rem > 2 || (rem == 2 && (m_norm & 1))) m_norm++;
        }
        if (m_norm >= (1 << 24)) {
            m_norm >>= 1;
            shift++;
        }
        int exp_new = e + shift + 150;
        if (exp_new >= 255) return s | 0x7F800000;
        if (exp_new > 0) {
            frac = m_norm & 0x7FFFFF;
            return s | (exp_new << 23) | frac;
        }
    }
    unsigned frac_new = m3 >> 1;
    if ((m3 & 1) && (frac_new & 1)) frac_new++;
    if (frac_new >= (1 << 23)) {
        return s | (1 << 23) | (frac_new - (1 << 23));
    }
    return s | frac_new;
}

// P16
/* 
 * floatRoundEven - round the floating-point value represented by uf to the
 *   nearest integer, with halfway cases rounded to the even integer. Return
 *   the bit-level representation of that integer as a single-precision float.
 *   If rounding produces zero, preserve the input sign; thus a negative
 *   value that rounds to zero returns -0. When uf is NaN or infinity,
 *   return uf unchanged.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 65
 *   Rating: 10
 */
unsigned floatRoundEven(unsigned uf) {
    unsigned s = uf & 0x80000000;
    unsigned exp  = (uf >> 23) & 0xFF;
    unsigned frac = uf & 0x7FFFFF;
    if (exp == 0xFF) return uf;
    if (exp == 0) return s;
    if (exp >= 150) return uf;
    unsigned M = (1 << 23) | frac;
    int r = 150 - exp;
    if (r > 24) return s;
    unsigned q = M >> r;
    unsigned rem  = M & ((1 << r) - 1);
    unsigned half = 1 << (r - 1);
    if (rem > half || (rem == half && (q & 1)))
        q++;
    if (q == 0) return s;
    unsigned temp = q;
    int msb = 0;
    if (temp >= 0x10000) { temp >>= 16; msb += 16; }
    if (temp >= 0x100)   { temp >>= 8;  msb += 8;  }
    if (temp >= 0x10)    { temp >>= 4;  msb += 4;  }
    if (temp >= 0x4)     { temp >>= 2;  msb += 2;  }
    if (temp >= 0x2)     { temp >>= 1;  msb += 1;  }
    unsigned exp_new  = msb + 127;
    unsigned frac_new = (q << (23 - msb)) & 0x7FFFFF;
    return s | (exp_new << 23) | frac_new;
}

// P17
/*
 * float_i2f - Return bit-level equivalent of expression (float) x.
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer / unsigned operations incl. ||, &&. also if, while
 *   Max ops: 40
 *   Rating: 10
 */
unsigned float_i2f(int x) {
    if (x == 0) return 0;
    unsigned sign = x & 0x80000000;
    unsigned mag = x;
    if (x < 0) mag = -mag;
    int p = 0;
    unsigned t = mag;
    if (t >> 16) {p += 16; t >>= 16; }
    if (t >> 8)  { p += 8;  t >>= 8; }
    if (t >>4)  { p += 4; t >>= 4;}
    if (t >>2)  {p += 2;  t >>= 2;}
    if (t >> 1)  { p += 1; }
    unsigned exp = p + 127;
    unsigned frac;
    if (p <= 23) {
        frac = (mag << (23 - p)) & 0x7FFFFF;
    } else {
        int shift = p - 23;
        unsigned half = 1 << (shift - 1);
        unsigned lsb = (mag >> shift) & 1;
        unsigned bias = half - 1 + lsb;
        frac = (mag + bias) >> shift;
        if (frac >> 24) {
            frac >>= 1;
            exp++;
        }
    }
    return sign | (exp << 23) | (frac & 0x7FFFFF);
}



// P18
/*
 * bitCount - return count of number of 1's in the binary representation of x
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 10
 */
int bitCount(int x) {
  int mask_1 = 0x55 << 8 | 0x55;
  int mask_2 = 0x33 << 8 | 0x33;
  int mask_3 = 0x0F << 8 | 0x0F;
  int mask_4 = 0xFF << 16 | 0xFF;
  int mask_5 = ~0 + (1 << 16);
  mask_1 |= mask_1 << 16;
  mask_2 |= mask_2 | mask_2 << 16;
  mask_3 |= mask_3 | mask_3 << 16;
  x = (x & mask_1) + ((x>>1) & mask_1);
  x = (x & mask_2) + ((x>>2) & mask_2);
  x = (x & mask_3) + ((x>>4) & mask_3);
  x = (x & mask_4) + ((x>>8) & mask_4);
  x = (x & mask_5) + ((x>>16) & mask_5);
  return x;
}

// P19
/*
 * bitReverse - Reverse bits in an 32-bit integer
 *   Examples: bitReverse(0x80000004) = 0x20000001
 *             bitReverse(0x7FFFFFFF) = 0xFFFFFFFE
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 34
 *   Rating: 10
 */
int bitReverse(int x){
  int mask_1 = 0xAA << 8| 0xAA;
  mask_1 |= mask_1 << 16;
  int mask_2 = ~mask_1;
  int mask_3 = 0xCC << 8| 0xCC;
  mask_3 |= mask_3 << 16;
  int mask_4 = ~mask_3;
  int mask_6 = 0x0F << 8| 0x0F;
  mask_6 |= mask_6 << 16;
  int mask_5 = ~mask_6;
  int mask_8 = 0xFF << 16|0xFF;
  int mask_7 = ~mask_8;
  x = ((x >> 1) & mask_2) | ((x << 1) & mask_1);
  x = ((x >> 2) & mask_4) | ((x << 2) & mask_3);
  x = ((x >> 4) & mask_6) | ((x << 4) & mask_5);
  x = ((x >> 8) & mask_8) | ((x << 8) & mask_7);
  return ((x >> 16) & ((0xFF << 8) | 0xFF)) | (x << 16);
}

