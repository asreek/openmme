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

#ifndef PGWSOVERLOADCONTROLINFORMATIONINCREATESESSIONRESPONSE_H_
#define PGWSOVERLOADCONTROLINFORMATIONINCREATESESSIONRESPONSE_H_

#include <set>
#include <sstream>
#include "manual/gtpV2GroupedIe.h"
#include <msgBuffer.h>
#include "gtpV2GrpIeDataTypes.h"
#include "../msgClasses/gtpV2MsgDataTypes.h"

class PgwsOverloadControlInformationInCreateSessionResponse:public GtpV2GroupedIe
{
public:
    PgwsOverloadControlInformationInCreateSessionResponse();
    virtual ~PgwsOverloadControlInformationInCreateSessionResponse();
    bool encodePgwsOverloadControlInformationInCreateSessionResponse(MsgBuffer &buffer,
                             PgwsOverloadControlInformationInCreateSessionResponseData
                              const &data);

    bool decodePgwsOverloadControlInformationInCreateSessionResponse (MsgBuffer &buffer,
                             PgwsOverloadControlInformationInCreateSessionResponseData 
                             & data, Uint16 length);

    void displayPgwsOverloadControlInformationInCreateSessionResponseData_v
    (PgwsOverloadControlInformationInCreateSessionResponseData const &data,
     Debug &stream);

private:
    set <Uint16> mandatoryIeSet;
};

#endif