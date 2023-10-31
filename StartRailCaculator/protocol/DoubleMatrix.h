/*****************************************************************************************
**	Copyright(C) <2023-2024> <adsl_lucy>
**
**	Permission is hereby granted, free of charge, to any person obtaining a copy
**	of this software and associated documentation files(the "Software"), to deal
**	in the Software without restriction, including without limitation the rights
**	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
**	copies of the Software, and to permit persons to whom the Software is furnished
**	to do so, subject to the following conditions :
**
**	The above copyright notice and this permission notice shall be included in all
**	copies or substantial portions of the Software.THE SOFTWARE IS PROVIDED "AS IS",
**	WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
**	THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
**	IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
**	OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
**	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**
*****************************************************************************************/

#ifndef DOUBLE_MATRIX
#define DOUBLE_MATRIX

#include <QVector>
#include <QSize>

//double矩阵，方便进行二维数阵操作
//扩充矩阵时默认新元素值为0
//矩阵的下标遵从数组习惯，第一个元素下标为0（这意味着左上角元素的下标为（0，0））
//如果矩阵的尺寸是3行4列，那么右下角元素的下标为（2，3）


class DoubleMatrix
{
public:
	DoubleMatrix(int row = 0, int column = 0);
	DoubleMatrix(QSize size);
	~DoubleMatrix();

	//返回矩阵大小,这里QSize的height就是行数，width就是列数
	const QSize 	getMatrixSize() const { return QSize(m_column, m_row); }
	//检查指定元素是否存在
	bool		checkElementExist(int row, int column);
	//返回特定位置的值，如果超出MatrixSize，那么会返回-1
	double		getValueAt(int row, int column);
	//返回特定位置的值常量，如果超出MatrixSize会崩溃，建议用之前检查尺寸
	const double 	getConstValueAt(int row, int column) const { return m_VecMatrixValue[row][column];};
	//返回特定位置的值引用，超出范围会崩
	double&		getValueRefAt(int row, int column);
	//设置矩阵一个位置的值，如果超出矩阵范围，那么自动扩充矩阵到包含该元素最小尺寸
	void		setValue(int row, int column,double value);
	//扩张矩阵大小，保证矩阵扩张后的尺寸至少有row行和column列
	//如果输入的行数/列数小于当前尺寸，那么行/列不会有操作
	void		expandMatrix(int row, int column);

	void		expandMatrix(QSize size) { expandMatrix(size.height(),size.width()); };
	//清理矩阵
	void		clearMatrix();

private:

	int m_row	= 0;//矩阵行数，值为4，意味着一共有4行，但是此时最大的行下标是3
	int m_column	= 0;//矩阵列数，值为3，意味着一共有3列，但是此时最大的列下标是2
	
	//矩阵容器，代码理论上会保证每一行的对应的数组是等长的
	QVector<QVector<double>> m_VecMatrixValue;

};

#endif
