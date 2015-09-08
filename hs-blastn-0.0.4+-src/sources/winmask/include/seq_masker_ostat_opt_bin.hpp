/*  $Id: seq_masker_ostat_opt_bin.hpp 183994 2010-02-23 20:20:11Z morgulis $
 * ===========================================================================
 *
 *                            PUBLIC DOMAIN NOTICE
 *               National Center for Biotechnology Information
 *
 *  This software/database is a "United States Government Work" under the
 *  terms of the United States Copyright Act.  It was written as part of
 *  the author's official duties as a United States Government employee and
 *  thus cannot be copyrighted.  This software/database is freely available
 *  to the public for use. The National Library of Medicine and the U.S.
 *  Government have not placed any restriction on its use or reproduction.
 *
 *  Although all reasonable efforts have been taken to ensure the accuracy
 *  and reliability of the software and data, the NLM and the U.S.
 *  Government do not and cannot warrant the performance or results that
 *  may be obtained by using this software or data. The NLM and the U.S.
 *  Government disclaim all warranties, express or implied, including
 *  warranties of performance, merchantability or fitness for any particular
 *  purpose.
 *
 *  Please cite the author in any work or product based on this material.
 *
 * ===========================================================================
 *
 * Author:  Aleksandr Morgulis
 *
 * File Description:
 *   Definition of CSeqMaskerOStatOptBin class.
 *
 */

#ifndef C_SEQ_MASKER_OSTATE_BIN_H
#define C_SEQ_MASKER_OSTATE_BIN_H

#include "seq_masker_ostat_opt.hpp"

BEGIN_NCBI_SCOPE

/**
 **\brief This class is responsible for saving optimized unit counts
 **       in binary format.
 **/
class NCBI_XALGOWINMASK_EXPORT
CSeqMaskerOstatOptBin : public CSeqMaskerOstatOpt
{
    public:

        /**
         **\brief Object constructor.
         **\param name output file name
         **\param sz requested upper limit on the size of the data structure
         **          (forwarded to CSeqMaskerOstatOpt)
         **\param use_ba use bit array optimization
         **/
        explicit CSeqMaskerOstatOptBin( const string & name, Uint2 sz, bool use_ba );

        /**
         **\brief Object constructor.
         **\param os the output stream
         **\param sz requested upper limit on the size of the data structure
         **          (forwarded to CSeqMaskerOstatOpt)
         **\param use_ba use bit array optimization
         **/
        explicit CSeqMaskerOstatOptBin( CNcbiOstream & os, Uint2 sz, bool use_ba );

        /**
         **\brief Object destructor.
         **/
        virtual ~CSeqMaskerOstatOptBin() {}

    protected:

        /**
         **\brief Write optimized data to the output stream.
         **\param p structure containing the hash table and threshold
         **         parameters and pointers to data tables
         **/
        virtual void write_out( const params & ) const;

    private:

        /**\internal
         **\brief Write a 4-byte unsigned integer to the output stream.
         **\param word the integer to write
         **/
        void write_word( Uint4 word ) const
        {
            out_stream.write( 
                reinterpret_cast< const char * >(&word), sizeof( Uint4 ) );
        }

        /**\internal
         **\brief Use bit array optimization.
         **/
        bool use_ba;
};

END_NCBI_SCOPE

#endif
