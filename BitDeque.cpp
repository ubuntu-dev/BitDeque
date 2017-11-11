//-------------------------------------------------|
// Copyright (c) 2016 Raymond M. Foulk IV
//
// Permission is hereby granted, free of charge, to
// any person obtaining a copy of this software and
// associated documentation files (the "Software"),
// to deal in the Software without restriction,
// including without limitation the rights to use,
// copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software,
// and to permit persons to whom the Software is
// furnished to do so, subject to the following
// conditions:
//
// The above copyright notice and this permission
// notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT
// WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
// AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
// ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
// OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//-------------------------------------------------|

#include "BitBlock.h"
#include "BitDeque.h"

namespace rmf
{
    
//--52---------------------------------------------|
BitDeque::BitDeque()
: _size(0)
{

}

//--52---------------------------------------------|
BitDeque::~BitDeque()
{

}

//--52---------------------------------------------|
void BitDeque::Clear()
{
    _blocks.clear();
    _size = 0;
}


    // Get a chunk of bits from arbirary bit offset
    BitBlock BitDeque::GetBits(const uint64_t addr);
    //BitBlock GetBits(const uint64_t addr,
    //                 const uint64_t size);

    // Replace (set) bits at bit offset.  This will
    // not alter the size of the block, but only
    // overwrite  bits currently allocated.
    BitBlock BitDeque::SetBits(const BitBlock & block,
                     const uint64_t addr);
    BitBlock BitDeque::SetBits(const uint64_t data,
                     const int8_t size,
                     const uint64_t addr);

    // LSB right-most bits are 'Back'.  This pushes
    // the caller's bits into the right end of the
    // block, shifting existing bits to the left.
    // Bits that  overflow off the left end are
    // returned
    BitBlock BitDeque::PushLow(const BitBlock & block);
    BitBlock BitDeque::PushLow(const uint64_t data,
                     const int8_t size);

    // This pops LSBs off the right, shifting
    // MSBs 'down' and decreasing _size
    BitBlock BitDeque::PopLow(const int8_t size);

    // MSB left-most bits are 'Front'.  This
    // pushes the caller's bits into the left
    // end of the block, shifting existing
    // bits to the right (if necessary since
    // buffer is LSB-justified).  Bits that
    // 'overflow' off the right end are
    // returned.
    BitBlock BitDeque::PushHigh(const BitBlock & block);
    BitBlock BitDeque::PushHigh(const uint64_t data,
                      const int8_t size);

    // This pops MSBs off the left.  No
    // shifting to accommodate should ever
    // be necessary here.
    BitBlock BitDeque::PopHigh(const int8_t size);

//--52---------------------------------------------|
    // Remove (delete) a chunk of bits at an
    // arbitrary bit offset.  The bits deleted are
    // returned in a block if small enough,
    // otherwise if a larger number are to be
    // removed then return the amount removed
    BitBlock BitDeque::Remove(const int8_t size,
                    const uint64_t addr);
    uint64_t BitDeque::Remove(const uint64_t size,
                    const uint64_t addr);


    void BitDeque::Insert(const BitBlock & block,
                const uint64_t addr);








}
