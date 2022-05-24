#ifndef __MERGE_STREAMS_H
#define __MERGE_STREAMS_H

#include "Stream.h"

class MergeStreams : public Stream
{
private:
    enum InputFrom
    {
        FIRST,
        SECOND
    };
    
    Stream* mFirst;
    Stream* mSecond;
    InputFrom mSwitch;

    void copy(const Stream* a, const Stream* b);
    void erase();
public:
    MergeStreams(const Stream* a, const Stream* b);
    MergeStreams(const MergeStreams&);
    MergeStreams& operator=(const MergeStreams&);
    ~MergeStreams();

    Stream* clone() const override;
    char get() override;
};  

#endif