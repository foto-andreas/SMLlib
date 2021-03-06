/**
 * File name: test_getprofilepack_req.c
 *
 * @author Christian Reimann <cybernico@gmx.de>
 * @author Tobias Jeske <tobias.jeske@tu-harburg.de>
 * @remark Supported by the Institute for Security in Distributed Applications (http://www.sva.tu-harburg.de)
 * @see The GNU Public License (GPL)
 */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>.
 */
#include <stdlib.h>

#include "smllib_types.h"
#include "smllib_test.h"

int main(void) {

	SML_Message message;
	SML_GetProfilePack_Req getProfilePackReq;
	SML_ProcParValue ppv;
	SML_Time time;
	SML_Tree dasDetails;
	char* entries[1];

	SML_Boolean withRawData = TRUE;
	char* entry = {"MyTreePathEntry"};
	char transactionId[] = {"GetProfilePack_TransactionId"};
	char serverId[] = {"MyServer"};
	char username[] = {"MyUser"};
	char password[] = {"MyPass"};
	char parameterName[] = {"MyParameterName"};
	entries[0] = entry;

	time.choiceTag = SML_TIME_TIMESTAMP;
	time.choiceValue.secIndex = 122142354;

	ppv.choiceTag = SML_PROCPAR_TIME;
	ppv.choiceValue.smlTime = &time;

	dasDetails.child_List = NULL;
	dasDetails.parameterName = parameterName;
	dasDetails.parameterValue = &ppv;

	getProfilePackReq.serverId = serverId;
	getProfilePackReq.username = username;
	getProfilePackReq.password = password;
	getProfilePackReq.withRawdata = &withRawData;
	getProfilePackReq.beginTime = &time;
	getProfilePackReq.endTime = &time;
	getProfilePackReq.parameterTreePath.listSize = 1;
	getProfilePackReq.parameterTreePath.path_Entry = entries;
	getProfilePackReq.dasDetails = &dasDetails;
	getProfilePackReq.object_List = NULL;

	message.abortOnError = 3;
	message.groupNo = 3;
	message.transactionId = transactionId;
	message.messageBody.choiceTag = SML_MESSAGEBODY_GETPROFILEPACK_REQUEST;
	message.messageBody.choiceValue.getProfilePackRequest = &getProfilePackReq;

	return sml_encode_parse_msg_test(&message);
}
