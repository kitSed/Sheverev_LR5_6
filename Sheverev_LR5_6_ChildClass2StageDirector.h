#ifndef SHEVEREV_LR5_6_CHILDCLASS2STAGEDIRECTOR_H
#define SHEVEREV_LR5_6_CHILDCLASS2STAGEDIRECTOR_H

#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_AbstractClassTheaterMember.h"

class StageDirector final : public TheaterMember {
private:
    int productionsCount;
    string artisticStyle;

protected:
    virtual void printInfo(ostream& os) const override;
    virtual void readInfo(istream& is) override;

public:
    int getProductionsCount() const { return productionsCount; }
    void setProductionsCount(int productionsCount) { this->productionsCount = productionsCount; }
    string getArtisticStyle() const { return artisticStyle; }
    void setArtisticStyle(const string& artisticStyle) { this->artisticStyle = artisticStyle; }

    StageDirector();
    StageDirector(int memberId, const string& name, int experienceYears, int productionsCount, const string& artisticStyle);
    StageDirector(const StageDirector& other);

    virtual void performRole() override;
    virtual string getMemberType() override;
    virtual bool validate() override;

    void addSceneRevision();

    StageDirector& operator+=(int count);
};

#endif