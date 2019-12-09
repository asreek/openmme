/*
 * Copyright (c) 2019, Infosys Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */ 


#include "traceInformationIe.h"
#include "dataTypeCodecUtils.h"

TraceInformationIe::TraceInformationIe() 
{
    ieType = 96;
    // TODO

}

TraceInformationIe::~TraceInformationIe() {
    // TODO Auto-generated destructor stub
}

bool TraceInformationIe::encodeTraceInformationIe(MsgBuffer &buffer, TraceInformationIeData const &data)
{
    if(!(buffer.writeBits(data.mccDigit2, 4)))
    {
        errorStream.add((char *)"Encoding of mccDigit2 failed\n");
        return false;
    }
    if(!(buffer.writeBits(data.mccDigit1, 4)))
    {
        errorStream.add((char *)"Encoding of mccDigit1 failed\n");
        return false;
    }
    if(!(buffer.writeBits(data.mncDigit3, 4)))
    {
        errorStream.add((char *)"Encoding of mncDigit3 failed\n");
        return false;
    }
    if(!(buffer.writeBits(data.mccDigit3, 4)))
    {
        errorStream.add((char *)"Encoding of mccDigit3 failed\n");
        return false;
    }
    if(!(buffer.writeBits(data.mncDigit2, 4)))
    {
        errorStream.add((char *)"Encoding of mncDigit2 failed\n");
        return false;
    }
    if(!(buffer.writeBits(data.mncDigit1, 4)))
    {
        errorStream.add((char *)"Encoding of mncDigit1 failed\n");
        return false;
    }
    if (!(DataTypeCodecUtils::encodeUint8Array4(buffer, data.traceId)))
    {
    errorStream.add((char *)"Encoding of traceId failed\n");
    return false;
    }
    if (!(DataTypeCodecUtils::encodeUint8Array16(buffer, data.triggeringEvents)))
    {
    errorStream.add((char *)"Encoding of triggeringEvents failed\n");
    return false;
    }
    if (!(buffer.writeUint16(data.listOfNeTypes)))
    {
        errorStream.add((char *)"Encoding of listOfNeTypes failed\n");
        return false;
    }
    if (!(buffer.writeUint8(data.sessionTraceDepth)))
    {
        errorStream.add((char *)"Encoding of sessionTraceDepth failed\n");
        return false;
    }
    if (!(DataTypeCodecUtils::encodeUint8Array16(buffer, data.listOfInterfaces)))
    {
    errorStream.add((char *)"Encoding of listOfInterfaces failed\n");
    return false;
    }
    if (!(DataTypeCodecUtils::encodeIpAddressV4(buffer, data.ipAddressOfTce)))
    {
    errorStream.add((char *)"Encoding of ipAddressOfTce failed\n");
    return false;
    }

    return true;
}

