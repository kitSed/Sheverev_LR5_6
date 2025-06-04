#ifndef SHEVEREV_LR5_6_STAGEDIRECTOR_H
#define SHEVEREV_LR5_6_STAGEDIRECTOR_H

#include "M:\projects\LR_OOP\Sheverev_LR5_6\Sheverev_LR5_6_AbstractTheaterMember.h"

class StageDirector final : public TheaterMember {
private:
    int productionsCount;
    string artisticStyle;

protected:
    virtual void printInfo(ostream& os) const override;
    virtual void readInfo(istream& is) override;
    virtual bool validate() override;

public:
    StageDirector();
    StageDirector(int memberId, int productionsCount, const string& artisticStyle);
    StageDirector(const StageDirector& other);

    int getProductionsCount() const;
    void setProductionsCount(int productionsCount);
    string getArtisticStyle() const;
    void setArtisticStyle(const string& artisticStyle);

    void performRole() override;
    string getMemberType() override;
    void addSceneRevision();

    StageDirector& operator+=(int count);
};

#endif