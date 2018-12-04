#include <RayTracing/ImgWindow.h>

#include <Utility/OpNode.h>

using namespace RayTracing;
using namespace CppUtility::OpenGL;
using namespace CppUtility::Other;
using namespace std;

ImgWindow::ImgWindow(const string & title)
	: TexWindow(title){
	img.GenBuffer(GetWidth(), GetHeight(), 3);
	if (!img.IsValid()) {
		isValid = false;
		return;
	}
}

bool ImgWindow::Run(Ptr<Operation> imgUpdateOp) {
	Texture tex(Texture::ENUM_TYPE_2D_DYNAMIC);
	tex.SetImg(img);
	SetTex(tex);

	OpNode::Ptr texUpdateOp = ToPtr(new OpNode(NULL, [&]() {
		if (!imgUpdateOp->IsHold())
			texUpdateOp->SetIsHold(false);
	}));

	LambdaOp::Ptr bindImgOp = ToPtr(new LambdaOp([&]() {
		tex.SetImg(img);
	}));
	
	(*texUpdateOp) << imgUpdateOp << bindImgOp;

	return TexWindow::Run(texUpdateOp);
}