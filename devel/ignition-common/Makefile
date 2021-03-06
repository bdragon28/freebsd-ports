# $FreeBSD$

PORTNAME=	ignition-common
DISTVERSION=	3.0.0
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Set of libraries designed to rapidly develop robot applications

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	ignition-cmake==2:devel/ignition-cmake
LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg \
		libfreeimage.so:graphics/freeimage \
		libgts.so:graphics/gts \
		libtinyxml2.so:textproc/tinyxml2 \
		libuuid.so:misc/e2fsprogs-libuuid \
		libignition-math6.so:math/ignition-math

USES=		cmake:outsource compiler:c++17-lang gnome pkgconfig
USE_GNOME=	glib20
USE_LDCONFIG=	yes

CMAKE_ON=	USE_EXTERNAL_TINYXML2
CMAKE_OFF=	BUILD_TESTING

BB_ACCOUNT=	ignitionrobotics
BB_PROJECT=	ign-common
BB_COMMIT=	a5c4d5a35bb8

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}

PLIST_SUB+=	COMMON_IGN_VER=common${DISTVERSION:R:R}

.include <bsd.port.mk>
