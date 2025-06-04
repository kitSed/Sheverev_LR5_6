#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_StageDirector.h"
#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_def.h"

StageDirector::StageDirector() : TheaterMember(), productionsCount(1), artisticStyle("Классика") {}

StageDirector::StageDirector(int memberId, int productionsCount, const string& artisticStyle) : TheaterMember(memberId), productionsCount(productionsCount), artisticStyle(artisticStyle) {}

StageDirector::StageDirector(const StageDirector& other) : TheaterMember(other), productionsCount(other.productionsCount), artisticStyle(other.artisticStyle) {}

int StageDirector::getProductionsCount() const {
    return productionsCount;
}

void StageDirector::setProductionsCount(int count) {
    productionsCount = count;
}

string StageDirector::getArtisticStyle() const {
    return artisticStyle;
}

void StageDirector::setArtisticStyle(const string& style) {
    artisticStyle = style;
}

void StageDirector::performRole() override {
    cout << "Режиссирует спектакль в стиле " << artisticStyle << endl;
}

string StageDirector::getMemberType() override {
    return "Режиссер";
}

bool StageDirector::validate() override {
    return TheaterMember::validate() && productionsCount >= 1;
}

void StageDirector::addSceneRevision() {
    cout << "Введите описание изменений: ";
    string revision;
    getline(cin, revision);
    artisticStyle += " [" + revision + "]";
}

StageDirector& StageDirector::operator+=(int count) {
    productionsCount += count;
    return *this;
}

void StageDirector::printInfo(ostream& os) const {
    TheaterMember::printInfo(os);
    os << "Поставлено спектаклей: " << productionsCount << endl
       << "Стиль: " << artisticStyle << endl;
}

void StageDirector::readInfo(istream& is) {
    TheaterMember::readInfo(is);
    EnterNumberInt(productionsCount, "Введите количество постановок: ", is)();
    is.ignore();
    EnterString(artisticStyle, "Введите стиль (Классика/Авангард): ", is)();
}