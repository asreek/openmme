/*
* Copyright (c) 2019 Infosys Limited
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

#include "remoteUeContextConnectedInCreateSessionRequest.h"
#include "manual/gtpV2Ie.h"
#include "gtpV2IeFactory.h"
#include "remoteUserIdIe.h"
#include "remoteUeIpInformationIe.h"

RemoteUeContextConnectedInCreateSessionRequest::
RemoteUeContextConnectedInCreateSessionRequest()
{
    Uint16 mandIe;
    mandIe = RemoteUserIdIeType;
    mandIe = (mandIe << 8) | 0; // remoteUserId
    mandatoryIeSet.insert(mandIe);
    mandIe = RemoteUeIpInformationIeType;
    mandIe = (mandIe << 8) | 0; // remoteUeIpInformation
    mandatoryIeSet.insert(mandIe);

}

RemoteUeContextConnectedInCreateSessionRequest::
~RemoteUeContextConnectedInCreateSessionRequest()
{

}
bool RemoteUeContextConnectedInCreateSessionRequest::
encodeRemoteUeContextConnectedInCreateSessionRequest(MsgBuffer &buffer,
                         RemoteUeContextConnectedInCreateSessionRequestData
                          const &data)
{
    bool rc = false;
    GtpV2IeHeader header;
    Uint16 startIndex = 0;
    Uint16 endIndex = 0;
    Uint16 length = 0;


    
    // Encode the Ie Header
    header.ieType = RemoteUserIdIeType;
    header.instance = 0;
    header.length = 0; // We will encode the IE first and then update the length
    GtpV2Ie::encodeGtpV2IeHeader(buffer, header);
    startIndex = buffer.getCurrentIndex(); 
    RemoteUserIdIe remoteUserId=
    dynamic_cast<
    RemoteUserIdIe&>(GtpV2IeFactory::getInstance().getIeObject(RemoteUserIdIeType));
    rc = remoteUserId.encodeRemoteUserIdIe(buffer, data.remoteUserId);
    endIndex = buffer.getCurrentIndex();
    length = endIndex - startIndex;

    // encode the length value now
    buffer.goToIndex(startIndex - 3);
    buffer.writeUint16(length, false);
    buffer.goToIndex(endIndex);
    if (!(rc))
    {
        errorStream.add((char *)"Failed to encode IE: remoteUserId\n");
        return false;
    }


    
    // Encode the Ie Header
    header.ieType = RemoteUeIpInformationIeType;
    header.instance = 0;
    header.length = 0; // We will encode the IE first and then update the length
    GtpV2Ie::encodeGtpV2IeHeader(buffer, header);
    startIndex = buffer.getCurrentIndex(); 
    RemoteUeIpInformationIe remoteUeIpInformation=
    dynamic_cast<
    RemoteUeIpInformationIe&>(GtpV2IeFactory::getInstance().getIeObject(RemoteUeIpInformationIeType));
    rc = remoteUeIpInformation.encodeRemoteUeIpInformationIe(buffer, data.remoteUeIpInformation);
    endIndex = buffer.getCurrentIndex();
    length = endIndex - startIndex;

    // encode the length value now
    buffer.goToIndex(startIndex - 3);
    buffer.writeUint16(length, false);
    buffer.goToIndex(endIndex);
    if (!(rc))
    {
        errorStream.add((char *)"Failed to encode IE: remoteUeIpInformation\n");
        return false;
    }
    return rc;
}

bool RemoteUeContextConnectedInCreateSessionRequest::
decodeRemoteUeContextConnectedInCreateSessionRequest(MsgBuffer &buffer,
                         RemoteUeContextConnectedInCreateSessionRequestData 
                         &data, Uint16 length)
{

    bool rc = false;
    GtpV2IeHeader ieHeader;
    set<Uint16> mandatoryIeLocalList = mandatoryIeSet;
    while (buffer.lengthLeft() > IE_HEADER_SIZE)
    {
        GtpV2Ie::decodeGtpV2IeHeader(buffer, ieHeader);
        if (ieHeader.length > buffer.lengthLeft())
        {
            // We do not have enough bytes left in the message for this IE
            errorStream.add((char *)"IE Length exceeds beyond message boundary\n");
            errorStream.add((char *)"  Offending IE Type: ");
            errorStream.add(ieHeader.ieType);
            errorStream.add((char *)"\n  Ie Length in Header: ");
            errorStream.add(ieHeader.length);
            errorStream.add((char *)"\n  Bytes left in message: ");
            errorStream.add(buffer.lengthLeft());
            errorStream.endOfLine();
            return false;
        }
    
        switch (ieHeader.ieType){
            case RemoteUserIdIeType:
            {
                RemoteUserIdIe ieObject =
                dynamic_cast<
                RemoteUserIdIe&>(GtpV2IeFactory::getInstance().
                         getIeObject(RemoteUserIdIeType));


                if(ieHeader.instance == 0)
                {

                					rc = ieObject.decodeRemoteUserIdIe(buffer, data.remoteUserId, ieHeader.length);

                    if (!(rc))
                    {
                        errorStream.add((char *)"Failed to decode IE: remoteUserId\n");
                        return false;
                    }
                    Uint16 mandIe = RemoteUserIdIeType;
                    mandIe = (mandIe << 8) | 0;
                    mandatoryIeLocalList.erase(mandIe);
                }
                else
                {
                    // Unknown IE instance print error TODO
                    errorStream.add((char *)"Unknown IE Type: ");
                    errorStream.add(ieHeader.ieType);
                    errorStream.endOfLine();
                    buffer.skipBytes(ieHeader.length);
                }
                break;
            }
            case RemoteUeIpInformationIeType:
            {
                RemoteUeIpInformationIe ieObject =
                dynamic_cast<
                RemoteUeIpInformationIe&>(GtpV2IeFactory::getInstance().
                         getIeObject(RemoteUeIpInformationIeType));


                if(ieHeader.instance == 0)
                {

                					rc = ieObject.decodeRemoteUeIpInformationIe(buffer, data.remoteUeIpInformation, ieHeader.length);

                    if (!(rc))
                    {
                        errorStream.add((char *)"Failed to decode IE: remoteUeIpInformation\n");
                        return false;
                    }
                    Uint16 mandIe = RemoteUeIpInformationIeType;
                    mandIe = (mandIe << 8) | 0;
                    mandatoryIeLocalList.erase(mandIe);
                }
                else
                {
                    // Unknown IE instance print error TODO
                    errorStream.add((char *)"Unknown IE Type: ");
                    errorStream.add(ieHeader.ieType);
                    errorStream.endOfLine();
                    buffer.skipBytes(ieHeader.length);
                }
                break;
            }
            default:
            {
            // Unknown IE print error
            errorStream.add((char *)"Unknown IE Type: ");
            errorStream.add(ieHeader.ieType);
            errorStream.endOfLine();
            buffer.skipBytes(ieHeader.length);
            }
        }
    }
    if (!mandatoryIeLocalList.empty())
    {
        // some mandatory IEs are missing
        errorStream.add((char *)"Missing Mandatory IEs:");
        errorStream.endOfLine();
        while (!mandatoryIeLocalList.empty())
        {
            Uint16 missingMandIe = *mandatoryIeLocalList.begin ();
            mandatoryIeLocalList.erase (mandatoryIeLocalList.begin ());
            Uint16 missingInstance = missingMandIe & 0x00FF;
            Uint16 missingIeType = (missingMandIe >> 8);
            errorStream.add ((char *)"Missing Ie type: ");
            errorStream.add (missingIeType);
            errorStream.add ((char *)"  Instance: ");
            errorStream.add (missingInstance);
            errorStream.endOfLine();
        }
        rc = false;
    
    }
    return rc; 
}

void RemoteUeContextConnectedInCreateSessionRequest::
displayRemoteUeContextConnectedInCreateSessionRequestData_v
(RemoteUeContextConnectedInCreateSessionRequestData const &data, Debug &stream)
{
    stream.incrIndent();
    stream.add((char *)"RemoteUeContextConnectedInCreateSessionRequest:");
    stream.endOfLine();
    stream.incrIndent();



    stream.decrIndent();
    stream.decrIndent();
}





