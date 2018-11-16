#include "ClassicZoneHeaderWriter.h"
#include "ThirdPartyHeadersBegin.h"
#include <boost/assign.hpp>
#include "ThirdPartyHeadersEnd.h"
#include "AltTecUtil.h"
#include "ItemSetIterator.h"
#include "writeValueArray.h"
#include "ClassicZoneFileLocations.h"
namespace tecplot { namespace ___3933 { ClassicZoneHeaderWriter::ClassicZoneHeaderWriter( ItemSetIterator&                varIter, ___4636                     zone, ___4636                     ___341, ___37&                     ___36, ClassicZoneFileLocations const& ___4611) : ZoneHeaderWriterAbstract(varIter, zone, ___341, ___36) , m_zoneFileLocations(___4611) {} ClassicZoneHeaderWriter::~ClassicZoneHeaderWriter() {} uint64_t ClassicZoneHeaderWriter::sizeInFile(bool ___2002) const { size_t const numVarsToWrite = static_cast<size_t>(m_varIter.___2812()); uint64_t ___3358 = zoneHeaderTagsSizeInFile(3  , ___2002) + arraySizeInFile<uint64_t, true  >(numVarsToWrite, ___2002); return ___3358; } ___372 ClassicZoneHeaderWriter::write(FileWriterInterface& fileWriter) const { ___372 ___2039 = ___4226; ___4352 const numVarsToWrite = m_varIter.___2812(); try { ___3945 ___3944 = boost::assign::map_list_of<uint16_t, uint64_t> ((uint16_t)___4342, (uint64_t)0) ((uint16_t)___2725, (uint64_t)m_zoneFileLocations.___2498) ((uint16_t)USER_FACE_NBR_FILE_LOC_TAG, (uint64_t)m_zoneFileLocations.___2663); uint64_t tagFilePos = fileWriter.fileLoc(); ___2039 = ___4565(fileWriter, ___3944); if (___2039) { ___3944[___4342] = fileWriter.fileLoc(); ___2039 = ___4563<uint64_t, true, 0>(fileWriter, appendZoneSuffix(VAR_FILE_LOC_DESCRIPTION).c_str(), ___2677 - m_baseZone, (size_t)numVarsToWrite, &m_zoneFileLocations.___2673[0]); } uint64_t finalFilePos = fileWriter.fileLoc(); ___2039 = ___2039 && fileWriter.___3459(tagFilePos) && ___4565(fileWriter, ___3944) && fileWriter.___3459(finalFilePos); } catch(std::bad_alloc const&) { ___2039 = ___1186("Out of memory while writing zone %d header.", ___2677+1); } catch(...) { ___2039 = ___1186("Unrecoverable error while writing zone %d header.", ___2677+1); } ENSURE(VALID_BOOLEAN(___2039)); return ___2039; } }}
