#ifndef ADD_CGTHCK_BILL_DTO_
#define ADD_CGTHCK_BILL_DTO_

#include "../FileDTO.h"
#include "../../GlobalInclude.h"
#include "./CgthckBillEntryDTO.h"
/**
* �ɹ��˻�����(����), ��Ӳɹ��˻����ⵥ���ݴ������
*/
class AddCgthckBillDTO : public FileDTO
{
	/***����***/
	// ���ݱ��
	CC_SYNTHESIZE(std::string, billNo, BillNo);
	// ��������
	CC_SYNTHESIZE(std::string, billDate, BillDate);

	/***����***/
	// ��������
	CC_SYNTHESIZE(std::string, subject, Subject);
	// Դ��ҵ����Ա
	CC_SYNTHESIZE(std::string, srcOperator, SrcOperator);
	// ҵ����
	CC_SYNTHESIZE(std::string, opDept, OpDept);
	// ��Ӧ��
	CC_SYNTHESIZE(std::string, supplierId, SupplierId);
	// �ɹ���ⵥ
	CC_SYNTHESIZE(std::string, srcNo, SrcNo);
	// ���⾭��
	CC_SYNTHESIZE(std::string, handler, Handler);
	// ��ע
	CC_SYNTHESIZE(std::string, remark, Remark);
	// ����
	CC_SYNTHESIZE(std::string, attachment, Attachment);
	// ���ݽ׶�
	CC_SYNTHESIZE(std::string, billStage, BillStage);

	/***������***/
	// ����Ч
	CC_SYNTHESIZE(bool, isEff, IsEff);
	// �ѹر�
	CC_SYNTHESIZE(bool, isClosed, IsClosed);
	// ������
	CC_SYNTHESIZE(bool, isVoided, IsVoided);
	// ��Чʱ��
	CC_SYNTHESIZE(std::string, effTime, EffTime);
	// ������
	CC_SYNTHESIZE(std::string, approver, Approver);
	// ����ʵ��
	CC_SYNTHESIZE(std::string, bpmiInstanceId, BpmiInstanceId);
	// �Ƶ�ʱ��
	CC_SYNTHESIZE(std::string, createTime, CreateTime);
	// �Ƶ�����
	CC_SYNTHESIZE(std::string, sysOrgCode, SysOrgCode);
	// �Ƶ���
	CC_SYNTHESIZE(std::string, createBy, CreateBy);
	// �޸�ʱ��
	CC_SYNTHESIZE(std::string, updateTime, UpdateTime);
	// �޸���
	CC_SYNTHESIZE(std::string, updateBy, UpdateBy);
	// �Ƿ��Զ�����
	CC_SYNTHESIZE(bool, isAuto, IsAuto);
	// �Ƿ����
	CC_SYNTHESIZE(bool, isRubric, IsRubric);
	// ��Ӧ��
	CC_SYNTHESIZE(bool, hasRp, HasRp);
	// ���Ƕ�
	CC_SYNTHESIZE(bool, hasSwell, HasSwell);
	// Դ������
	CC_SYNTHESIZE(std::string, srcBillType, SrcBillType);
	// ��Ʊ����
	CC_SYNTHESIZE(std::string, invoiceType, InvoiceType);

	// �˻����ⵥ��ϸ�б�
	CC_SYNTHESIZE(std::list<CgthckBillEntryDTO>, entry, Entry);
public:
	// ��JSONת������
	friend void from_json(const json& j, AddCgthckBillDTO& t) // NOLINT
	{
		BIND_FROM_TO_NORMAL(j, t, billNo);
		BIND_FROM_TO_NORMAL(j, t, billDate);
		BIND_FROM_TO_NORMAL(j, t, subject);
		BIND_FROM_TO_NORMAL(j, t, srcOperator);
		BIND_FROM_TO_NORMAL(j, t, opDept);
		BIND_FROM_TO_NORMAL(j, t, supplierId);
		BIND_FROM_TO_NORMAL(j, t, srcNo);
		BIND_FROM_TO_NORMAL(j, t, handler);
		BIND_FROM_TO_NORMAL(j, t, remark);
		BIND_FROM_TO_NORMAL(j, t, attachment);
		BIND_FROM_TO_NORMAL(j, t, billStage);
		BIND_FROM_TO_I(j, t, isEff);
		BIND_FROM_TO_I(j, t, isClosed);
		BIND_FROM_TO_I(j, t, isVoided);
		BIND_FROM_TO_NORMAL(j, t, effTime);
		BIND_FROM_TO_NORMAL(j, t, approver);
		BIND_FROM_TO_NORMAL(j, t, bpmiInstanceId);
		BIND_FROM_TO_NORMAL(j, t, createTime);
		BIND_FROM_TO_NORMAL(j, t, sysOrgCode);
		BIND_FROM_TO_NORMAL(j, t, createBy);
		BIND_FROM_TO_NORMAL(j, t, updateTime);
		BIND_FROM_TO_NORMAL(j, t, updateBy);
		BIND_FROM_TO_I(j, t, isAuto);
		BIND_FROM_TO_I(j, t, isRubric);
		BIND_FROM_TO_I(j, t, hasRp);
		BIND_FROM_TO_I(j, t, hasSwell);
		BIND_FROM_TO_NORMAL(j, t, srcBillType);
		BIND_FROM_TO_NORMAL(j, t, invoiceType);
		BIND_FROM_TO_OBJ(j, t, entry, std::list<CgthckBillEntryDTO>);
		BIND_FROM_TO_OBJ(j, t, files, std::list<std::string>);
	}
};

#endif // !ADD_CGTHCK_BILL_DTO_
