/*******************************************************************************
* Copyright (C) 2004-2006 Intel Corp. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of source code must retain the above copyright notice,
*    this list of conditions and the following disclaimer.
*
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*
*  - Neither the name of Intel Corp. nor the names of its
*    contributors may be used to endorse or promote products derived from this
*    software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL Intel Corp. OR THE CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

/**
 * @author Anas Nashif
 * @author Eugene Yarmosh
 */
#ifndef XML_BINDING_LIBXML2_H_
#define XML_BINDING_LIBXML2_H_



struct __internalWsNode
{
	char* valText;
	//DL_List nsQNameList;
};
typedef struct __internalWsNode iWsNode;

void xml_parser_initialize(SoapH soap);
void xml_parser_destroy(SoapH soap);

int xml_parser_create_doc(WsXmlDocH Doc, char *rootName);
void xml_parser_destroy_doc(WsXmlDocH Doc);
WsXmlDocH xml_parser_get_doc(WsXmlNodeH node);
WsXmlNodeH xml_parser_get_root(WsXmlDocH doc);
WsXmlDocH xml_parser_memory_to_doc(SoapH soap, char *buf, int size, char *encoding, unsigned long options);
char *xml_parser_node_query(WsXmlNodeH node, int what);
int xml_parser_node_set(WsXmlNodeH node, int what, char *str);
WsXmlNodeH xml_parser_node_get(WsXmlNodeH node, int which);
WsXmlNsH xml_parser_ns_find(WsXmlNodeH node, char *uri, char *prefix, int bWalkUpTree, int bAddAtRootIfNotFound);
char *xml_parser_ns_query(WsXmlNsH ns, int what);
WsXmlNsH xml_parser_ns_add(WsXmlNodeH node, char *uri, char *prefix);
int xml_parser_ns_remove(WsXmlNodeH node, char *nsUri);
WsXmlNsH xml_parser_ns_get(WsXmlNodeH node, int which);
int get_ns_count_at_node(xmlNodePtr xmlNode);
int xml_parser_get_count(WsXmlNodeH node, int what, int bWalkUpTree);
// xmlNodePtr make_new_xml_node(xmlNodePtr base, char *uri, char *name, char *value);
WsXmlNodeH xml_parser_node_add(WsXmlNodeH base, int where, char *nsUri, char *localName, char *value);
int xml_parser_node_remove(WsXmlNodeH node);
WsXmlAttrH xml_parser_attr_add(WsXmlNodeH node, char *uri, char *name, char *value);
int xml_parser_attr_remove(WsXmlAttrH attr);
WsXmlDocH xml_parser_file_to_doc(SoapH soap, char* filename, char* encoding, unsigned long options);

char* xml_parser_attr_query(WsXmlAttrH attr, int what);
WsXmlAttrH xml_parser_attr_get(WsXmlNodeH node, int which);

void xml_parser_free_memory(void* ptr);
void xml_parser_doc_to_memory(WsXmlDocH doc, char** buf, int* ptrSize, char* encoding);

void xml_parser_doc_dump(FILE* f, WsXmlDocH doc);
void xml_parser_doc_dump_memory(WsXmlDocH doc, char** buf, int* ptrSize);
void xml_parser_element_dump(FILE* f, WsXmlDocH doc, WsXmlNodeH node);

int xml_parser_check_xpath(WsXmlNodeH node, char * xpath_expr);

int xml_parser_utf8_strlen(char *buf);

char *xml_parser_get_xpath_value(WsXmlDocH doc, const char *expression);

#endif /*XML_BINDING_LIBXML2_H_*/
