IF (BUILD_ALC OR BUILD_ALCC)
	ADD_SUBDIRECTORY (aLinkCreator)
ENDIF (BUILD_ALC OR BUILD_ALCC)

IF (BUILD_CAS)
	ADD_SUBDIRECTORY (cas)
ENDIF (BUILD_CAS)

IF (BUILD_FILEVIEW)
	ADD_SUBDIRECTORY (fileview)
ENDIF (BUILD_FILEVIEW)

IF (BUILD_PLASMAMULE)
	ADD_SUBDIRECTORY (plasmamule)
ENDIF (BUILD_PLASMAMULE)

IF (BUILD_WXCAS)
	ADD_SUBDIRECTORY (wxCas)
ENDIF (BUILD_WXCAS)

IF (BUILD_XAS)
	ADD_SUBDIRECTORY (xas)
ENDIF (BUILD_XAS)
