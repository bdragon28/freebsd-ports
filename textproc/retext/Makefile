# $FreeBSD$

PORTNAME=	retext
PORTVERSION=	7.0.0
CATEGORIES=	textproc

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Markdown editor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE_GPL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}markdown>=2.0.3:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Markups>=3.0.0:textproc/py-markups@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown-math>=0.6:textproc/py-markdown-math@${PY_FLAVOR}

USES=		python:3.2+ desktop-file-utils pyqt:5
USE_GITHUB=	yes
GH_ACCOUNT=	retext-project
GH_PROJECT=	retext
USE_PYTHON=	distutils noflavors
USE_PYQT=	core_run sip_run gui_run widgets_run printsupport_run \
		network_run

.include <bsd.port.mk>
