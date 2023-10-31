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

#include "DoubleMatrix.h"

DoubleMatrix::DoubleMatrix(int row, int column ):m_column(0), m_row(0)
{
	expandMatrix(row, column);
}

DoubleMatrix::DoubleMatrix(QSize size):DoubleMatrix(size.height(),size.height())
{
}

DoubleMatrix::~DoubleMatrix()
{
	clearMatrix();
}

bool DoubleMatrix::checkElementExist(int row, int column)
{
	if (row < m_row && column < m_column)
	{
		return true;
	}
	else
	{
		return false;
	}
}

double  DoubleMatrix::getValueAt(int row, int column)
{
	if (checkElementExist(row, column))
	{
		return m_VecMatrixValue[row][column];
	}
	else
	{
		return -1;
	}
}

double& DoubleMatrix::getValueRefAt(int row, int column)
{
	return m_VecMatrixValue[row][column];
}

void DoubleMatrix::setValue(int row, int column, double value)
{
	if (!checkElementExist(row,column))
	{
		expandMatrix(row + 1, column + 1);//假设元素(3,4)不存在，那么矩阵至少要有4行5列，所以扩张尺寸都要+1
	}

	m_VecMatrixValue[row][column] = value;

}

void DoubleMatrix::clearMatrix()
{
	for (auto pos : m_VecMatrixValue)
	{
		pos.clear();
	}
	m_VecMatrixValue.clear();

	m_column = 0;
	m_row = 0;
}

void DoubleMatrix::expandMatrix(int row, int column)
{
	int resultRow		= std::max(row, m_row);
	int resultColumn	= std::max(column, m_column);

	if (resultColumn == 0 || resultRow == 0)
	{
		return;
	}

	for (int rowNeedAppend = resultRow - m_row; rowNeedAppend > 0; rowNeedAppend--)
	{
		QVector<double> newEmptyVec;
		m_VecMatrixValue.append(newEmptyVec);
	}

	for (int currentRow = 0; currentRow < resultRow; currentRow++)
	{
		int remainColumn = resultColumn - m_VecMatrixValue[currentRow].size();

		for (int columnNeedAppend = remainColumn; columnNeedAppend > 0; columnNeedAppend--)
		{
			m_VecMatrixValue[currentRow].append(0);
		}
	}

	m_row		= resultRow;
	m_column	= resultColumn;

}
