//   NOTE: this is a machine generated file--editing not recommended
//
// acext.cpp - class member functions for ASN.1 module ACEXT
//
//   This file was generated by snacc on Mon Apr 26 08:02:27 2004
//   UBC snacc written by Mike Sample
//   A couple of enhancements made by IBM European Networking Center


#include "acext.h"

namespace SNACC{
//------------------------------------------------------------------------------
// value defs

const AsnOid right ("1.1.1.5.1");

const AsnOid group ("1.1.1.4.1");

const AsnOid id_at_group ("1.1.1.4.1");

const AsnOid id_at_right ("1.1.1.5.1");


//------------------------------------------------------------------------------
// class member definitions:

// this class will automatically intialize the any hash tbl
class InitAnyACEXT
{
  public:
    InitAnyACEXT();
    /* Do not add a destructor to this class!  It could
     * cause pre-mature destruction of the ANY tables.
     * The ANY tables will be destroyed by the runtime library.
     */
};

static InitAnyACEXT anyInitalizer;
InitAnyACEXT::InitAnyACEXT()
{
    AsnOid oid0("1.1.1.5.1");
    AsnOid oid1("1.1.1.4.1");


    AsnAny::InstallAnyByOid (oid0, right_ANY_ID, new RightSyntax);
    AsnAny::InstallAnyByOid (oid1, group_ANY_ID, new GroupSyntax);
}  /* InitAny::InitAny */


void RightSyntax::Init(void)
{
  rightAuthority = NULL;
  rightName = NULL;
}

void RightSyntax::Clear()
{
  delete rightAuthority;
  delete rightName;
 Init();
}

RightSyntax::RightSyntax(const RightSyntax &that)
{
   Init();
   *this = that;
}
AsnType *RightSyntax::Clone() const
{
  return new RightSyntax(*this);
}

RightSyntax &RightSyntax::operator = (const RightSyntax &that)
{
  if (this != &that)
  {
    Clear();
    if (that.rightAuthority)
    {
      if (!rightAuthority)
        rightAuthority = new GeneralNames;
      *rightAuthority = *that.rightAuthority;
    }
    else
    {
      delete rightAuthority;
      rightAuthority = NULL;
    }
    if (that.rightName)
    {
      if (!rightName)
        rightName = new GeneralName;
      *rightName = *that.rightName;
    }
    else
    {
      delete rightName;
      rightName = NULL;
    }
  }

  return *this;
}

AsnLen
RightSyntax::BEncContent (AsnBuf &b) const
{
  AsnLen totalLen = 0;
  AsnLen l=0;

    l = rightName->BEncContent (b);
    l += BEncConsLen (b, l);

    l += BEncTag1 (b, CNTX, CONS, 1);
    totalLen += l;

  if (NOT_NULL (rightAuthority))
  {
    l = rightAuthority->BEncContent (b);
    l += BEncConsLen (b, l);

    l += BEncTag1 (b, CNTX, CONS, 0);
    totalLen += l;
  }

  return totalLen;
} // RightSyntax::BEncContent


void RightSyntax::BDecContent (const AsnBuf &b, AsnTag /*tag0*/, AsnLen elmtLen0, AsnLen &bytesDecoded)
{
  FUNC(" RightSyntax::BDecContent");
  Clear();
  AsnTag tag1;
  AsnLen seqBytesDecoded = 0;
  AsnLen elmtLen1;
  AsnLen elmtLen2;
  tag1 = BDecTag (b, seqBytesDecoded);

  if ((tag1 == MAKE_TAG_ID (CNTX, CONS, 0)))
  {
    elmtLen1 = BDecLen (b, seqBytesDecoded);
  rightAuthority = new GeneralNames;
    rightAuthority->BDecContent (b, tag1, elmtLen1, seqBytesDecoded);
    tag1 = BDecTag (b, seqBytesDecoded);
  }

  if ((tag1 == MAKE_TAG_ID (CNTX, CONS, 1)))
  {
    elmtLen1 = BDecLen (b, seqBytesDecoded);
    tag1 = BDecTag (b, seqBytesDecoded);
    elmtLen2 = BDecLen (b, seqBytesDecoded);
  rightName = new GeneralName;
    rightName->BDecContent (b, tag1, elmtLen2, seqBytesDecoded);
    if (elmtLen1 == INDEFINITE_LEN)
      BDecEoc (b, seqBytesDecoded);

  }
  else
  {
      throw EXCEPT("SEQUENCE is missing non-optional elmt", DECODE_ERROR);
  }

  bytesDecoded += seqBytesDecoded;
  if (elmtLen0 == INDEFINITE_LEN)
  {
    BDecEoc (b, bytesDecoded);
    return;
  }
  else if (seqBytesDecoded != elmtLen0)
  {
    throw EXCEPT("Length discrepancy on sequence", DECODE_ERROR);
  }
  else
    return;
} // RightSyntax::BDecContent

AsnLen RightSyntax::BEnc (AsnBuf &b) const
{
  AsnLen l=0;
  l = BEncContent (b);
  l += BEncConsLen (b, l);
  l += BEncTag1 (b, UNIV, CONS, SEQ_TAG_CODE);
  return l;
}

void RightSyntax::BDec (const AsnBuf &b, AsnLen &bytesDecoded)
{
  FUNC(" RightSyntax::BDec");
  AsnTag tag;
  AsnLen elmtLen1;

  if ((tag = BDecTag (b, bytesDecoded)) != MAKE_TAG_ID (UNIV, CONS, SEQ_TAG_CODE))
  {
    throw InvalidTagException(typeName(), tag, STACK_ENTRY);
  }
  elmtLen1 = BDecLen (b, bytesDecoded);
  BDecContent (b, tag, elmtLen1, bytesDecoded);
}

void RightSyntax::Print (std::ostream &os) const
{
  threadLock();
  os << "{ -- SEQUENCE --" << std::endl;
  indentG = (short)(indentG + stdIndentG);

  if (NOT_NULL (rightAuthority))
  {
    Indent (os, indentG);
    os << "rightAuthority ";
    os << *rightAuthority;
  }
  else
  {
    Indent (os, indentG);
    os << "rightAuthority ";
    os << "-- void --";
    os << "," << std::endl;
  }

  if (NOT_NULL (rightName))
  {
    Indent (os, indentG);
    os << "rightName ";
    os << *rightName;
  }
  else
  {
    Indent (os, indentG);
    os << "rightName ";
    os << "-- void --";
    os << std::endl;
  }

  os << std::endl;
  indentG =  (short)(indentG - stdIndentG);
  Indent (os, indentG);
  os << "}";
  threadUnlock();
} // RightSyntax::Print


void RightSyntax::PrintXML (std::ostream &os, 
                   const char *lpszTitle) const
{
  if (lpszTitle)
  {
     os << "<" << lpszTitle;
     if (typeName() && strlen(typeName()))
     {
        os << " typeName=\"" << typeName() << "\"";
     }
  }
  else
  {
     os << "<NONE";
  }
  if (typeName() && strlen(typeName()))
  {
     if (typeName() && strlen(typeName()))
     {
        os << "<" << typeName();
     }
  }
 os << " type=\"SEQUENCE\">" << std::endl;
  if (NOT_NULL (rightAuthority))
  {
    rightAuthority->PrintXML(os, "rightAuthority");
  }

  if (NOT_NULL (rightName))
  {
    rightName->PrintXML(os, "rightName");
  }

  if (lpszTitle)
  {
     os << "</" << lpszTitle << ">" << std::endl;
  }
  else
     if (typeName() && strlen(typeName()))
     {
        os << "</" << typeName() << ">" << std::endl;
     }
} // RightSyntax::PrintXML


void GroupSyntax::Init(void)
{
  groupAuthority = NULL;
  groupName = NULL;
}

void GroupSyntax::Clear()
{
  delete groupAuthority;
  delete groupName;
 Init();
}

GroupSyntax::GroupSyntax(const GroupSyntax &that)
{
   Init();
   *this = that;
}
AsnType *GroupSyntax::Clone() const
{
  return new GroupSyntax(*this);
}

GroupSyntax &GroupSyntax::operator = (const GroupSyntax &that)
{
  if (this != &that)
  {
    Clear();
    if (that.groupAuthority)
    {
      if (!groupAuthority)
        groupAuthority = new GeneralNames;
      *groupAuthority = *that.groupAuthority;
    }
    else
    {
      delete groupAuthority;
      groupAuthority = NULL;
    }
    if (that.groupName)
    {
      if (!groupName)
        groupName = new GeneralName;
      *groupName = *that.groupName;
    }
    else
    {
      delete groupName;
      groupName = NULL;
    }
  }

  return *this;
}

AsnLen
GroupSyntax::BEncContent (AsnBuf &b) const
{
  AsnLen totalLen = 0;
  AsnLen l=0;

    l = groupName->BEncContent (b);
    l += BEncConsLen (b, l);

    l += BEncTag1 (b, CNTX, CONS, 1);
    totalLen += l;

  if (NOT_NULL (groupAuthority))
  {
    l = groupAuthority->BEncContent (b);
    l += BEncConsLen (b, l);

    l += BEncTag1 (b, CNTX, CONS, 0);
    totalLen += l;
  }

  return totalLen;
} // GroupSyntax::BEncContent


void GroupSyntax::BDecContent (const AsnBuf &b, AsnTag /*tag0*/, AsnLen elmtLen0, AsnLen &bytesDecoded)
{
  FUNC(" GroupSyntax::BDecContent");
  Clear();
  AsnTag tag1;
  AsnLen seqBytesDecoded = 0;
  AsnLen elmtLen1;
  AsnLen elmtLen2;
  tag1 = BDecTag (b, seqBytesDecoded);

  if ((tag1 == MAKE_TAG_ID (CNTX, CONS, 0)))
  {
    elmtLen1 = BDecLen (b, seqBytesDecoded);
  groupAuthority = new GeneralNames;
    groupAuthority->BDecContent (b, tag1, elmtLen1, seqBytesDecoded);
    tag1 = BDecTag (b, seqBytesDecoded);
  }

  if ((tag1 == MAKE_TAG_ID (CNTX, CONS, 1)))
  {
    elmtLen1 = BDecLen (b, seqBytesDecoded);
    tag1 = BDecTag (b, seqBytesDecoded);
    elmtLen2 = BDecLen (b, seqBytesDecoded);
  groupName = new GeneralName;
    groupName->BDecContent (b, tag1, elmtLen2, seqBytesDecoded);
    if (elmtLen1 == INDEFINITE_LEN)
      BDecEoc (b, seqBytesDecoded);

  }
  else
  {
      throw EXCEPT("SEQUENCE is missing non-optional elmt", DECODE_ERROR);
  }

  bytesDecoded += seqBytesDecoded;
  if (elmtLen0 == INDEFINITE_LEN)
  {
    BDecEoc (b, bytesDecoded);
    return;
  }
  else if (seqBytesDecoded != elmtLen0)
  {
    throw EXCEPT("Length discrepancy on sequence", DECODE_ERROR);
  }
  else
    return;
} // GroupSyntax::BDecContent

AsnLen GroupSyntax::BEnc (AsnBuf &b) const
{
  AsnLen l=0;
  l = BEncContent (b);
  l += BEncConsLen (b, l);
  l += BEncTag1 (b, UNIV, CONS, SEQ_TAG_CODE);
  return l;
}

void GroupSyntax::BDec (const AsnBuf &b, AsnLen &bytesDecoded)
{
  FUNC(" GroupSyntax::BDec");
  AsnTag tag;
  AsnLen elmtLen1;

  if ((tag = BDecTag (b, bytesDecoded)) != MAKE_TAG_ID (UNIV, CONS, SEQ_TAG_CODE))
  {
    throw InvalidTagException(typeName(), tag, STACK_ENTRY);
  }
  elmtLen1 = BDecLen (b, bytesDecoded);
  BDecContent (b, tag, elmtLen1, bytesDecoded);
}

void GroupSyntax::Print (std::ostream &os) const
{
  threadLock();
  os << "{ -- SEQUENCE --" << std::endl;
  indentG = (short)(indentG + stdIndentG);

  if (NOT_NULL (groupAuthority))
  {
    Indent (os, indentG);
    os << "groupAuthority ";
    os << *groupAuthority;
  }
  else
  {
    Indent (os, indentG);
    os << "groupAuthority ";
    os << "-- void --";
    os << "," << std::endl;
  }

  if (NOT_NULL (groupName))
  {
    Indent (os, indentG);
    os << "groupName ";
    os << *groupName;
  }
  else
  {
    Indent (os, indentG);
    os << "groupName ";
    os << "-- void --";
    os << std::endl;
  }

  os << std::endl;
  indentG =  (short)(indentG - stdIndentG);
  Indent (os, indentG);
  os << "}";
  threadUnlock();
} // GroupSyntax::Print


void GroupSyntax::PrintXML (std::ostream &os, 
                   const char *lpszTitle) const
{
  if (lpszTitle)
  {
     os << "<" << lpszTitle;
     if (typeName() && strlen(typeName()))
     {
        os << " typeName=\"" << typeName() << "\"";
     }
  }
  else
  {
     os << "<NONE";
  }
  if (typeName() && strlen(typeName()))
  {
     if (typeName() && strlen(typeName()))
     {
        os << "<" << typeName();
     }
  }
 os << " type=\"SEQUENCE\">" << std::endl;
  if (NOT_NULL (groupAuthority))
  {
    groupAuthority->PrintXML(os, "groupAuthority");
  }

  if (NOT_NULL (groupName))
  {
    groupName->PrintXML(os, "groupName");
  }

  if (lpszTitle)
  {
     os << "</" << lpszTitle << ">" << std::endl;
  }
  else
     if (typeName() && strlen(typeName()))
     {
        os << "</" << typeName() << ">" << std::endl;
     }
} // GroupSyntax::PrintXML


void AttributeCertChain::Init(void)
{
  attributeCert = NULL;
}

void AttributeCertChain::Clear()
{
  delete attributeCert;
 Init();
}

AttributeCertChain::AttributeCertChain(const AttributeCertChain &that)
{
   Init();
   *this = that;
}
AsnType *AttributeCertChain::Clone() const
{
  return new AttributeCertChain(*this);
}

AttributeCertChain &AttributeCertChain::operator = (const AttributeCertChain &that)
{
  if (this != &that)
  {
    Clear();
    if (that.attributeCert)
    {
      if (!attributeCert)
        attributeCert = new AttributeCertificate;
      *attributeCert = *that.attributeCert;
    }
    else
    {
      delete attributeCert;
      attributeCert = NULL;
    }
    certificateChain = that.certificateChain;
  }

  return *this;
}

AsnLen
AttributeCertChain::BEncContent (AsnBuf &b) const
{
  AsnLen totalLen = 0;
  AsnLen l=0;

    l = certificateChain.BEncContent (b);
    l += BEncConsLen (b, l);

    l += BEncTag1 (b, UNIV, CONS, SEQ_TAG_CODE);
    totalLen += l;

    l = attributeCert->BEncContent (b);
    l += BEncConsLen (b, l);

    l += BEncTag1 (b, UNIV, CONS, SEQ_TAG_CODE);
    totalLen += l;

  return totalLen;
} // AttributeCertChain::BEncContent


void AttributeCertChain::BDecContent (const AsnBuf &b, AsnTag /*tag0*/, AsnLen elmtLen0, AsnLen &bytesDecoded)
{
  FUNC(" AttributeCertChain::BDecContent");
  Clear();
  AsnTag tag1;
  AsnLen seqBytesDecoded = 0;
  AsnLen elmtLen1;
  tag1 = BDecTag (b, seqBytesDecoded);

  if ((tag1 == MAKE_TAG_ID (UNIV, CONS, SEQ_TAG_CODE)))
  {
    elmtLen1 = BDecLen (b, seqBytesDecoded);
  attributeCert = new AttributeCertificate;
    attributeCert->BDecContent (b, tag1, elmtLen1, seqBytesDecoded);
    tag1 = BDecTag (b, seqBytesDecoded);
  }
  else
  {
      throw EXCEPT("SEQUENCE is missing non-optional elmt", DECODE_ERROR);
  }

  if ((tag1 == MAKE_TAG_ID (UNIV, CONS, SEQ_TAG_CODE)))
  {
    elmtLen1 = BDecLen (b, seqBytesDecoded);
    certificateChain.BDecContent (b, tag1, elmtLen1, seqBytesDecoded);
  }
  else
  {
      throw EXCEPT("SEQUENCE is missing non-optional elmt", DECODE_ERROR);
  }

  bytesDecoded += seqBytesDecoded;
  if (elmtLen0 == INDEFINITE_LEN)
  {
    BDecEoc (b, bytesDecoded);
    return;
  }
  else if (seqBytesDecoded != elmtLen0)
  {
    throw EXCEPT("Length discrepancy on sequence", DECODE_ERROR);
  }
  else
    return;
} // AttributeCertChain::BDecContent

AsnLen AttributeCertChain::BEnc (AsnBuf &b) const
{
  AsnLen l=0;
  l = BEncContent (b);
  l += BEncConsLen (b, l);
  l += BEncTag1 (b, UNIV, CONS, SEQ_TAG_CODE);
  return l;
}

void AttributeCertChain::BDec (const AsnBuf &b, AsnLen &bytesDecoded)
{
  FUNC(" AttributeCertChain::BDec");
  AsnTag tag;
  AsnLen elmtLen1;

  if ((tag = BDecTag (b, bytesDecoded)) != MAKE_TAG_ID (UNIV, CONS, SEQ_TAG_CODE))
  {
    throw InvalidTagException(typeName(), tag, STACK_ENTRY);
  }
  elmtLen1 = BDecLen (b, bytesDecoded);
  BDecContent (b, tag, elmtLen1, bytesDecoded);
}

void AttributeCertChain::Print (std::ostream &os) const
{
  threadLock();
  os << "{ -- SEQUENCE --" << std::endl;
  indentG = (short)(indentG + stdIndentG);

  if (NOT_NULL (attributeCert))
  {
    Indent (os, indentG);
    os << "attributeCert ";
    os << *attributeCert;
  }
  else
  {
    Indent (os, indentG);
    os << "attributeCert ";
    os << "-- void --";
    os << "," << std::endl;
  }

  {
    Indent (os, indentG);
    os << "certificateChain ";
    os << certificateChain;
  }

  os << std::endl;
  indentG =  (short)(indentG - stdIndentG);
  Indent (os, indentG);
  os << "}";
  threadUnlock();
} // AttributeCertChain::Print


void AttributeCertChain::PrintXML (std::ostream &os, 
                   const char *lpszTitle) const
{
  if (lpszTitle)
  {
     os << "<" << lpszTitle;
     if (typeName() && strlen(typeName()))
     {
        os << " typeName=\"" << typeName() << "\"";
     }
  }
  else
  {
     os << "<NONE";
  }
  if (typeName() && strlen(typeName()))
  {
     if (typeName() && strlen(typeName()))
     {
        os << "<" << typeName();
     }
  }
 os << " type=\"SEQUENCE\">" << std::endl;
  if (NOT_NULL (attributeCert))
  {
    attributeCert->PrintXML(os, "attributeCert");
  }

    certificateChain.PrintXML(os, "certificateChain");

  if (lpszTitle)
  {
     os << "</" << lpszTitle << ">" << std::endl;
  }
  else
     if (typeName() && strlen(typeName()))
     {
        os << "</" << typeName() << ">" << std::endl;
     }
} // AttributeCertChain::PrintXML


#ifndef NO_NAMESPACE
} // namespace close
#endif