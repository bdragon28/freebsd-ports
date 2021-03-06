# $FreeBSD$

PORTNAME=	mkl-dnn
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Intel(R) Math Kernel Library for Deep Neural Networks

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	error: shift count >= width of type (and other errors), see https://github.com/intel/mkl-dnn/issues/315

TEST_DEPENDS=	bash:shells/bash

USES=		cmake:outsource compiler:c++11-lib
USE_GITHUB=	yes
GH_ACCOUNT=	intel
USE_LDCONFIG=	yes

PLIST_FILES=	include/mkldnn.h \
		include/mkldnn.hpp \
		include/mkldnn_debug.h \
		include/mkldnn_types.h \
		lib/libmkldnn.so \
		lib/libmkldnn.so.0 \
		lib/libmkldnn.so.${DISTVERSION}.0

OPTIONS_DEFINE=		OPENMP

OPENMP_CMAKE_BOOL=	USE_OPENMP
OPENMP_LIB_DEPENDS=	libomp.so:devel/openmp

# use clang from ports because cmake can't find OpenMP with base clang, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=223678
BUILD_DEPENDS+=	clang${LLVM_DEFAULT}:devel/llvm${LLVM_DEFAULT}
CPP=		clang-cpp${LLVM_DEFAULT}
CC=		clang${LLVM_DEFAULT}
CXX=		clang++${LLVM_DEFAULT}

do-test: # some tests are known to fail: https://github.com/intel/mkl-dnn/issues/350
	@${REINPLACE_CMD} 's| /bin/bash | ${LOCALBASE}/bin/bash |' ${WRKSRC}/tests/CMakeLists.txt
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTS=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