bool TraceInformationIe::decodeTraceInformationIe(MsgBuffer &buffer, TraceInformationIeData &data, Uint16 length)
{ 
    // TODO optimize the length checks
    Uint16 lengthLeft = length;
    Uint16 ieBoundary = buffer.getCurrentIndex() + length;
    data.mccDigit2 = buffer.readBits(4);
    // confirm that we are not reading beyond the IE boundary
    if (buffer.getCurrentIndex() > ieBoundary)
    {
        errorStream.add((char *)"Attempt to read beyond IE boundary: mccDigit2\n");
        return false;
    }
    data.mccDigit1 = buffer.readBits(4);
    // confirm that we are not reading beyond the IE boundary
    if (buffer.getCurrentIndex() > ieBoundary)
    {
        errorStream.add((char *)"Attempt to read beyond IE boundary: mccDigit1\n");
        return false;
    }
    data.mncDigit3 = buffer.readBits(4);
    // confirm that we are not reading beyond the IE boundary
    if (buffer.getCurrentIndex() > ieBoundary)
    {
        errorStream.add((char *)"Attempt to read beyond IE boundary: mncDigit3\n");
        return false;
    }
    data.mccDigit3 = buffer.readBits(4);
    // confirm that we are not reading beyond the IE boundary
    if (buffer.getCurrentIndex() > ieBoundary)
    {
        errorStream.add((char *)"Attempt to read beyond IE boundary: mccDigit3\n");
        return false;
    }
    data.mncDigit2 = buffer.readBits(4);
    // confirm that we are not reading beyond the IE boundary
    if (buffer.getCurrentIndex() > ieBoundary)
    {
        errorStream.add((char *)"Attempt to read beyond IE boundary: mncDigit2\n");
        return false;
    }
    data.mncDigit1 = buffer.readBits(4);
    // confirm that we are not reading beyond the IE boundary
    if (buffer.getCurrentIndex() > ieBoundary)
    {
        errorStream.add((char *)"Attempt to read beyond IE boundary: mncDigit1\n");
        return false;
    }
    lengthLeft = ieBoundary - buffer.getCurrentIndex();
    if (!(DataTypeCodecUtils::decodeUint8Array4(buffer, data.traceId, lengthLeft, 3)))
    {
        errorStream.add((char *)"Failed to decode: traceId\n");
        return false;
    }
    lengthLeft = ieBoundary - buffer.getCurrentIndex();
    if (!(DataTypeCodecUtils::decodeUint8Array16(buffer, data.triggeringEvents, lengthLeft, 0)))
    {
        errorStream.add((char *)"Failed to decode: triggeringEvents\n");
        return false;
    }

    buffer.readUint16(data.listOfNeTypes);
    if (buffer.getCurrentIndex() > ieBoundary)
    {
        errorStream.add((char *)"Attempt to read beyond IE boundary: listOfNeTypes\n");
        return false;
    }

    buffer.readUint8(data.sessionTraceDepth);
    if (buffer.getCurrentIndex() > ieBoundary)
    {
        errorStream.add((char *)"Attempt to read beyond IE boundary: sessionTraceDepth\n");
        return false;
    }
    lengthLeft = ieBoundary - buffer.getCurrentIndex();
    if (!(DataTypeCodecUtils::decodeUint8Array16(buffer, data.listOfInterfaces, lengthLeft, 0)))
    {
        errorStream.add((char *)"Failed to decode: listOfInterfaces\n");
        return false;
    }
    lengthLeft = ieBoundary - buffer.getCurrentIndex();
    if (!(DataTypeCodecUtils::decodeIpAddressV4(buffer, data.ipAddressOfTce, lengthLeft)))
    {
        errorStream.add((char *)"Failed to decode: ipAddressOfTce\n");
        return false;
    }

    // The IE is decoded now. The buffer index should be pointing to the 
    // IE Boundary. If not, we have some more data left for the IE which we don't know
    // how to decode
    if (ieBoundary == buffer.getCurrentIndex())
    {
        return true;
    }
    else
    {
        errorStream.add((char *)"Unable to decode IE TraceInformationIe\n");
        return false;
    }
}
void TraceInformationIe::displayTraceInformationIe_v(TraceInformationIeData const &data, Debug &stream)
{
    stream.incrIndent();
    stream.add((char *)"TraceInformationIeData:");
    stream.incrIndent();
    stream.endOfLine();
  
    stream.add( (char *)"mccDigit2: "); 
    stream.add((Uint8)data.mccDigit2);
    stream.endOfLine();
  
    stream.add( (char *)"mccDigit1: "); 
    stream.add((Uint8)data.mccDigit1);
    stream.endOfLine();
  
    stream.add( (char *)"mncDigit3: "); 
    stream.add((Uint8)data.mncDigit3);
    stream.endOfLine();
  
    stream.add( (char *)"mccDigit3: "); 
    stream.add((Uint8)data.mccDigit3);
    stream.endOfLine();
  
    stream.add( (char *)"mncDigit2: "); 
    stream.add((Uint8)data.mncDigit2);
    stream.endOfLine();
  
    stream.add( (char *)"mncDigit1: "); 
    stream.add((Uint8)data.mncDigit1);
    stream.endOfLine();
  
    stream.add((char *)"traceId:");
    stream.endOfLine();
    DataTypeCodecUtils::displayUint8Array4_v(data.traceId, stream);
  
    stream.add((char *)"triggeringEvents:");
    stream.endOfLine();
    DataTypeCodecUtils::displayUint8Array16_v(data.triggeringEvents, stream);
  
    stream.add((char *)"listOfNeTypes: ");
    stream.add(data.listOfNeTypes);
    stream.endOfLine();
  
    stream.add((char *)"sessionTraceDepth: ");
    stream.add(data.sessionTraceDepth);
    stream.endOfLine();
  
    stream.add((char *)"listOfInterfaces:");
    stream.endOfLine();
    DataTypeCodecUtils::displayUint8Array16_v(data.listOfInterfaces, stream);
  
    stream.add((char *)"ipAddressOfTce:");
    stream.endOfLine();
    DataTypeCodecUtils::displayIpAddressV4_v(data.ipAddressOfTce, stream);
    stream.decrIndent();
    stream.decrIndent();
}
